
/**
 * @file GameRoom.cpp
 * @brief This file contains the GameRoom class definition.
 * @author Kevin Walther
 * @date 2016
 */

#include "GameRoom.h"


// Define the constructor and destructor.
GameRoom::GameRoom()
{
	// Create the Wheel and GameBoard instances.
	this->wheelHandle = new Wheel();
	this->gameBoardHandle = new GameBoard();
}

GameRoom::~GameRoom()
{
	// These statements become obscelete if we use smart pointers.
	if (wheelHandle != nullptr) {
		delete wheelHandle;
	}
	if (gameBoardHandle != nullptr) {
		delete gameBoardHandle;
	}
}

// Define the GameRoom object methods.


