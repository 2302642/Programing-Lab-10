/*********************************************************************************************************************************************************************************************************************************************************************
|@file       the name of source file is point.hpp                           |
|@author     Najih & DP login: n.hajasheikallaudin                          |
|@course     This source file meant for RSE1202 course                      |    
|@section    which section of this course are you enrolled in RSE           |
|@tutorial   Lab 6                                                          |
|@date       file created on 19/02/2024                                     |
|@brief      provide a brief explanation about what this source file does:  |
|----------------------------------------------------------------------------          
|
|This file is contains 2 function definition to called by main in pa-driver.
|   function:
|			mystery_type create_board(std::vector<std::string> const& cmdline_params);  // to create a array of elements in a certain pattern
|           void print_board(mystery_type const& board, std::string const& width);      // to create a array of elements in a certain pattern	
*********************************************************************************************************************************************************************************************************************************************************************/
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include "pa.hpp"

namespace hlp2 {
    mystery_type create_board(std::vector<std::string> const& cmdline_params){          // to create a array of elements in a certain pattern
        mystery_type empty_board;                                                       // setting up a empty board for error return
        if (cmdline_params.size() != 5) {                                               // checking the size of inputs to ensure that 5 values are entered
            std::cerr << "Usage: ./program-name rows cols start cycle width\n";
            return empty_board;
        }

        int rows = std::stoi(cmdline_params[0]);                                        // extracting + converting element stored at that location to type int for rows
        int cols = std::stoi(cmdline_params[1]);                                        // extracting + converting element stored at that location to type int for columns
        char start_char = cmdline_params[2][0];                                         // extracting + converting element stored at that location to type char for start_char
        int cycle = std::stoi(cmdline_params[3]);                                       // extracting + converting element stored at that location to type int for cycle_size
        int width = std::stoi(cmdline_params[4]);                                       // extracting + converting element stored at that location to type int for width
        if (rows<=0||cols<=0||cycle< 0||width<=0){ return empty_board; }                // Validate parameters if necessary
            
        mystery_type board(rows, std::string(cols, ' '));                               // Creating the board grid initialize with spaces
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                char ch = start_char + (i+j)%cycle;                                     // calculating the character based on the starting character and cycle size
                if(!(ch >= 32 && ch<= 126)) { return empty_board; }
                board[i][j] = ch;                                                       // setting the character in the board grid
            }
        }
        return board;
    }

    void print_board(const mystery_type& board, const std::string& width) {             // to create a array of elements in a certain pattern   
        if(isdigit(width[0])){                                                          // checking if with is valid as a digit
            int cell_width = std::stoi(width);                                          // extracting + converting element stored at that location to type int for width
            for(const std::string& row : board) {                                       // iterating through each row of the board
                for(int i = 0; i < cell_width; ++i) {
                    for(const auto& cell : row) {                                       // iterating through each cell in the row     
                        for(int j = 0; j < cell_width; ++j){ std::cout<<cell; }         // printing a cell for that location
                    }std::cout << std::endl;                                            // moving to the next row
                }
            }
        }
    }
}
