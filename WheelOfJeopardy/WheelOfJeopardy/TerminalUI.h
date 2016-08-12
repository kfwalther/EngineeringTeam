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
	virtual SectorType spinWheel();
	virtual bool useFreeTurnToken();
	virtual void endGame();
	virtual std::vector<std::string> listCategories();
	virtual bool startGame();
	virtual void run();

	virtual void promptGameLoop();
	virtual void promptPreGame();
	virtual void displayPlayerInfo();
};