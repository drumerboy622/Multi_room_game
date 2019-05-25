/************************************************************************************************
Program Name: Find Keys Game
Program Developer: Matthew Solbrack
Date: 08/09/2019
Description: This function is part of the BedroomOne class. This is a subclass of the Space Class. 
In this room the player will look through different items to find a pair of keys. This 
room might have a succesful ending.  
*************************************************************************************************/
#include "BedroomOne.hpp"

int BedroomOne::itemsToLookThrough()
{
	double choice = 0;
	// Menu for Bedroom One
	cout << "\nYou are looking in the Bedroom 1" << endl;
	cout << "-------------------------------------" << endl;
	cout << "What items would you like to look through (Pick one from below)" << endl;
	cout << "1. In the sheets" << endl;
	cout << "2. On the floor" << endl;
	cout << "3. Under the bed" << endl;
	cout << "4. In the closet" << endl;
	cout << "5. Exit this room" << endl;
	cout << "Look through [pick 1 to 5]: ";
	cin >> choice;

	//input validation
	while (!cin || choice < 1 || choice > 5 || remainder(choice, 1) != 0) // using remainder to check decimal http://www.cplusplus.com/reference/cmath/remainder/
	{
		cout << "Try Again:  ";
		cin.clear();
		cin.ignore();
		cin >> choice;
	};
	int choiceReturn = choice;

	if (choice == 3)
	{	// Dust Bunny obstacle
		if (looks < 999)
		{
			char continueQuestion;
			cout << "\nOnce you got down on your hands and knees you find nothing but dust bunnies!\n";
			cout << "To be able to look under the bed you must vacuum first and it will cost you 4 look throughs." << endl;
			cout << "Would you like to continue? [Y or N]: ";
			cin >> continueQuestion;

			//input validation
			while (continueQuestion != 'Y' && continueQuestion != 'N' && continueQuestion != 'n' && continueQuestion != 'y')
			{
				cout << "Try Again: ";
				cin.clear();
				cin.ignore();
				cin >> continueQuestion;
			}

			if (continueQuestion == 'y' || continueQuestion == 'Y')
				vacuum();

			return choice;
		}
		else
		{
			keysNotHere(); // send note to user and add look through points
			return choice;
		}
	}
	else if (choice != 5 && choice != 3)
	{
		keysNotHere();// send note to user and add look through points
		return choice;
	}
	else
		return 0;
}

/************************************************************************************************
Description: This function uses a sleep function to add suspense to the game. This is where
the bottle opener key chain will be found. You are required to use extra look throughs
to get to these keys
************************************************************************************************/
void BedroomOne::vacuum()
{
	looks = 1000; // this variable is to tell the class that the keys have already been found
	setNumberOfTurns(4);
	cout << "\nGetting the Vacuum... Plug it in.... Vacuum up the dust bunnies..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(5)); // Reference: https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
	cout << "Now that you are finished, you can start looking for the keys!" << endl;
	cout << "\nLooking.... Looking.... Looking...." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(5)); // Reference: https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
	cout << "\nYou have found the Bottle Opener Key Chain under the bed!!! Good Job!" << endl;
	addToContainer("Bottle Opener Key Chain"); // add keys to the container
}
	
