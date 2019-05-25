/************************************************************************************************
Program Name: Find Keys Game
Program Developer: Matthew Solbrack
Date: 08/09/2019
Description:  This class holds the objects that run this simulation game. Many of the functions 
in this class call the information in the abstract class Space.hpp and its derived classes.  
Most of these classes are private because they are not called outside of this class. For more
specific infomration on this class visit GamePlay.cpp file. 
*************************************************************************************************/
#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

//Included these files because this class creates objects to them. 
#include "Space.hpp"
#include "FamilyRoom.hpp"
#include "BedroomOne.hpp"
#include "BedroomTwo.hpp"
#include "Den.hpp"
#include "DiningRoom.hpp"
#include "Kitchen.hpp"

class GamePlay
{
private:
	Space * familyRoom;
	Space * diningRoom;
	Space * den;
	Space * bedroomOne;
	Space * bedroomTwo;
	Space * kitchen;
	Space * play;
	int getTurnsFromSpace();
	int getContainerSizeFromSpace();
	bool checkToSeeIfGameIsOver();
	void createHouse();
	void YouWon();
	void YouLost();
public:
	GamePlay();
	~GamePlay();
	void gamePlay();
};

#endif // !GAMEPLAY_HPP
