
/************************************************************************************************
Program Name: Find Keys Game
Program Developer: Matthew Solbrack
Date: 08/09/2019
Description: This class holds the objects that run this simulation game. Many of the functions 
in this class call the information in the abstract class Space.hpp and its derived classes. The 
object of the game is to find keys. The derived classes is where you will find the specific 
room objects to look through. The point of this gmae is to find three sets of keys before 
the time runs out (which is 15 look through points).
*************************************************************************************************/
#include "GamePlay.hpp"

/************************************************************************************************
Description: constructor initializes the objects to the derived classes and displays the opening
information through a txt file. 
************************************************************************************************/
GamePlay::GamePlay()
{
	createHouse();
	play = familyRoom;
	play->displayEnterance();
}

/************************************************************************************************
Description: Destructor deletes all the objects this class created. 
************************************************************************************************/
GamePlay::~GamePlay()
{
	cout << endl;
	delete familyRoom;
	delete diningRoom;
	delete den;
	delete bedroomOne;
	delete bedroomTwo;
	delete kitchen;
}

/************************************************************************************************
Description: Create the objects to the derived classes. They are linked together.  A name is 
added to each object so that it can be called and the user will know where they are. 
************************************************************************************************/
void GamePlay::createHouse()
{
	//Creating the objects
	familyRoom = new FamilyRoom();
	den = new Den();
	diningRoom = new DiningRoom();
	bedroomOne = new BedroomOne();
	bedroomTwo = new BedroomTwo();
	kitchen = new Kitchen();

	//point to the adjacent rooms from the familyroom
	familyRoom->setLeft(den);
	familyRoom->setTop(diningRoom);
	familyRoom->setRight(bedroomTwo);
	familyRoom->setBottom(familyRoom);
	familyRoom->setName("Family Room");

	//point to the adjacent rooms from the den
	den->setLeft(den);
	den->setTop(bedroomOne);
	den->setRight(familyRoom);
	den->setBottom(den);
	den->setName("Den");

	//point to the adjacent rooms from bedroom 1
	bedroomOne->setLeft(bedroomOne);
	bedroomOne->setTop(bedroomOne);
	bedroomOne->setRight(diningRoom);
	bedroomOne->setBottom(den);
	bedroomOne->setName("Bedroom One");

	//point to the adjacent rooms from dining room
	diningRoom->setLeft(bedroomOne);
	diningRoom->setTop(diningRoom);
	diningRoom->setRight(kitchen);
	diningRoom->setBottom(familyRoom);
	diningRoom->setName("Dining Room");


	//point to the adjacent rooms from kitchen
	kitchen->setLeft(diningRoom);
	kitchen->setTop(kitchen);
	kitchen->setRight(kitchen);
	kitchen->setBottom(bedroomTwo);
	kitchen->setName("Kitchen");

	//point to the adjacent rooms from bedroom Two
	bedroomTwo->setLeft(familyRoom);
	bedroomTwo->setTop(kitchen);
	bedroomTwo->setRight(bedroomTwo);
	bedroomTwo->setBottom(bedroomTwo);
	bedroomTwo->setName("Bedroom Two");
}

/************************************************************************************************
Description: Add all the objects together to find out how many look through points have been added
************************************************************************************************/
int GamePlay::getTurnsFromSpace()
{
	return familyRoom->getTurns() + den->getTurns() + bedroomOne->getTurns() + bedroomTwo->getTurns() + 
		kitchen->getTurns() + diningRoom->getTurns();
}

/************************************************************************************************
Description: Add all the containers from the different objects to see how many keys have been found
************************************************************************************************/
int GamePlay::getContainerSizeFromSpace()
{
	return familyRoom->getContainerSize() + den->getContainerSize() + bedroomOne->getContainerSize() + 
		bedroomTwo->getContainerSize() + kitchen->getContainerSize() + diningRoom->getContainerSize();
}

