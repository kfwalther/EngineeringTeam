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
	TerminalUI();
	virtual ~TerminalUI();

	// Define the UserInterface object methods.
	/*virtual bool createGame();
	virtual bool joinGame(int gameId);
	virtual std::vector<std::string> listGames();*/
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
	virtual void UI_LoseTurn();
	virtual void UI_AddFreeTurn();
	virtual void UI_Bankrupt();
	virtual void UI_SpinAgain();
};