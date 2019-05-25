/************************************************************************************************
Program Name: Find Keys Game
Program Developer: Matthew Solbrack
Date: 08/09/2019
Description: This header is for DiningRoom.cpp. This holds the data members and member functions.
Visit DiningRoom.cpp to find more information on the class.
*************************************************************************************************/
#ifndef DININGROOM_HPP
#define DININGROOM_HPP

#include "Space.hpp"

class DiningRoom : public Space
{
public:
	int itemsToLookThrough();
};
#endif // !DININGROOM_HPP
