
/**
 * @file SCategory.cpp
 * @brief This file contains the SCategory class definition.
 * @author Kevin Walther
 * @date 2016
 */
#include "SCategory.h"


SCategory::SCategory(int const sectorType, std::string const sectorName)
{
	this->sectorType = sectorType;
	this->sectorName= sectorName;
}

SCategory::~SCategory()
{
}

// These aren't complete but they'd each call the Player object's functions...
void SCategory::Bankrupt(Player * const & player) {
	// player->SetScore(0);
}

void SCategory::LoseTurn(Player * const & player) {

}

void SCategory::FreeTurn(Player * const & player) {
	// player->SetFreeTurnToken(1);
}

void SCategory::PlayerChoice(Player * const & player) {
	// player->ChooseCategory(0);
}

void SCategory::OpponentChoice(Player * const & player) {

}

void SCategory::SpinAgain(Player * const & player) {

}


