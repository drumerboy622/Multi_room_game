/************************************************************************************************
Program Name: Find Keys Game
Program Developer: Matthew Solbrack
Date: 08/09/2019
Description: This function is part of the Bedroom Two class. This is a subclass of the Space Class. 
In this room the player will look through different items to find a pair of keys. This 
room will not have a susccesful ending. The function has a menu specific to this room. 
*************************************************************************************************/
#include "BedroomTwo.hpp"

int BedroomTwo::itemsToLookThrough()
{
	double choice = 0;

	// Menu for Bedroom 2
	cout << "\nYou are looking in the Bedroom 2" << endl;
	cout << "-------------------------------------" << endl;
	cout << "What items would you like to look through (Pick one from below)" << endl;
	cout << "1. Under the bed" << endl;
	cout << "2. In the closet" << endl;
	cout << "3. In the night stand" << endl;
	cout << "4. Around the sheets of the bed" << endl;
	cout << "5. Exit this room" << endl;
	cout << "Look through [pick 1 to 5]: ";
	cin >> choice;

	while (!cin || choice < 1 || choice > 5 || remainder(choice, 1) != 0) // using remainder to check decimal http://www.cplusplus.com/reference/cmath/remainder/
	{
		cout << "Try Again:  ";
		cin.clear();
		cin.ignore();
		cin >> choice;
	};
	int choiceReturn = choice;

	if (choice != 5)
	{
		keysNotHere(); // send message and add look through points
		return choice;
	}
	else
		return 0;
}
