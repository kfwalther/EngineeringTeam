
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

int Player::getScore()
{
	return this->score;
}

void Player::joinGame(Player * host)
{
	this->gameSessionHandle=host->gameSessionHandle;
	this->gameSessionHandle->join(this);
}
/*//Old methods, superceded by Wheel::Spin()
void Player::spinWheel()
{
	//Spin the Wheel to get a random Sector
	this->gameSessionHandle->getGameRoom()->getWheel()->Spin()->Action(this->gameSessionHandle);
}

void Player::spinWheel(int x)//testcode to force where the wheel spins to
{
	this->gameSessionHandle->getGameRoom()->getWheel()->Spin(x)->Action(this->gameSessionHandle);
}
*/
std::string Player::getName() {
	return this->username;
}

bool Player::hasFreeTurnToken(){
	return (this->totalTokens>0 ? true : false);
}
void Player::useFreeTurnToken()
{
	// Decrement token count. 
	this->totalTokens--;
}

void Player::changeScore(int const value)
{
	// Use this method to add positive or negative points to player's score.
	this->score += value;
}

void Player::chooseCategory()
{
	this->gameSessionHandle->getGameRoom()->getWheel()->listCategories();//returns a vector of strings, needs to be pushed to UI
	//TODO
	//int x = user's selection
	//if x is between 0 and 5 (inclusive) and that category still has open questions
		//this->gameSessionHandle->getGameRoom()->getWheel()->Spin(x)->Action(this->gameSessionHandle);
	//else
		//stupid user! pick a real category
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
