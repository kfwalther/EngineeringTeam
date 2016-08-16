
/**
 * @file GameRoom.cpp
 * @brief This file contains the GameRoom class definition.
 * @author Kevin Walther
 * @date 2016
 */

#include <algorithm>

#include "GameRoom.h"

// Define the constructor and destructor.
GameRoom::GameRoom(std::string const & inputFileName)
{
	// Create the Wheel instance.
	this->wheelHandle = new Wheel(inputFileName);
	// Initialize a vector to hold the QCategory objects.
	GameBoard::QCategoryVectorType qCategoryVector;
	// Copy only the QCategory objects from the Wheel into the vector.
	auto it = std::for_each(this->wheelHandle->getSectors().begin(), this->wheelHandle->getSectors().end(),
			[&qCategoryVector](Sector * const & currentSector) {
				if (currentSector->getType() == 1) {
					qCategoryVector.push_back(dynamic_cast<QCategory *>(currentSector));
				}
			});
	// Create the GameBoard instance, providing it the vector of QCategory objects.
	this->gameBoardHandle = new GameBoard(qCategoryVector);
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
Wheel * const & GameRoom::getWheel()
{
	return this->wheelHandle;
}
