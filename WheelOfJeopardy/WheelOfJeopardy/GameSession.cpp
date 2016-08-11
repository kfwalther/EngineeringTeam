
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
	this->players = new GameSession::PlayerListType;
	this->round=1;
	this->sessionID=GameSession::uniqueID;
	GameSession::uniqueID++;

}

GameSession::~GameSession()
{
	// These statements become obscelete with smart pointers.
	if (gameRoomHandle != nullptr) {
		delete gameRoomHandle;
	}
}

int GameSession::uniqueID=0;

/** Functional methods. */
void GameSession::initiateGameplay()
{
}
void GameSession::terminateGameplay()
{
}
void GameSession::changeTurns()
{
	this->players->reverse();
}
void GameSession::join(Player *player)
{
	this->players->push_back(player);
}
GameRoom * const & GameSession::getGameRoom()
{
	return this->gameRoomHandle;
}

GameSession::PlayerListType & GameSession::getPlayers()
{
	return *(this->players);
}

