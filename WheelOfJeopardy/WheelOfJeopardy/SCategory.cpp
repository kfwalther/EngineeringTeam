
/**
 * @file SCategory.cpp
 * @brief This file contains the SCategory class definition.
 * @author Kevin Walther
 * @date 2016
 */
#include "SCategory.h"
#include "Player.h"


SCategory::SCategory(std::string const sectorName)
{
	// Sector.sectorType: 1 == QCategory, 2 == SCategory
	this->sectorType = 2;
	this->sectorName = sectorName;
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

void SCategory::Action(Player * player) {
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

