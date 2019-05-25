/************************************************************************************************
Program Name: Find Keys Game
Program Developer: Matthew Solbrack
Date: 08/09/2019
Description: This function is part of the FamilyRoom class. This is a subclass of the Space Class. 
In this room the player will look through different items to find a pair of keys. This 
room might have a succesful ending. 
*************************************************************************************************/
#include "FamilyRoom.hpp"

int FamilyRoom::itemsToLookThrough()
{
	double choice = 0;

	cout << "\nYou are looking in the Family Room" << endl;
	cout << "-------------------------------------" << endl;
	cout << "What items would you like to look through (Pick one from below)" << endl;
	cout << "1. In and under the couch" << endl;
	cout << "2. In the book shelf" << endl;
	cout << "3. Under the coffee table" << endl;
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

	// This loop will ask the user if they would like to use more look throughs
	if (choice == 1)
	{	
		if (looks < 999) // This was added to only allow the keys to be found once
		{
			char continueQuestion;
			cout << "\nThis couch is really big! It is going to take two look throughs to look through everything!\n"
				<< "Would you like to continue? [Y or N]: ";
			cin >> continueQuestion;

			while (continueQuestion != 'Y' && continueQuestion != 'N' && continueQuestion != 'n' && continueQuestion != 'y')
			{
				cout << "Try Again: ";
				cin.clear();
				cin.ignore();
				cin >> continueQuestion;
			}

			// 
			if (continueQuestion == 'y' || continueQuestion == 'Y')
			{
				goofyKeyChain();
			}
			return choice;
		}
		else
		{
			keysNotHere();
			return choice;
		}
	}
	// These places will have no keys
	else if (choice == 2 || choice == 3)
	{
		keysNotHere();
		return choice;
	}
	else
		return 0;
}

/************************************************************************************************
Description: This function uses a sleep function to add suspense to the game. This is where
the goofy key chain will be found. You are required to use extra look throughs
to get to these keys. 
************************************************************************************************/

void FamilyRoom::goofyKeyChain()
{
	looks = 1000; // change looks so that the loop knows that the keys have already been found here\
	
	// add the points to the look throughs
	setNumberOfTurns(2);
	cout << "\nLooking.... Looking.... Looking...." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(3)); // Reference: https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
	cout << "\nYou have found the Goofy Key Chain!!! Good Job!" << endl;

	// add the keys to the container
	addToContainer("Goofy KeyChain");
}
