
/**
 * @file GameSession.cpp
 * @brief WoJ GameSession class.
 * @author Kevin Walther
 * @date 2016
 */

#include "GameSession.h"


// Define the constructor and destructor.
GameSession::GameSession()
{
	this->gameRoomHandle = new GameRoom();
}

GameSession::~GameSession()
{
	// These statements become obscelete with smart pointers.
	if (gameRoomHandle != nullptr) {
		delete gameRoomHandle;
	}
}

/** Functional methods. */
void GameSession::initiateGameplay()
{
}
void GameSession::terminateGameplay()
{
}
void GameSession::changeTurns()
{
}
GameRoom * const & GameSession::getGameRoom()
{
	return this->gameRoomHandle;
}

