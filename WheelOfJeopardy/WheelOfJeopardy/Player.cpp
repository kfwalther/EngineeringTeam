
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
	gameSession->join(this);
}

void Player::spinWheel()
{
	//getSector(-1) retrieves a random sector
	this->gameSessionHandle->getGameRoom()->getWheel()->getSector(0)->Action(this);


	/*std::string sector = this->gameSessionHandle->getGameRoom()->getWheel()->getSector(-1)->Action();//workaround return string type
	if (sector == "Bankrupt") {
		this->setScore(0);
		this->setFreeTurnToken(0);
	} else if (sector == "Lose Turn") {
		if(this->totalTokens > 0){
			//prompt to use token
			//if yes
			//	this->useFreeTurnToken();
		}

	} else if (sector == "Free Turn") {
		this->totalTokens++;
	} else if (sector == "Player Choice") {
		this->chooseCategory();
	} else if (sector == "Opponent Choice") {
		//switch to other player
		this->chooseCategory();
	} else if (sector == "Spin Again") {
		this->spinWheel();
	}
	//WRST ends here*/



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
	this->gameSessionHandle->getGameRoom()->getWheel()->listCategories();
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
