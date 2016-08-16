
/**
 * @file SCategory.cpp
 * @brief This file contains the SCategory class definition.
 * @author Kevin Walther
 * @date 2016
 */
#include "SCategory.h"
#include "Player.h"

#include "GameSession.h"

SCategory::SCategory(std::string const sectorName, SectorType sectorTypeIn)
{
	// Sector.sectorType: 1 == QCategory, 2 == SCategory
	this->sectorType = 2;
	this->sectorName = sectorName;
	this->whlSectorType = sectorTypeIn;
}

SCategory::~SCategory()
{
}

//session is a pointer to the instace that contains the player list
//front() returns a pointer to the first (current) player
void SCategory::Bankrupt(GameSession * session) {
	session->getCurrentPlayer()->setScore(0);
	session->getCurrentPlayer()->setFreeTurnToken(0);
	session->changeTurns();
}

void SCategory::LoseTurn(GameSession * session) {
	if(session->getCurrentPlayer()->hasFreeTurnToken()){
		//TODO
		//ask player if want to use FreeTurnToken
		//if yes
			//session->getPlayers().front()->useFreeTurnToken();
		//else
			//session->changeTurns();
	}
	else {
		session->changeTurns();
	}
}

void SCategory::FreeTurn(GameSession * session) {
	session->getCurrentPlayer()->addFreeTurnToken();
}

void SCategory::PlayerChoice(GameSession * session) {
	//session->getCurrentPlayer()->chooseCategory();
}

void SCategory::OpponentChoice(GameSession * session) {
	//back() returns a pointer to the opponent player
	//session->getPlayers().back()->chooseCategory();
}

void SCategory::SpinAgain(GameSession * session) {
	//do nothing
}

void SCategory::Action(GameSession * session) {	//overrides Sector::Action(GameSession *), calls the appropriate function and forwards the GameSession pointer to it
		std::cout << "Spins remaining: " << session->getGameRoom()->getWheel()->getSpinsLeft() << std::endl;//testcode
		std::cout << "Player '" << session->getCurrentPlayer()->getName() << "' landed on: " << sectorName << std::endl;//testcode

        if (this->sectorName == "Bankrupt") {
			this->Bankrupt(session);
        } else if (this->sectorName == "Lose Turn") {
			this->LoseTurn(session);
        } else if (this->sectorName == "Free Turn") {
			this->FreeTurn(session);
        } else if (this->sectorName == "Player Choice") {
			this->PlayerChoice(session);
        } else if (this->sectorName == "Opponent Choice") {
			this->OpponentChoice(session);
        } else if (this->sectorName == "Spin Again") {
			this->SpinAgain(session);
        }  
}          
