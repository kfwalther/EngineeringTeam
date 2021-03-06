
/**
 * @file GameSession.cpp
 * @brief WoJ GameSession class.
 * @author Kevin Walther
 * @date 2016
 */

#include "GameSession.h"


// Define the constructor and destructor.
GameSession::GameSession()
{
	//this->gameRoomHandle = new GameRoom();
	this->players = new GameSession::PlayerVectorType;
	this->round=1; //number of round
	this->sessionID=GameSession::uniqueID;
	GameSession::uniqueID++;

}

GameSession::~GameSession()
{
	// These statements become obscelete with smart pointers.
	if (gameRoomHandle != nullptr) {
		delete gameRoomHandle;
	}
}

int GameSession::uniqueID=0;

/** Functional methods. */
bool GameSession::initiateGameplay()
{
	// Set the current player.
	this->currentPlayerIndex = 0;
//	for (int i = 0; i < this->round; i++) {
		//delete the old GameRoom, and create a new one for round 2.
		this->gameRoomHandle = new GameRoom("QuestionCategory");	
//	}
	return true;
}

bool GameSession::terminateGameplay()
{
	// Check to see if the current round can be terminated.
	if (this->gameRoomHandle->getWheel()->isSpinnable())
		return false;
	else {
		if (this->round == 1) {
			this->round++;
			this->gameRoomHandle = new GameRoom("QuestionCategoryJD");
			return false;
		}
		return true;
	}
}

void GameSession::changeTurns()
{
	this->currentPlayerIndex++;
	if (this->currentPlayerIndex == this->players->size()) {
		this->currentPlayerIndex = 0;	// loop back around.
	}
}

void GameSession::join(Player *player)
{
	// Add the current player to the GameSession. 
	this->players->push_back(player);
	// If a second player joins the game, start the game.
	if (this->players->size() == 2) {
		this->initiateGameplay();
	}
}

GameRoom * const & GameSession::getGameRoom()
{
	return this->gameRoomHandle;
}

GameSession::PlayerVectorType & GameSession::getPlayers()
{
	return *(this->players);
}

std::tuple<SectorType, std::string> GameSession::spinWheel(int playerId)
{
	// Spin the wheel, yielding a new current sector.
	Sector * const currentSector = this->gameRoomHandle->getWheel()->Spin();

	// Perform the internal actions for the current sector.
	this->gameRoomHandle->getWheel()->getCurrentSector()->Action(this);

	// Return the sector type and name.
	return std::make_tuple(currentSector->getSectorType(), currentSector->getSectorName());
}

bool GameSession::useFreeTurnToken(int playerId)
{
	return false; 
}

void GameSession::bankrupt(int playerId)
{
	// do nothing
}

int GameSession::getWheelSpinsLeft()
{
	return this->gameRoomHandle->getWheel()->getSpinsLeft();
}

int GameSession::getRoundNumber()
{
	return this->round;
}

UserInterface * const & GameSession::getUserInterfaceHandle()
{
	return this->userInterfaceHandle;
}


void GameSession::setUserInterfaceHandle(UserInterface * const & userInterface)
{
	this->userInterfaceHandle = userInterface;
}

Question & GameSession::getCurrentQuestion() {
	return this->currentQuestion;
}

void GameSession::setCurrentQuestion(Question newCurrentQuestion) {
	this->currentQuestion = newCurrentQuestion;
}

bool GameSession::answerQuestion(std::string response) {

	int score;
	// Check the player's answer against the correct answer.
	if (this->currentQuestion.checkAnswer(response)) {
		// Correct answer.
		score = this->round * this->currentQuestion.getPoints();//round two points are doubled
		this->getCurrentPlayer()->changeScore(score);
		return true;
	} else {
		// Incorrect answer.
		//score = -1 * this->currentQuestion.getPoints(); //the score has already been changes to negative inside the Question class, this statement reverted it back to positive
		score = this->round * this->currentQuestion.getPoints();
		this->getCurrentPlayer()->changeScore(score);
		this->changeTurns();
		return false;
	}
}

Player * const & GameSession::getCurrentPlayer() {
	return this->players->at(this->currentPlayerIndex);
}
