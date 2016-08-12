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
	virtual bool useFreeTurnToken();
	virtual void endGame();
	virtual std::vector<std::string> listCategories();
	virtual bool startGame();
	
	// Pure virtual functions
	virtual SectorType spinWheel() = 0;

protected:
	GameSession m_session;
	bool m_gameStarted;
	bool m_exit;
	bool m_endGame;
	std::vector<Player*> m_players;
	Player* m_currentPlayer;
};

