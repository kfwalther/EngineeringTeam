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
#include "TerminalUI.h"

// Forward declaration
struct Player;

struct GameSession
{
	// Alias the list of Player objects attribute.
	//first element will always point to current player
	//second element will always point to other player.
	typedef std::list<Player *> PlayerListType;

	// Define the constructor/destructor.
	GameSession();
	~GameSession();

	/** Functional methods. */
	void initiateGameplay();
	void terminateGameplay();
	void changeTurns();
	void join(Player *player);
	GameRoom * const & getGameRoom();
	GameSession::PlayerListType & getPlayers();
protected:
	static int uniqueID;//ensures sessionID is unique
	int sessionID;
	TerminalUI * ui;
	PlayerListType * players;
	// currentPlayer value matches Player.playerID for current player.
	int currentPlayer;
	int otherPlayer;
	int rounds;
	GameRoom * gameRoomHandle;
	// Still need to define the UserInterface class.
	//UserInterface * userInterfaceHandle;
};

