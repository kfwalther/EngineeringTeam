
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

void TerminalUI::chooseCategory(int category)
{

}

bool TerminalUI::submitAnswer(int answer)
{
	return false;
}

void TerminalUI::endGame()
{

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

int TerminalUI::promptSelect(std::vector<std::string>& options)
{
	int option = 0;

	while (option <= 0 || option > options.size())
	{
		cout << "\n";
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
	cout << "---------------------------------------------------------------------\n";
	cout << "<< You have lost your turn - skipping" << "\n";
}

void TerminalUI::UI_SpinWheel()
{
	cout << "---------------------------------------------------------------------\n";
	std::vector<std::string> options;
	options.push_back("Spin the wheel");
	
	this->promptSelect(options);
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
	cout << "---------------------------------------------------------------------\n";
	cout << "<< Wheel: You have lost a turn!" << "\n";
}

void TerminalUI::UI_AddFreeTurn()
{
	cout << "---------------------------------------------------------------------\n";
	cout << "<< Wheel: You have added a free turn!" << "\n";
}

void TerminalUI::UI_Bankrupt()
{
	cout << "---------------------------------------------------------------------\n";
	cout << "<< Wheel: You are bankrupt!" << "\n";
}

void TerminalUI::UI_SpinAgain()
{
	cout << "---------------------------------------------------------------------\n";
	cout << "<< Wheel: You get to spin again!" << "\n";
}

void TerminalUI::UI_EndTurn()
{
	cout << "---------------------------------------------------------------------\n";
	cout << "<< End of turn!";

	std::vector<std::string> options;
	options.push_back("Next turn");

	this->promptSelect(options);
}