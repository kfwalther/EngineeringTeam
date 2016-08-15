#pragma once

/**
* @class UserInterface
* @brief WoJ UserInterface object.
* @author Kevin Walther
* @date 2016
* @ingroup WheelOfJeopardy
*/

#include <string>
#include <vector>

#include "GameSession.h"
#include "Player.h"
#include "Sector.h"

// Forward declaration
struct Player;

class UserInterface
{
public:
	// Define the constructor and destructor.
	UserInterface(Player * const & player1, Player * const & player2);
	virtual ~UserInterface();

	// Define the UserInterface object methods.
	virtual void runGameLoop();

	virtual bool useFreeTurnToken();
	virtual void endGame() = 0;
	virtual bool startGame();

	// Pure virtual UI handlers
	virtual void UI_StartTurn() = 0;
	virtual void UI_LostTurn() = 0;
	virtual void UI_SpinWheel() = 0;
	virtual void UI_Category(std::string category) = 0;
	virtual void UI_Question(Question & question) = 0;
	virtual bool UI_AskUseToken() = 0;
	virtual void UI_UseToken() = 0;
	virtual void UI_LoseTurn() = 0;
	virtual void UI_AddFreeTurn() = 0;
	virtual void UI_Bankrupt() = 0;
	virtual void UI_SpinAgain() = 0;
	virtual void UI_CorrectAnswer() = 0;
	virtual void UI_WrongAnswer() = 0;
	virtual void UI_EndTurn() = 0;
	virtual int UI_ChooseCategory(Wheel::StringVectorType const & categories) = 0;
	virtual void UI_GameSummary() = 0;

	virtual void UI_PlaceHolder(std::string input)
	{
		std::cout << "\n---------------" << "\n";
		std::cout << "PlaceHolder: " << input << "\n";
		std::cout << "---------------" << "\n\n";
	}

protected:
	GameSession * m_session;
	bool m_gameStarted;
	bool m_exit;
	bool m_endGame;
	std::vector<Player *> m_players;
	Player * m_currentPlayer;
};
