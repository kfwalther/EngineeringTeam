
/**
* @file UserInterface.cpp
* @brief This file contains the UserInterface class definition.
* @author Joshua Griffith
* @date 2016
*/

#include <map>

#include "UserInterface.h"

UserInterface::UserInterface(Player * const & player1, Player * const & player2)
	: m_session(player1->getGameSession()),
	  m_gameStarted(false),
	  m_exit(false),
	  m_endGame(false),
	  m_answering(false),
	  m_timerThread(&UserInterface::tick, this)
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
	while (!this->m_endGame)
	{
		// Get the current player turn.
		m_currentPlayer = this->m_session->getCurrentPlayer();

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
			answerCategory = false;

			// Take action depending on wheel spin sector
			switch (sectorType)
			{
				case SectorType::CATEGORY: {
					this->UI_Category(sectorName);
					answerCategory = true;
					break;
				}
				case SectorType::LOSE_TURN: {
					// Give the player a chance to use a free turn token
					if (m_currentPlayer->hasFreeTurnToken() && this->UI_AskUseToken())
					{
						m_currentPlayer->useFreeTurnToken();
						spinWheel = true;
						this->UI_UseToken();
					}
					else
					{
						//m_currentPlayer->loseTurn();
						this->UI_LoseTurn();
					}
					break;
				}
				case SectorType::FREE_TURN: {
					// SCategory::Action performs this, don't do it twice!
					//m_currentPlayer->addFreeTurnToken();
					this->UI_AddFreeTurn();
					spinWheel = true;	// Player spins again.
					break;
				}
				case SectorType::BANKRUPT: {
					m_session->bankrupt(m_currentPlayer->getId());
					this->UI_Bankrupt();
					break;
				}
				case SectorType::PLAYER_CHOICE: {
					// Provide a list of available categories and let the current player choose.
					this->m_session->getCurrentPlayer()->chooseCategory(
							this->UI_ChooseCategory(m_session->getGameRoom()->getWheel()->listCategories()) - 1);
					answerCategory = true;
					break;
				}
				case SectorType::OPP_CHOICE: {
					// Tell player what they landed on.
					this->UI_OpponentChoice();
					Wheel::StringVectorType const catVector = this->m_session->getGameRoom()->getWheel()->listCategories();
					// Initialize votes vector.
					std::vector<int> votes(catVector.size(), 0);
					// Loop through each player.
					for (auto const & currentPlayer : this->m_players) {
						// Choose all opposing players to poll for a vote.
						if (currentPlayer != this->m_currentPlayer) {
							int chosenIndex = this->UI_OpposingVote(catVector, currentPlayer);
							votes[chosenIndex - 1]++;
						}
					}
					// Get index of most-voted category.
					int const topCategoryIndex = std::distance(
							std::begin(votes), std::max_element(std::begin(votes), std::end(votes)));
					// Notify the players of the chosen Category.
					this->UI_OpponentVoteWinner(catVector[topCategoryIndex]);
					// Choose the next question for the chosen category.
					this->m_session->getCurrentPlayer()->chooseCategory(topCategoryIndex);
					answerCategory = true;
					break;
				}
				case SectorType::SPIN_AGAIN: {
					spinWheel = true;
					this->UI_SpinAgain();
					break;
				}
				default: {
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

				m_answering = true;

				if (m_session->answerQuestion())
				{
					this->UI_CorrectAnswer();
					spinWheel = true;
				}
				else
				{
					this->UI_WrongAnswer();

					// Give the player a chance to use a free turn token
					if (m_currentPlayer->hasFreeTurnToken() && this->UI_AskUseToken())
					{
						m_currentPlayer->useFreeTurnToken();
						spinWheel = true;
						this->UI_UseToken();
					}
					else 
						spinWheel = false;
				}
			}

			// Check to see if the game is terminated, if so
			// force spinWheel to be false.
			this->endGame();
			if (this->m_endGame) {
				spinWheel = false;
			}
				
		}

		this->UI_EndTurn();
	}

	// Print end of game info.
	this->UI_GameSummary();
}

void UserInterface::tick()
{
	while (!m_exit)
	{
		while (m_answering)
		{
			double time = m_session->getCurrentQuestion().getTime();
			
			if ((int)time != 0)
			{
				this->UI_Timer(time);
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			else
			{
				m_answering = false;
				this->UI_EndTimer();
			}

		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void UserInterface::tickInterrupt()
{
	this->m_answering = false;
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
