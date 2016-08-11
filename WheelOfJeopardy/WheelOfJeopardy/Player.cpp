
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
	this->score=0;
	this->isJoinedGame=false;
	this->totalTokens=0;
	this->playerID=Player::uniqueID;
	Player::uniqueID++;
}

Player::~Player()
{
}

int Player::uniqueID=0;

// Define the Player object methods.
void Player::createGame()
{
	this->gameSessionHandle = new GameSession();
	this->joinGame(this);
}

void Player::joinGame(Player * host)
{
	this->gameSessionHandle=host->gameSessionHandle;
	this->gameSessionHandle->join(this);
}

void Player::spinWheel()
{
	//getSector(-1) retrieves a random sector
	this->gameSessionHandle->getGameRoom()->getWheel()->getSector(-1)->Action(this->gameSessionHandle);
	

}

bool Player::hasFreeTurnToken(){
	return (this->totalTokens>0 ? true : false);
}
void Player::useFreeTurnToken()
{
	// Decrement token count. 
	this->totalTokens--;
	this->spinWheel();
}

void Player::calculateScore(int const value)
{
	// Use this method to add positive or negative points to player's score.
	this->score += value;
}

void Player::chooseCategory()
{
	this->gameSessionHandle->getGameRoom()->getWheel()->listCategories();//returns a vector of strings, needs to be pushed to UI
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

void Player::addFreeTurnToken()
{
	this->totalTokens++;
}
