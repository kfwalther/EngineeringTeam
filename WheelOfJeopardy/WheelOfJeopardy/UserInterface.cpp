
/**
* @file UserInterface.cpp
* @brief This file contains the UserInterface class definition.
* @author Joshua Griffith
* @date 2016
*/
#include "UserInterface.h"

UserInterface::UserInterface()
	: m_session(),
	  m_gameStarted(false),
	  m_exit(false),
	  m_endGame(false)
{
	m_players.push_back(new Player("Player 1"));
	m_players.push_back(new Player("Player 2"));
}

UserInterface::~UserInterface()
{
	std::vector<Player*>::iterator iter;

	for (iter = m_players.begin(); iter != m_players.end(); ++iter)
	{
		delete *iter;
	}
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
	std::vector<Player*>::iterator iter;

	for (iter = m_players.begin(); iter != m_players.end(); ++iter)
		m_session.join(*iter);

	if (m_session.initiateGameplay())
		m_gameStarted = true;

	return m_gameStarted;
}

void UserInterface::chooseCategory(int category)
{

}

bool UserInterface::submitAnswer(int answer)
{
	return false;
}

bool UserInterface::useFreeTurnToken()
{
	return false;
}

void UserInterface::endGame()
{
	m_endGame = true;
}

std::vector<std::string> UserInterface::listCategories()
{
	std::vector<std::string> temp;
	return temp;
}