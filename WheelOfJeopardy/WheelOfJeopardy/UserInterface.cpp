
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

void UserInterface::runGameLoop()
{
	while (!m_endGame)
	{
		// Let all the players have a turn 
		for (std::vector<Player*>::iterator iter = m_players.begin(); iter != m_players.end(); ++iter)
		{
			// Set the current player turn 
			m_currentPlayer = *iter;

			// Check if the player lost a turn last round
			if (!(m_currentPlayer->hasLostTurn()))
			{
				this->UI_StartTurn();

				bool spinWheel = true;
				while (spinWheel)
				{
					this->UI_SpinWheel();
					SectorType sectorType = m_session.spinWheel(m_currentPlayer->getId());
					spinWheel = false;

					switch (sectorType)
					{
					case SectorType::CATEGORY:
						this->UI_PlaceHolder("Category");
						break;
					case SectorType::LOSE_TURN:
						m_currentPlayer->loseTurn();
						this->UI_LoseTurn();		
						break;
					case SectorType::FREE_TURN:
						m_currentPlayer->addFreeTurnToken();
						this->UI_AddFreeTurn();
						break;
					case SectorType::BANKRUPT:
						m_session.bankrupt(m_currentPlayer->getId());
						this->UI_Bankrupt();
						break;
					case SectorType::PLAYER_CHOICE:
						this->UI_PlaceHolder("Player Choice");
						break;
					case SectorType::OPP_CHOICE:
						this->UI_PlaceHolder("Opp Choice");
						break;
					case SectorType::SPIN_AGAIN:
						spinWheel = true;
						this->UI_SpinAgain();
						break;
					default:
						this->UI_PlaceHolder("Default");
						break;
					}
				}
			}
			else
			{
				this->UI_LostTurn();
			}
		}
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
	{
		m_gameStarted = true;
		this->runGameLoop();
	}

	return m_gameStarted;
}

bool UserInterface::useFreeTurnToken()
{
	return m_session.useFreeTurnToken(m_currentPlayer->getId());
}

void UserInterface::endGame()
{
	m_endGame = true;
}