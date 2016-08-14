#pragma once

/**
* @class TerminalUI
* @brief WoJ TerminalUI object.
* @author Joshua Griffith
* @date 2016
* @ingroup WheelOfJeopardy
*/

#include <string>
#include <vector>

#include "UserInterface.h"

#include "Sector.h"

class TerminalUI : UserInterface
{
public:
	// Define the constructor and destructor.
	TerminalUI(Player * const & player1, Player * const & player2);
	virtual ~TerminalUI();

	// Define the UserInterface object methods.
	virtual void chooseCategory(int category);
	virtual bool submitAnswer(int answer);
	virtual void endGame();
	virtual std::vector<std::string> listCategories();
	virtual void run();

	virtual void promptPreGame();
	virtual void displayPlayerInfo();
	virtual int promptSelect(std::vector<std::string>& options);

	// User Interface Handlers
	virtual void UI_StartTurn();
	virtual void UI_LostTurn();
	virtual void UI_SpinWheel();
	virtual void UI_Category(std::string category);
	virtual void UI_Question(Question & question);
	virtual bool UI_AskUseToken();
	virtual void UI_UseToken();
	virtual void UI_LoseTurn();
	virtual void UI_AddFreeTurn();
	virtual void UI_Bankrupt();
	virtual void UI_SpinAgain();
	virtual void UI_CorrectAnswer();
	virtual void UI_WrongAnswer();
	virtual void UI_EndTurn();
};