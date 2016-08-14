
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

	// Give the GameSession instance a reference to the UserInterface instance.
	this->m_session->setUserInterfaceHandle(this);
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
		// Get the current player turn.
		m_currentPlayer = this->m_session->getCurrentPlayer();

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
				std::tie(sectorType, sectorName) = m_session->spinWheel(m_currentPlayer->getId());
				spinWheel = false;

				// Take action depending on wheel spin sector
				switch (sectorType)
				{
				case SectorType::CATEGORY:
					this->UI_Category(sectorName);
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
					// NOTE:  This one is pretty straight-forward -- we just want 
					// to provide a list of available categories and let the 
					// user choose 
					//
					// std::vector<std::categories> categories = m_session->getCategories();
					// m_session->chooseCategory(this->UI_ChooseCategory(categories));

					// Remove UI_PlaceHolder call once above implemented
					this->UI_PlaceHolder("Player Choice");
					answerCategory = true;
					break;
				case SectorType::OPP_CHOICE:
					// NOTE: Now this one is more complex... we want to let all 
					// opponent (non-current) players vote on the category to choose
					//
					// std::vector<std::categories> categories = m_session->getCategories();
					// 
					// std::map<std::string, int> votes;
					// 
					// for (std::vector<Player*>::iterator iter_2 = m_players.begin(); iter_2 != m_players.end(); ++iter_2)
					// {
					//		if(*iter_2 != m_currentPlayer)
					//		{
					//			std::string choice = this->UI_OppVote(categories, *iter_2);
					//			votes[choice]++;
					//		}
					// }
					//
					// int largestVote = votes[0].second;
					// std::string vote = votes[1].first;
					// for (int i = 0; i < votes.size(); i++)
					// {
					//		if(votes[i].second > largestVote)
					//			vote = votes[i].first;
					// }
					// 
					// this->UI_OppVoteWinner(vote);
					// m_session.voteCategory(vote);
					//

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
				// NOTE: I am expecting some return type that includes 
				// the question text, list of acceptable options, and
				// any additional information (eg points) that may be 
				// relevant from a UI perspective. If the existing question
				// class has these accessors, then that'll work for this
				//
				// It'd also be good to grab the timer value and pass it to a 
				// UI_* function every x ticks 
				//

				this->UI_Question(m_session->getCurrentQuestion());
					
				if (m_session->answerQuestion())
				{
					this->UI_CorrectAnswer();
				}
				else
				{
					this->UI_WrongAnswer();
				}
			}

			this->UI_EndTurn();
		}
		else
		{
			this->UI_LostTurn();
		}
	}
}

bool UserInterface::startGame()
{
	// Join the second player to the game.
	m_players.back()->joinGame(m_players.front());

	// Start the game loop.
	m_gameStarted = true;
	this->runGameLoop();

	return m_gameStarted;
}

bool UserInterface::useFreeTurnToken()
{
	return m_session->useFreeTurnToken(m_currentPlayer->getId());
}

void UserInterface::endGame()
{
	m_endGame = true;
}