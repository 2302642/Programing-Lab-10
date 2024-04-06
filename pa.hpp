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
#ifndef PA_HPP
#define PA_HPP

#include <iostream> // istream, ostream
#include <string>
#include <vector>

namespace hlp2 {

using mystery_type = std::vector<std::string>;

mystery_type create_board(std::vector<std::string> const& cmdline_params);              // to create a array of elements in a certain pattern
void print_board(mystery_type const& board, std::string const& width);                  // to create a array of elements in a certain pattern

} // end namespace hlp2

#endif // end PA_HPP
