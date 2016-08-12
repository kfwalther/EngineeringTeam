
/**
* @file UserInterface.cpp
* @brief This file contains the UserInterface class definition.
* @author Joshua Griffith
* @date 2016
*/
#include "UserInterface.h"

UserInterface::UserInterface()
	: m_session(),
	  m_player1("Player 1"),
	  m_player2("Player 2")
{

}

UserInterface::~UserInterface()
{

}

/*
// TBD: Hotseat only for now
bool UserInterface::createGame()
{

}

bool UserInterface::joinGame(int gameId)
{

}

std::vector<std::string> UserInterface::listGames()
{

}
*/

bool UserInterface::startGame()
{
	m_session.join(&m_player1);
	m_session.join(&m_player2);

	m_session.initiateGameplay();

	return false;
}

void UserInterface::chooseCategory(int category)
{

}

bool UserInterface::submitAnswer(int answer)
{
	return false;
}

void UserInterface::spinWheel()
{

}

bool UserInterface::useFreeTurnToken()
{
	return false;
}

void UserInterface::endGame()
{

}

std::vector<std::string> UserInterface::listCategories()
{
	std::vector<std::string> temp;
	return temp;
}