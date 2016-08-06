
/**
 * @file Player.cpp
 * @brief This file contains the Player class definition.
 * @author Kevin Walther
 * @date 2016
 */

#include "Player.h"


// Define the constructor and destructor.
Player::Player(std::string const playerName)
{
	this->username = playerName;
}

Player::~Player()
{
}

// Define the Player object methods.
void Player::createGame()
{
	this->gameSessionHandle = new GameSession();
}

void Player::joinGame(GameSession * const & gameSession)
{

}

void Player::spinWheel(GameSession * const & gameSession)
{

}

void Player::useFreeTurnToken()
{
	/// Player spins again.
	// Decrement token count. 
	this->totalTokens--;
}

void Player::calculateScore(int const value)
{
	// Use this method to add positive or negative points to player's score.
	this->score += value;
}

void Player::chooseCategory()
{

}

void Player::submitAnswer()
{

}

void Player::setScore(int const value)
{
	// Use this method when the player goes bankrupt.
	this->score = value;
}

void Player::setFreeTurnToken(int const value)
{
	this->totalTokens = value;
}
