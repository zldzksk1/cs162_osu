/********************************************************************************************************************************************
** Program name: count_letters.hpp
** Author: Sangyun Lee
** Date: OCT 8: 2019
** Description:	This is count_letters function specficiation file. The function recieve ifstream variable as reference, and point to array
** Reference:
********************************************************************************************************************************************/

#ifndef COUNT_LETTERS_HPP
#define COUNT_LETTERS_HPP

#include "output_letters.hpp"							// since thie function will utilize the output_letters function



void count_letters(std::ifstream& file, int* arr);		//proto type


#endif COUNT_LETTERS_HPP