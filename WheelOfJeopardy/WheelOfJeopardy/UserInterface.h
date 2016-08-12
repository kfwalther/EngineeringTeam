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

class UserInterface
{
public:
	// Define the constructor and destructor.
	UserInterface();
	virtual ~UserInterface();

	// Define the UserInterface object methods.
	/*virtual bool createGame();
	virtual bool joinGame(int gameId);
	virtual std::vector<std::string> listGames();*/
	virtual void chooseCategory(int category);
	virtual bool submitAnswer(int answer);
	virtual void spinWheel();
	virtual bool useFreeTurnToken();
	virtual void endGame();
	virtual std::vector<std::string> listCategories();
	virtual bool startGame();
	
private:
	GameSession m_session;
	Player m_player1;
	Player m_player2;
};

