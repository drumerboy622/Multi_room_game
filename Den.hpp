/************************************************************************************************
Program Name: Find Keys Game
Program Developer: Matthew Solbrack
Date: 08/09/2019
Description: This header is for Den.cpp. This holds the data members and member functions.
Visit BedroomOne.cpp to find more information on the class.
*************************************************************************************************/
#ifndef DEN_HPP
#define DEN_HPP

#include "Space.hpp"

class Den : public Space
{
public:
	int itemsToLookThrough();
};

#endif // !DEN_HPP
