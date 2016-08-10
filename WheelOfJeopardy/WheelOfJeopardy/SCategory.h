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

	void Bankrupt(Player * const & player);
	void LoseTurn(Player * const & player);
	void FreeTurn(Player * const & player);
	void PlayerChoice(Player * const & player);
	void OpponentChoice(Player * const & player);
	void SpinAgain(Player * const & player);

	/** Define the functions to override the virtual Sector methods. */
	void Action(Player * player) override;

		std::string Action() override {	//workaround int return type
		// TODO: Action needs to pass in the reference to Player, could do this with templates so QCategory works also..
			return this->sectorName;
	}

	bool isEmpty() override {
		return false;
	}

private:

};

