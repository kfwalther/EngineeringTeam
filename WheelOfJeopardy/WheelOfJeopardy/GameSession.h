#pragma once

/**
* @class GameSession
* @brief WoJ GameSession class.
* @author Kevin Walther
* @date 2016
* @ingroup WheelOfJeopardy
*/

#include <list>
#include <cstddef>

#include "GameRoom.h"
//#include "UserInterface.h"
#include "Player.h"

// Forward declaration
struct Player;

struct GameSession
{
	// Alias the list of Player objects attribute.
	typedef std::list<Player> PlayerListType;

	// Define the constructor/destructor.
	GameSession();
	~GameSession();

	/** Functional methods. */
	void initiateGameplay();
	void terminateGameplay();
	void changeTurns();
	GameRoom * const & getGameRoom();
protected:
	int sessionID;
	PlayerListType playerList;
	// currentPlayer value matches Player.playerID for current player.
	int currentPlayer;
	int otherPlayer;
	int round;
	GameRoom * gameRoomHandle;
	// Still need to define the UserInterface class.
	//UserInterface * userInterfaceHandle;
};

