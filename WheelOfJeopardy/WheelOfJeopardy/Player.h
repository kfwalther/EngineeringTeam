#pragma once

/**
 * @class Player
 * @brief WoJ Player object.
 * @author Kevin Walther
 * @date 2016
 * @ingroup WheelOfJeopardy
 */

#include <string>

#include "GameSession.h"


struct Player
{
	// Define the constructor and destructor.
	Player(std::string const playerName);
	~Player();

	// Define the Player object methods.
	void createGame();
	void joinGame(Player * hostPlayer);
	void spinWheel();
	void spinWheel(int);//testcode to force the sector that the wheel will spin to
	void useFreeTurnToken();
	void changeScore(int const value);
	void chooseCategory(int const categoryIndex);
	void submitAnswer();
	void setScore(int const value);
	double getScore();
	void setFreeTurnToken(int const value);
	void addFreeTurnToken();
	bool hasLostTurn();
	bool hasFreeTurnToken();
	void clearLostTurn();
	void loseTurn();
	std::string getName();
	int getId();
	int getNumTokens();
	GameSession * const & getGameSession();
private:
	static int uniqueID; //ensures playerID is unique
	int playerID;
	std::string username;
	double score;
	bool isJoinedGame;
	int totalTokens;
	bool m_lostTurn;
	GameSession * gameSessionHandle;
};

