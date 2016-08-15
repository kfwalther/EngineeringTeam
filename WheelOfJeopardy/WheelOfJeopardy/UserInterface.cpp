
/**
* @file UserInterface.cpp
* @brief This file contains the UserInterface class definition.
* @author Joshua Griffith
* @date 2016
*/
#include "UserInterface.h"
/*
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
					//m_currentPlayer->loseTurn();
					this->UI_LoseTurn();
				}
				break;
			case SectorType::FREE_TURN:
				// SCategory::Action performs this, don't do it twice!
				//m_currentPlayer->addFreeTurnToken();
				this->UI_AddFreeTurn();
				spinWheel = true;	// Player spins again.
				break;
			case SectorType::BANKRUPT:
				m_session->bankrupt(m_currentPlayer->getId());
				this->UI_Bankrupt();
				break;
			case SectorType::PLAYER_CHOICE:
				// Provide a list of available categories and let the current player choose 
				this->m_session->getCurrentPlayer()->chooseCategory(this->UI_ChooseCategory(m_session->getGameRoom()->getWheel()->listCategories()));
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
					spinWheel = true;
				}
				else
				{
					this->UI_WrongAnswer();
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
/**
* @file UserInterface.cpp
* @brief This file contains the UserInterface class definition.
* @author Joshua Griffith
* @date 2016

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
}*/