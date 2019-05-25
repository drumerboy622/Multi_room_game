/************************************************************************************************
Program Name: Find Keys Game
Program Developer: Matthew Solbrack
Date: 08/09/2019
Description: This function is part of the Dining ROom class. This is a subclass of the Space Class. 
In this room the player will look through different items to find a pair of keys. This 
room will not have a susccesful ending. This function is for this class exclusively. 
*************************************************************************************************/
#include "DiningRoom.hpp"

int DiningRoom::itemsToLookThrough()
{
	double choice = 0;

	cout << "\nYou are looking in the Dining Room" << endl;
	cout << "-------------------------------------" << endl;
	cout << "What items would you like to look through (Pick one from below)" << endl;
	cout << "1. The Hutch" << endl;
	cout << "2. Under the Table" << endl;
	cout << "3. Exit this room" << endl;
	cout << "Look through [pick 1 to 3]: ";
	cin >> choice;

	while (!cin || choice < 1 || choice > 3 || remainder(choice, 1) != 0) // using remainder to check decimal http://www.cplusplus.com/reference/cmath/remainder/
	{
		cout << "Try Again:  ";
		cin.clear();
		cin.ignore();
		cin >> choice;
	};
	int choiceReturn = choice;


	if (choice == 1 || choice == 2)
	{
		keysNotHere(); // send a message and add look throughs to the total
		return choice;
	}
	else
		return 0;
}
