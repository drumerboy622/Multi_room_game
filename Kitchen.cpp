/************************************************************************************************
Program Name: Find Keys Game
Program Developer: Matthew Solbrack
Date: 08/09/2019
Description: This function is part of the Kitchen class. This is a subclass of the Space Class. 
In this room the player will look through different items to find a pair of keys. This 
room might have a susccesful ending. 
*************************************************************************************************/
#include "Kitchen.hpp"

/************************************************************************************************
Description: This function is a menu specific to this class. some of the options send the user
information that they haven't found the keys and one option gives the user an opportunity to 
find one set of keys. 
************************************************************************************************/
int Kitchen::itemsToLookThrough()
{
	double choice = 0;

	cout << "\nYou are looking in the Kitchen" << endl;
	cout << "-------------------------------------" << endl;
	cout << "What items would you like to look through (Pick one from below)" << endl;
	cout << "1. In the fridge" << endl;
	cout << "2. Through the cupboards" << endl;
	cout << "3. In the drawers" << endl;
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

	//this area will allow the user to find a set of keys once. 
	if (choice == 2)
	{
		if (looks < 999)
		{
			OSUKeyChain();
			return choice;
		}
		else
		{
			keysNotHere();
			return choice;
		}
	}
	else if (choice == 1 || choice == 3)
	{
		keysNotHere();
		return choice;
	}
	else
		return 0;
}

/************************************************************************************************
Description: This function is for when the user looks through the cupboards. It uses a timed pause
to give the game more suspense. You will find the OSU keychain. 
************************************************************************************************/

void Kitchen::OSUKeyChain()
{
	char continueQuestion;
	looks = 1000;
	// add a point to the amount of turns
	setNumberOfTurns(1);
	cout << "\nLooking.... Looking.... Looking...." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(4)); // Reference: https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
	cout << "You think there might be something behind the glasses. " << endl;
	cout << "To move the glasses you will lose a look through. Time is running out!" << endl;
	cout << "Would you like to continue? [Y or N]: ";
	cin >> continueQuestion;

	while (continueQuestion != 'Y' && continueQuestion != 'N' && continueQuestion != 'n' && continueQuestion != 'y')
	{
		cout << "Try Again: ";
		cin.clear();
		cin.ignore();
		cin >> continueQuestion;
	}

	if (continueQuestion == 'y' || continueQuestion == 'Y')
	{	//add more points to the turn
		setNumberOfTurns(1);
		cout << "\nYou have found the OSU Key Chain!!! Good Job!" << endl;

		//put the keychain in the contianer
		addToContainer("OSU Key Chain");
	}


}
