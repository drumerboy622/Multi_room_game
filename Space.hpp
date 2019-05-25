/************************************************************************************************
Program Name: Find Keys Game
Program Developer: Matthew Solbrack
Date: 08/09/2019
Description:  This is the main header for the abstract Space class. This class folds most of the 
functionality of the simulation. All of the abstract classes has access to this class which is
why the decision to hold much of the games functionality here. Many of the functions are 
getters to get the information about the subclasses . For more information about this class
visit the Space.cpp file. 
*************************************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <stack> // STL container
#include <chrono> // used for the temporary sleep to add suspence
#include <thread> // used for the temporary sleep to add suspence
#include <cmath>

using std::string;
using std::stack;
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;


class Space
{
private:
	int turn;
	string name;
	Space * left;
	Space * right;
	Space * top;
	Space * bottom;
	stack<string> container;
protected:
	void addToContainer(string);
	void setNumberOfTurns(int);


public:
	Space() {};
	void setName(string);
	void setTop(Space *);
	void setBottom(Space *);
	void setRight(Space *);
	void setLeft(Space *);
	Space *getTop();
	Space *getBottom();
	Space *getRight();
	Space *getLeft();
	string getName();
	void popContainer();
	string getItemFromContainer();
	int getContainerSize();
	int getTurns();
	bool lookInRoom();
	void displayEnterance();
	void houseMap();
	int moveMenu();
	void keysNotHere();

	virtual int itemsToLookThrough() = 0; //Pure virtual function
};
#endif
