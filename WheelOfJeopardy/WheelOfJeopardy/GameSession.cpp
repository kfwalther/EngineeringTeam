
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
	this->rounds=2; //number of rounds
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
bool GameSession::initiateGameplay()
{
	for (int i = 0; i < this->rounds; i++) {
		/*while (this->gameRoomHandle->getWheel()->isSpinnable()) {
			std::cout << "Current Player: " << players->front()->getName() << "\tCurrent Score: "<< players->front()->getScore() << "\tFree Tokens: "<< players->front()->hasFreeTurnToken()<< std::endl;//testcode
			std::cout << "Opposing Player: " << players->back()->getName() << "\tOpposing Score: " << players->back()->getScore() << "\tFree Tokens: " << players->back()->hasFreeTurnToken() << std::endl;//testcode
			std::string x; std::cout << "Press any key to spin\n"; 	std::getline(std::cin, x); //testcode
			this->getGameRoom()->getWheel()->Spin()->Action(this);
		}*/
		//delete the old GameRoom, and create a new one for round 2.
		this->gameRoomHandle = new GameRoom();	
	}

	return true;
}
void GameSession::terminateGameplay()
{
	//call destructors? possibly not needed if loop is inside initiateGameplay()
}

void GameSession::changeTurns()
{
	this->players->reverse();
}

void GameSession::join(Player *player)
{
	// Add the current player to the GameSession. 
	this->players->push_back(player);
	// If a second player joins the game, start the game.
	if (this->players->size() == 2) {
		this->initiateGameplay();
	}
}

GameRoom * const & GameSession::getGameRoom()
{
	return this->gameRoomHandle;
}

GameSession::PlayerListType & GameSession::getPlayers()
{
	return *(this->players);
}

std::tuple<SectorType, std::string> GameSession::spinWheel(int playerId)
{
	// Spin the wheel, yielding a new current sector.
	Sector * const currentSector = this->gameRoomHandle->getWheel()->Spin();
	// Perform the internal actions for the current sector.
	currentSector->Action(this);
	// Return the sector type and name.
	return std::make_tuple(currentSector->getSectorType(), currentSector->getSectorName());
}

bool GameSession::useFreeTurnToken(int playerId)
{
	return false; 
}

void GameSession::bankrupt(int playerId)
{
	// do nothing
}

int GameSession::getWheelSpinsLeft()
{
	return this->gameRoomHandle->getWheel()->getSpinsLeft();
}

int GameSession::getRoundNumber()
{
	return 1;
}

UserInterface * const & GameSession::getUserInterfaceHandle()
{
	return this->userInterfaceHandle;
}


void GameSession::setUserInterfaceHandle(UserInterface * const & userInterface)
{
	this->userInterfaceHandle = userInterface;
}