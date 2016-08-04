#pragma once

/**
 * @class GameRoom
 * @brief WoJ GameRoom object.
 * @author Kevin Walther
 * @date 2016
 * @ingroup WheelOfJeopardy
 */

#include <string>

//#include "GameFrame.h"
#include "Wheel.h"
#include "GameBoard.h"

// Forward declaration
struct GameSession;

struct GameRoom
{
	// Define the constructor and destructor.
	GameRoom();
	~GameRoom();

	// Define the GameRoom class methods.

private:
	//int GameRoomID;	// may be unnecessary
	GameSession * gameSessionHandle;
	// Still need to define GameFrame class.
	//GameFrame * gameFrameHandle;
	Wheel * wheelHandle;
	GameBoard * gameBoardHandle;
};

