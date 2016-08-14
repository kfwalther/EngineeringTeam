
/**
* @file UserInterface.cpp
* @brief This file contains the UserInterface class definition.
* @author Joshua Griffith
* @date 2016
*/
#include "UserInterface.h"

UserInterface::UserInterface(Player * const & player1, Player * const & player2)
	: m_session(player1->getGameSession()),
	  m_gameStarted(false),
	  m_exit(false),
	  m_endGame(false)
{
	this->m_players.push_back(player1);
	this->m_players.push_back(player2);
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

				//
				// All UI logic pertaining to the wheel is handled in the following while loop
				//
				bool answerCategory = false;
				bool spinWheel = true;
				while (spinWheel)
				{
					// Spin the wheel
					this->UI_SpinWheel();
					SectorType sectorType; std::string sectorName;
					std::tie (sectorType, sectorName) = m_session->spinWheel(m_currentPlayer->getId());
					spinWheel = false;

					// Take action depending on wheel spin sector
					switch (sectorType)
					{
					case SectorType::CATEGORY:
						this->UI_PlaceHolder("Category");
						answerCategory = true;
						break;
					case SectorType::LOSE_TURN:

						// Give the player a chance to use a free turn token
						if (m_currentPlayer->hasFreeTurnToken() && this->UI_AskUseToken())
						{
							m_currentPlayer->useFreeTurnToken();
							spinWheel = true;
							this->UI_UseToken();
						}
						else
						{
							m_currentPlayer->loseTurn();
							this->UI_LoseTurn();
						}
						break;
					case SectorType::FREE_TURN:
						m_currentPlayer->addFreeTurnToken();
						this->UI_AddFreeTurn();
						break;
					case SectorType::BANKRUPT:
						m_session->bankrupt(m_currentPlayer->getId());
						this->UI_Bankrupt();
						break;
					case SectorType::PLAYER_CHOICE:
						this->UI_PlaceHolder("Player Choice");
						answerCategory = true;
						break;
					case SectorType::OPP_CHOICE:
						this->UI_PlaceHolder("Opp Choice");
						answerCategory = true;
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

				//
				// All UI logic pertaining to categories is handled within the following if statement
				//
				if (answerCategory)
				{
					this->UI_PlaceHolder("Answer a category question");
				}
			}
			else
			{
				this->UI_LostTurn();
			}
		}
	}
}

bool UserInterface::startGame()
{
	// Join the second player to the game.
	this->m_players.back()->joinGame(this->m_players.front());

	// Start the game loop.
	this->m_gameStarted = true;
	this->runGameLoop();

	return this->m_gameStarted;
}

bool UserInterface::useFreeTurnToken()
{
	return m_session->useFreeTurnToken(m_currentPlayer->getId());
}

void UserInterface::endGame()
{
	m_endGame = true;
}