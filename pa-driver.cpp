#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <vector>
#include "pa.hpp"

int main(int argc, char* argv[]) {
//================================================================================================================================================================================================================================================================
//|                                                                    INPUT FILE CHECKING                                                                                                                                                         |
//================================================================================================================================================================================================================================================================
    if (argc != 4) { std::cerr << "Usage: " << argv[0] << " <input_file> <expected_output_file> <actual_output_file>" << std::endl; std::exit(EXIT_FAILURE); }
    std::ifstream input_file(argv[1]);
    std::ifstream expected_output_file(argv[2]);
    std::ofstream actual_output_file(argv[3]);

    // checking if the input_file, expected_output_file or actual_output_file cannot ne opened
    if (!input_file || !expected_output_file || !actual_output_file) { std::cerr << "Error: Unable to open files." << std::endl; std::exit(EXIT_FAILURE); }
//================================================================================================================================================================================================================================================================
//|                                                          READ INPUTS AND PRODUCE ACTUAL DATA SECTION                                                                                                                                                                |
//================================================================================================================================================================================================================================================================
    std::string actual_output;
    
    // read and show parameters from input file
    std::cout<<std::setfill(' ')<<std::setw(25)<<" ↓"<<"\n"<<"\t      ./pa.out ";
    std::vector<std::string> cmdline_params;
    std::string param;
    while (input_file >> param) { std::cout<<param<<" ";cmdline_params.push_back(param); }
    input_file.close();
    std::cout<<std::endl;

    if (cmdline_params.size() != 5) {
        actual_output_file << "Usage: ./program-name rows cols start cycle width" << std::endl;
        actual_output_file.close();
        std::exit(EXIT_FAILURE);
    }

    hlp2::mystery_type board = hlp2::create_board(cmdline_params);                                                                      // creating the board    
    // Redirect the printed output to a stringstream
    std::ostringstream actual_output_stream;
    std::streambuf* cout_buffer = std::cout.rdbuf();                                                                                    // Save cout's buffer
    std::cout.rdbuf(actual_output_stream.rdbuf());                                                                                      // Redirect cout to the stringstream
    hlp2::print_board(board, cmdline_params[4]);                                                                                        // Print the board
    std::cout.rdbuf(cout_buffer);                                                                                                       // Restore cout's buffer
    actual_output = actual_output_stream.str();                                                                                         // Get the content of the stringstream and store it in actual_output
    actual_output_file << actual_output;                                                                                                // Write actual output to file                                                                                                    // close the file
    
//================================================================================================================================================================================================================================================================
//|                                                                  READ SHOW EXPCTED AND ACTUAL DATA                                                                                                                                                                |
//================================================================================================================================================================================================================================================================
    // read show expected output from file
    std::cout<<"\nExpected data:\n"<<std::setfill('-')<<std::setw(50)<<"-"<<std::endl;
    std::ostringstream expected_output_stream;
    expected_output_stream << expected_output_file.rdbuf();
    std::string expected_output = expected_output_stream.str();
    std::cout<<expected_output<<"\n";
    
    // Print board
    std::cout<<"Actual output:\n"<<std::setfill('-')<<std::setw(50)<<"-"<<std::endl;
    hlp2::print_board(board, cmdline_params[4]);
    std::cout<<std::endl;

    // Close the files
    input_file.close();
    expected_output_file.close();
    actual_output_file.close();

    // Compare actual and expected outputs
    if (expected_output == actual_output) { std::cout << "Test passed: Output matches expected." << std::endl; }
    else { std::cout << "Test failed: Output does not match expected." << std::endl; }
    std::cout<<std::setfill('#')<<std::setw(150)<<"#"<<std::endl;
    
    return 0;
}
