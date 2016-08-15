
/**
* @file TerminalUI.cpp
* @brief This file contains the SCategory class definition.
* @author Joshua Griffith
* @date 2016
*/
#include "TerminalUI.h"

#include <iostream>

using std::cout;
using std::cin;

TerminalUI::TerminalUI(Player * const & player1, Player * const & player2) : 
		UserInterface(player1, player2) {
	cout << "*********************************\n";
	cout << "*       WHEEL OF JEOPARDY       *\n";
	cout << "*********************************\n";
}

TerminalUI::~TerminalUI()
{

}

bool TerminalUI::submitAnswer(int answer)
{
	return false;
}

void TerminalUI::endGame()
{
	this->m_endGame = this->m_session->terminateGameplay();
}

std::vector<std::string> TerminalUI::listCategories()
{
	std::vector<std::string> temp;
	return temp;
}

void TerminalUI::displayPlayerInfo()
{

}

void TerminalUI::promptPreGame()
{
	int selection = 0;

	std::vector<std::string> options;
	options.push_back("Start new game (hotseat)");
	options.push_back("Exit");

	selection = this->promptSelect(options);

	switch (selection)
	{
	case 1:
		this->startGame();
		break;
	case 2:
		m_exit = true;
		break;
	}
}


void TerminalUI::run()
{
	this->promptPreGame();
}

int TerminalUI::promptSelect(std::vector<std::string> const & options)
{
	int option = 0;

	while (option <= 0 || option > options.size())
	{
		cout << "<< Select an option:" << "\n";

		for (int i = 0; i < options.size(); i++)
			cout << ":: " << i + 1 << ". " << options.at(i) << "\n";

		cout << "\n";
		cout << ">> Selection: ";
		cin >> option;
		cout << "\n";
	}

	return option;
}

//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------

void TerminalUI::UI_StartTurn()
{
	cout << "\n";
	cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "&&           TURN START           &&\n";
	cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "\n";

	cout << "---------------------------------------------------------------------\n";
	cout << ": Game Data" << "\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "<< Round: " << m_session->getRoundNumber() << "\n";
	cout << "<< Spins Remaining: " << m_session->getWheelSpinsLeft() << "\n";
	cout << "\n";

	cout << "---------------------------------------------------------------------\n";
	cout << ": Player Data" << "\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "<< Current Player: " << m_currentPlayer->getName() << "\n";
	cout << "<< Tokens: " << m_currentPlayer->getNumTokens() << "\n";
	cout << "<< Score: " << m_currentPlayer->getScore() << "\n";
	cout << "\n";
}

void TerminalUI::UI_LostTurn()
{
	cout << "\n---------------------------------------------------------------------\n";
	cout << "<< You have lost your turn - skipping" << "\n";
}

void TerminalUI::UI_SpinWheel()
{
	cout << "\n---------------------------------------------------------------------\n";
	std::vector<std::string> options;
	options.push_back("Spin the wheel");
	
	this->promptSelect(options);
}

void TerminalUI::UI_Category(std::string category)
{
	cout << "\n---------------------------------------------------------------------\n";
	cout << "<< Wheel: Landed on category -> " << category << "\n";
}

void TerminalUI::UI_Question(Question & question)
{
	cout << "\n---------------------------------------------------------------------\n";
	cout << "<< Question: " << question.getQuestion() << "\n";
}

bool TerminalUI::UI_AskUseToken()
{
	bool useToken = false;

	int selection = 0;

	std::vector<std::string> options;
	options.push_back("Use token");
	options.push_back("Don't use token");

	selection = this->promptSelect(options);

	switch (selection)
	{
	case 1:
		useToken = true;
		break;
	case 2:
		useToken = false;
		break;
	}

	return useToken;
}

void TerminalUI::UI_UseToken()
{

}

void TerminalUI::UI_LoseTurn()
{
	cout << "\n---------------------------------------------------------------------\n";
	cout << "<< Wheel: You have lost a turn!" << "\n";
}

void TerminalUI::UI_AddFreeTurn()
{
	cout << "\n---------------------------------------------------------------------\n";
	cout << "<< Wheel: You have added a free turn!" << "\n";
}

void TerminalUI::UI_Bankrupt()
{
	cout << "\n---------------------------------------------------------------------\n";
	cout << "<< Wheel: You are bankrupt!" << "\n";
}

void TerminalUI::UI_SpinAgain()
{
	cout << "\n---------------------------------------------------------------------\n";
	cout << "<< Wheel: You get to spin again!" << "\n";
}

void TerminalUI::UI_CorrectAnswer()
{
	cout << "\n---------------------------------------------------------------------\n";
	cout << "<< Question: You answered correctly!" << "\n";
}

void TerminalUI::UI_WrongAnswer()
{
	cout << "\n---------------------------------------------------------------------\n";
	cout << "<< Question: You answered incorrectly!" << "\n";
}

void TerminalUI::UI_EndTurn()
{
	cout << "\n---------------------------------------------------------------------\n";
	cout << "<< End of turn!\n";

	std::vector<std::string> options;
	options.push_back("Next turn");

	this->promptSelect(options);
}

int TerminalUI::UI_ChooseCategory(Wheel::StringVectorType const & categories) {
	cout << "\n---------------------------------------------------------------------\n";
	cout << "<< Wheel: You choose the question category." << "\n";

	return this->promptSelect(categories);
}

void TerminalUI::UI_OpponentChoice() {
	cout << "\n---------------------------------------------------------------------\n";
	cout << "<< Wheel: Your opponents choose the question category." << "\n";
}

int TerminalUI::UI_OpposingVote(Wheel::StringVectorType const & categories, Player * const & player) {
	cout << "\n---------------------------------------------------------------------\n";
	cout << "<< Wheel: You choose the question category." << "\n";

	return this->promptSelect(categories);
}

void TerminalUI::UI_OpponentVoteWinner(std::string const & categoryName) {
	cout << "\n---------------------------------------------------------------------\n";
	cout << "<< Your opponents chose the following category: " << categoryName << "\n";
}

void TerminalUI::UI_GameSummary() {
	cout << "\n";
	cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "&&       END OF GAME SUMMARY      &&\n";
	cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "\n";
	cout << "---------------------------------------------------------------------\n";
	cout << ": Player Data" << "\n";
	cout << "---------------------------------------------------------------------\n";

	// Get list of all players.
	GameSession::PlayerVectorType players = this->m_session->getPlayers();
	for (size_t i = 0; i < players.size(); i++) {
		cout << "<< Player " << (i+1) << ": " << players.at(i)->getName() << "\n";
		cout << "<< Tokens: " << players.at(i)->getNumTokens() << "\n";
		cout << "<< Score: " << players.at(i)->getScore() << "\n";
		cout << "\n";
	}
}