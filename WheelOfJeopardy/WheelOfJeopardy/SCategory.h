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
	SCategory(int const sectorType, std::string const sectorName);
	~SCategory();

	void Bankrupt(Player * const & player);
	void LoseTurn(Player * const & player);
	void FreeTurn(Player * const & player);
	void PlayerChoice(Player * const & player);
	void OpponentChoice(Player * const & player);
	void SpinAgain(Player * const & player);

	/** Define the functions to override the virtual Sector methods. */
	void Action() override {
		// TODO: Action needs to pass in the reference to Player, could do this with templates so QCategory works also..
		if (this->sectorName == "Bankrupt") {
			//this->Bankrupt(player);
		} else if (this->sectorName == "Lose Turn") {
			//this->LoseTurn(player);
		} else if (this->sectorName == "Free Turn") {
			//this->FreeTurn(player);
		} else if (this->sectorName == "Player Choice") {
			//this->PlayerChoice(player);
		} else if (this->sectorName == "Opponent Choice") {
			//this->OpponentChoice(player);
		} else if (this->sectorName == "Spin Again") {
			//this->SpinAgain(player);
		}
	}

	bool isEmpty() override {
		return false;
	}

private:

};

