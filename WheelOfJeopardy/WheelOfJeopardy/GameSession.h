#pragma once

/**
* @class GameSession
* @brief WoJ GameSession class.
* @author Kevin Walther
* @date 2016
* @ingroup WheelOfJeopardy
*/

#include <vector>
#include <cstddef>
#include <tuple>

#include "GameRoom.h"
#include "UserInterface.h"
#include "Player.h"

// Forward declaration
struct Player;
class UserInterface;

struct GameSession
{
	// Alias the vector of Player objects attribute.
	typedef std::vector<Player *> PlayerVectorType;

	// Define the constructor/destructor.
	GameSession();
	~GameSession();

	/** Functional methods. */
	bool initiateGameplay();
	void terminateGameplay();
	void changeTurns();
	void join(Player *player);
	GameRoom * const & getGameRoom();
	GameSession::PlayerVectorType & getPlayers();

	// Top level, exposed to UI
	std::tuple<SectorType, std::string> spinWheel(int playerId);
	bool useFreeTurnToken(int playerId);
	void bankrupt(int playerId);
	int getWheelSpinsLeft();
	int getRoundNumber();
	UserInterface * const & getUserInterfaceHandle();
	void setUserInterfaceHandle(UserInterface * const & userInterface);
	Question & getCurrentQuestion();
	void setCurrentQuestion(Question newCurrentQuestion);
	bool answerQuestion();
	Player * const & getCurrentPlayer();

protected:
	static int uniqueID;//ensures sessionID is unique
	int sessionID;
	PlayerVectorType * players;
	// currentPlayer value matches Player.playerID for current player.
	int currentPlayerIndex;
	int currentPlayer;
	int otherPlayer;
	int rounds;
	GameRoom * gameRoomHandle;
	UserInterface * userInterfaceHandle;
	Question currentQuestion;
};

