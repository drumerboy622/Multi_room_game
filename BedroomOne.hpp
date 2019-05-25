/************************************************************************************************
Program Name: Find Keys Game
Program Developer: Matthew Solbrack
Date: 08/09/2019
Description:  This header is for BedroomOne.cpp. This holds the data members and member functions.
Visit BedroomOne.cpp to find more information on the class.
*************************************************************************************************/
#ifndef BEDROOMONE_HPP
#define BEDROOMONE_HPP

#include "Space.hpp"

class BedroomOne : public Space
{
private:
	int looks; // this variable has the power to tell the function if the keys have already been found
	void vacuum();
public:
	int itemsToLookThrough();
};



#endif