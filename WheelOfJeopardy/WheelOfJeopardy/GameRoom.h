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
	Wheel * const & getWheel();
private:
	//int GameRoomID;	// may be unnecessary
	GameSession * gameSessionHandle;
	// Still need to define GameFrame class.
	//GameFrame * gameFrameHandle;
	Wheel * wheelHandle;
	GameBoard * gameBoardHandle;
	int spins; //number of wheel spins (start at 50 and decrement)
};

