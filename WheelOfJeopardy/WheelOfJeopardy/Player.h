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
	void useFreeTurnToken();
	void calculateScore(int const value);
	void chooseCategory();
	void submitAnswer();
	void setScore(int const value);
	void setFreeTurnToken(int const value);
	void addFreeTurnToken();
	bool hasFreeTurnToken();
private:
	static int uniqueID; //ensures playerID is unique
	int playerID;
	std::string username;
	double score;
	bool isJoinedGame;
	int totalTokens;
	GameSession * gameSessionHandle;
};

