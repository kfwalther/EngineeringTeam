#pragma once

/**
 * @class SCategory
 * @brief WoJ SCategory object.
 * @author Kevin Walther
 * @date 2016
 * @ingroup WheelOfJeopardy
 */
#include "Sector.h"
#include "Player.h"

// Forward Declaration 
struct Player;

struct SCategory : public Sector
{
	SCategory(std::string const sectorName);
	~SCategory();

	void Bankrupt(GameSession * session);
	void LoseTurn(GameSession * session);
	void FreeTurn(GameSession * session);
	void PlayerChoice(GameSession * session);
	void OpponentChoice(GameSession * session);
	void SpinAgain(GameSession * session);
/*	void LoseTurn(Player * const & player);
	void FreeTurn(Player * const & player);
	void PlayerChoice(Player * const & player);
	void OpponentChoice(Player * const & player);
	void SpinAgain(Player * const & player);*/

	/** Define the functions to override the virtual Sector methods. */
	void Action(GameSession * session) override;

	bool isEmpty() override {
		return false;
	}

private:

};

