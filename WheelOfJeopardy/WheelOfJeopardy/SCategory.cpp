
/**
 * @file SCategory.cpp
 * @brief This file contains the SCategory class definition.
 * @author Kevin Walther
 * @date 2016
 */
#include "SCategory.h"
#include "Player.h"

#include "GameSession.h"

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

void SCategory::Bankrupt(GameSession * session) {
	session->getPlayers().front()->setScore(0);
	session->getPlayers().front()->setFreeTurnToken(0);
}

void SCategory::LoseTurn(GameSession * session) {
	if(session->getPlayers().front()->hasFreeTurnToken()){
		//ask player if want to use FreeTurnToken
		//if yes
			//session->getPlayers().front()->
	}
}

void SCategory::FreeTurn(GameSession * session) {
	// player->addFreeTurnToken();
}

void SCategory::PlayerChoice(GameSession * session) {
	// player->ChooseCategory(0);
}

void SCategory::OpponentChoice(GameSession * session) {

}

void SCategory::SpinAgain(GameSession * session) {

}

void SCategory::Action(GameSession * session) {
        if (this->sectorName == "Bankrupt") {
			this->Bankrupt(session);
        } else if (this->sectorName == "Lose Turn") {
//            this->LoseTurn(session->getPlayers().front());
        } else if (this->sectorName == "Free Turn") {
 //           this->FreeTurn(session->getPlayers().front());
        } else if (this->sectorName == "Player Choice") {
 //           this->PlayerChoice(session->getPlayers().front());
        } else if (this->sectorName == "Opponent Choice") {
 //           this->OpponentChoice(session->getPlayers().front());
        } else if (this->sectorName == "Spin Again") {
  //          this->SpinAgain(session->getPlayers().front());
        }  
}          