/************************************************************************************************
Description: 
************************************************************************************************/
bool GamePlay::checkToSeeIfGameIsOver()
{
	if (getContainerSizeFromSpace() >= 3 || getTurnsFromSpace() < -15)
		return true;
	else
		return false;
}

/************************************************************************************************
Description:  This is the main gamePlay function. This will control and run the simulation. 
This function will provide the movement between rooms and call the gmae play functions 
in the Space class. 
************************************************************************************************/
void GamePlay::gamePlay()
{
	int turn = 1;
	while (checkToSeeIfGameIsOver() == false && turn == 1)
	{
		//Diplay what room you are currently in
		cout << "\nYou are currently in the: " << play->getName() << endl;
		cout << "You have looked through " << abs(getTurnsFromSpace()) << " places and have found " << getContainerSizeFromSpace() << " set(s) of keys." << endl;
		if (play->lookInRoom() == true)
		{
			int inRoom = 1;
			while (inRoom != 0 && checkToSeeIfGameIsOver() == false)
			{
				inRoom = play->itemsToLookThrough();
			}
		}

		//Loop the menu until the correct action is taken
		int move = 1;
		while (checkToSeeIfGameIsOver() == false && move == 1)
		{	//Display Map so that the user knows where to go next
			play->houseMap();
			cout << "                 You are currently in the " << play->getName() << endl;
			cout << "      You have looked through " << abs(getTurnsFromSpace()) << " places and have found " << getContainerSizeFromSpace() << " set(s) of keys." << endl << endl;
			//Display the Move Menu
			int moveRooms = play->moveMenu();

			// Check each move against the map to see if it is there
			if (moveRooms == 1 && play->getTop() != play)
			{
				play = play->getTop();
				move = 0;
			}
			else if (moveRooms == 2 && play->getBottom() != play)
			{
				play = play->getBottom();
				move = 0;
			}
			else if (moveRooms == 3 && play->getLeft() != play)
			{
				play = play->getLeft();
				move = 0;
			}
			else if (moveRooms == 4 && play->getRight() != play)
			{
				play = play->getRight();
				move = 0;
			}
			else if (moveRooms == 5)
			{
				move = 0;
				turn = 86;
			}
			else
			{
				cout << "\nYou hit a Wall! Try again!" << endl;
				move = 0;
			}
		}

	}
	//See if the gmae has been won or lost
	if (getContainerSizeFromSpace() >= 3)
		YouWon();
	else if (getTurnsFromSpace() <= -15)
		YouLost();
}
	
/************************************************************************************************
Description: If the user Wins the simulation a file will be opened and displayed on the screen.
Also, the key names will be displayed. They will be from a STL container.
************************************************************************************************/
void GamePlay::YouWon()
{
	cout << "\nYou have Found the following keys: ";
	cout << familyRoom->getItemFromContainer() << ", " << kitchen->getItemFromContainer() << ", " << bedroomOne->getItemFromContainer();
	familyRoom->popContainer();
	kitchen->popContainer();
	bedroomOne->popContainer();
	cout << endl << endl;

	ifstream MyFile("YouWin.txt");
	char ch;

	while (!MyFile.eof())
	{
		MyFile.get(ch);
		cout << ch;
	}

	MyFile.close();
}

/************************************************************************************************
Description: If the user has lost this function will be called to print a message. 
************************************************************************************************/
void GamePlay::YouLost()
{
	cout << "\nLooks Like you ran out of time and Lost the Game! Better luck next time..." << endl;
}
	

/************************************************************************************************
Description: This is the main function. It will run a loop until the user would like to exit. 
************************************************************************************************/
int main()
{
	char choice;
	bool play = true;
	while (play == true)
	{
		GamePlay startGame;
		startGame.gamePlay();

		cout << "\nWould you like to play again? [Y or N]: ";
		cin >> choice;

		while (choice != 'Y' && choice != 'N' && choice != 'n' && choice != 'y')
		{
			cout << "Try Again: ";
			cin.clear();
			cin.ignore();
			cin >> choice;
		}

		if (choice == 'n' || choice == 'N')
			play = false;
	}


	return 0;
}
