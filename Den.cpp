/************************************************************************************************
Program Name: Find Keys Game
Program Developer: Matthew Solbrack
Date: 08/09/2019
Description: This function is part of the Den class. This is a subclass of the Space Class. 
In this room the player will look through different items to find a pair of keys. This 
room will not have a susccesful ending.  This function has an obsticle if the user so 
chooses. The menu in this function is specfic to this class. There is a function to add
a pause inside this function. It was an attempt to add suspence. 
*************************************************************************************************/
#include "Den.hpp"

int Den::itemsToLookThrough()
{
	double choice = 0;

	cout << "\nYou are looking in the Den" << endl;
	cout << "-------------------------------------" << endl;
	cout << "What items would you like to look through (Pick one from below)" << endl;
	cout << "1. Under the computer desk" << endl;
	cout << "2. In the desk drawers" << endl;
	cout << "3. In the closet" << endl;
	cout << "4. Exit this room" << endl;
	cout << "Look through [pick 1 to 4]: ";
	cin >> choice;

	while (!cin || choice < 1 || choice > 4 || remainder(choice, 1) != 0) // using remainder to check decimal http://www.cplusplus.com/reference/cmath/remainder/
	{
		cout << "Try Again:  ";
		cin.clear();
		cin.ignore();
		cin >> choice;
	};
	int choiceReturn = choice;

	if (choice == 2)
	{	// It takes a while to look through drawers. Add more look throughs to get through this one. 
		char continueQuestion;
		cout << "\nThere are three different drawers to look through. It will cost you three look throughs to complete this task!\n"
			<< "Would you like to continue? [Y or N]: ";
		cin >> continueQuestion;

		while (continueQuestion != 'Y' && continueQuestion != 'N' && continueQuestion != 'n' && continueQuestion != 'y')
		{
			cout << "Try Again: ";
			cin.clear();
			cin.ignore();
			cin >> continueQuestion;
		}

		if (continueQuestion == 'y' || continueQuestion == 'Y')
		{
			setNumberOfTurns(2);
			cout << "\nLooking.... Looking.... Looking...." << endl;
			std::this_thread::sleep_for(std::chrono::seconds(2)); // Reference: https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
			keysNotHere(); // send message and add look throughs
		}
		return choice;
	}
	else if (choice == 1 || choice == 3)
	{
		keysNotHere(); // send message and add look throughs 
		return choice;
	}
	else
		return 0;
}
