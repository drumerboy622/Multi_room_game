
/************************************************************************************************
Program Name: Find Keys Game
Program Developer: Matthew Solbrack
Date: 08/09/2019
Description: This is an abstract class that controls most of the functionality of this game. 
There are a bunch of setters and getters to help move around the house. The objects are 
made in the GamePlay.cpp file. The menu's were put in this file for easy handling in the 
GamePlay file. The objects can grab the files as they are already referencing one fo the 
subclasses of this abstract clasds.
*************************************************************************************************/
#include "Space.hpp"

/************************************************************************************************
Description: SETTERS - sets all the names, direction and number of turns
************************************************************************************************/
void Space::setNumberOfTurns(int number) { turn = turn - number; }
void Space::setName(string room_name) { name = room_name; }
void Space::setTop(Space *setit) { top = setit; }
void Space::setBottom(Space *setit) { bottom = setit; }
void Space::setRight(Space *setit) { right = setit; }
void Space::setLeft(Space *setit) { left = setit; }

/************************************************************************************************
Description: GETTERS - allows to get all the names, direction and number of turns
************************************************************************************************/
void Space::addToContainer(string add) { container.push(add); }
Space *Space::getTop() { return top; }
Space *Space::getBottom() { return bottom; }
Space *Space::getRight() { return right; }
Space *Space::getLeft() { return left; }
string Space::getName() { return name; }
int Space::getContainerSize() { return container.size(); }
int Space::getTurns() { return turn; }
string Space::getItemFromContainer()
{
	if (container.empty())
		return " ";
	else
		return container.top();
}

/************************************************************************************************
Description: Pop the container of keys as long as it isn't empty
************************************************************************************************/
void Space::popContainer()
{
	if (!container.empty())
		container.pop();
}

/************************************************************************************************
Description: This function asks the user if they would like to look through the room and returns
the users decision.
************************************************************************************************/
bool Space::lookInRoom()
{
	char choice;
	cout << "\nWould you like to look in this room? [Y or N]: ";
	cin >> choice;

	while (choice != 'Y' && choice != 'N' && choice != 'n' && choice != 'y')
	{
		cout << "Try Again: ";
		cin.clear();
		cin.ignore();
		cin >> choice;
	}

	if (choice == 'y' || choice == 'Y')
		return true;
	else
		return false;
}

/************************************************************************************************
Description: This function calls a txt file and displays the contents. This is for the 
introduction to the game. 
************************************************************************************************/
void Space::displayEnterance()
{
	ifstream MyFile("IntroDisplay.txt"); //Open file
	char into;

	while (!MyFile.eof())
	{
		MyFile.get(into);
		cout << into;
	}

	MyFile.close(); //Close file
}

/************************************************************************************************
Description: This function holds the map to the house. Displays when called. 
************************************************************************************************/
void Space::houseMap()
{

	cout << "\n         _____MAP___________________________________________" << endl;
	cout << "        |              |               |                   |" << endl;
	cout << "        |  Bedroom 1   |  Dining Room  |                   |" << endl;
	cout << "        |                                                  |" << endl;
	cout << "        |              |               |    Kitchen        |" << endl;
	cout << "        |_____   ______|______     ____|                   |" << endl;
	cout << "        |          |                   |____________   ____|" << endl;
	cout << "        |  Den     |    Family Room    |                   |" << endl;
	cout << "        |                              |                   |" << endl;
	cout << "        |          |                       Bedroom 2       |" << endl;
	cout << "        |__________|____________|\\_____|___________________|" << endl;
	cout << "                   Front Door" << endl << endl;
}

/************************************************************************************************
Description: This functions is a menu for the User to decide if they would like to move rooms.
the decision is then sent back to the GamePlay file.
************************************************************************************************/
int Space::moveMenu()
{
	double choice;
	cout << "Move Options" << endl;
	cout << "------------" << endl;
	cout << "1. Move Up" << endl;
	cout << "2. Move Down" << endl;
	cout << "3. Move Left" << endl;
	cout << "4. Move Right" << endl;
	cout << "5. Exit Game" << endl;
	cout << "Please choose from one of the options above [1 to 5]: ";
	cin >> choice;

	while (!cin || choice < 1 || choice > 5 || remainder(choice, 1) != 0) // using remainder to check decimal http://www.cplusplus.com/reference/cmath/remainder/
	{
		cout << "Try Again:  ";
		cin.clear();
		cin.ignore();
		cin >> choice;
	};
	int choiceReturn = choice;
	return choiceReturn;
}

/************************************************************************************************
Description: This functions is used by all the subclasses. It tells the User the keys were not 
found. And, it adds to the number of turns.  
************************************************************************************************/
void Space::keysNotHere()
{
	cout << "\nThe Keys are not here. Try another location." << endl;
	setNumberOfTurns(1);
}
