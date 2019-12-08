/********************************************************************************************************************************************
** Program name: display.hpp
** Author: Sangyun Lee
** Date: OCT 8: 2019
** Description: This is display function specficiation file. The function recieve ifstream variable as reference.
** Reference:
********************************************************************************************************************************************/

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "output_letters.hpp"		//Instead of including all the library, I include other func that already has the necessary library

void TxtDisplay(std::ifstream& file);

#endif 

