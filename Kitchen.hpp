/************************************************************************************************
Program Name: Find Keys Game
Program Developer: Matthew Solbrack
Date: 08/09/2019
Description: This header is for Kitchen.cpp. This holds the data members and member functions.
Visit Kitchen.cpp to find more information on the class
*************************************************************************************************/
#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "Space.hpp"

class Kitchen : public Space
{
private:
	int looks; // this variable has the power to tell the function if the keys have already been found
	void OSUKeyChain(); //OSU keychain
public:
	int itemsToLookThrough();
};
#endif // !KITCHEN_HPP
