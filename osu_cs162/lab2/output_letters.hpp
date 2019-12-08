/********************************************************************************************************************************************
** Program name: count_letters.hpp
** Author: Sangyun Lee
** Date: OCT 8: 2019
** Description: This is output_letters function specficiation file. The function recieve ofstream variable as reference, and point to array
** Reference:
********************************************************************************************************************************************/

#ifndef OUTPUT_LETTERS_HPP
#define OUTPUT_LETTERS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>


using std::cout;
using std::cin;
using std::endl;
using std::string;

void output_letters(std::ofstream&, int*);	//proto type


#endif OUTPUT_LETTERS_HPP