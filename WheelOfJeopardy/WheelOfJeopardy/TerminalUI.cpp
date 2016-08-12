
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

TerminalUI::TerminalUI()
{
	cout << "*********************************\n";
	cout << "*       WHEEL OF JEOPARDY       *\n";
	cout << "*********************************\n";
}

TerminalUI::~TerminalUI()
{

}

/*
bool TerminalUI::createGame()
{

}

bool TerminalUI::joinGame(int gameId)
{

}

std::vector<std::string> TerminalUI::listGames()
{

}*/

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
		cout << "Select an option:" << "\n";

		for (int i = 0; i < options.size(); i++)
			cout << i + 1 << ". " << options.at(i) << "\n";

		cout << "Selection: ";
		cin >> option;
	}

	return option;
}

//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------

void TerminalUI::UI_StartTurn()
{
	cout << "---------------------------------------------------------------------\n";
	cout << "WheelOfJeopardy -- StartTurn" << "\n";

	cout << "---------------------------------------------------------------------\n";
	cout << "Game Data" << "\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "Round: " << m_session.getRoundNumber() << "\n";
	cout << "Spins Remaining: " << m_session.getWheelSpinsLeft() << "\n";

	cout << "---------------------------------------------------------------------\n";
	cout << "Player Data" << "\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "Current Player: " << m_currentPlayer->getName() << "\n";
	cout << "Tokens: " << m_currentPlayer->getNumTokens() << "\n";
	cout << "Score: " << m_currentPlayer->getScore() << "\n";
}

void TerminalUI::UI_LostTurn()
{
	cout << "---------------------------------------------------------------------\n";
	cout << "WheelOfJeopardy -- LostTurn" << "\n";
	cout << "You have lost your turn - skipping" << "\n";
}

void TerminalUI::UI_SpinWheel()
{
	cout << "---------------------------------------------------------------------\n";
	std::vector<std::string> options;
	options.push_back("Spin the wheel");
	
	this->promptSelect(options);
}

void TerminalUI::UI_LoseTurn()
{
	cout << "---------------------------------------------------------------------\n";
	cout << "WheelOfJeopardy -- LoseTurn" << "\n";
	cout << "Wheel: You have lost a turn!" << "\n";
}

void TerminalUI::UI_AddFreeTurn()
{
	cout << "---------------------------------------------------------------------\n";
	cout << "WheelOfJeopardy -- AddFreeTurn" << "\n";
	cout << "Wheel: You have added a free turn!" << "\n";
}

void TerminalUI::UI_Bankrupt()
{
	cout << "---------------------------------------------------------------------\n";
	cout << "WheelOfJeopardy -- Bankrupt" << "\n";
	cout << "Wheel: You are bankrupt!" << "\n";
}

void TerminalUI::UI_SpinAgain()
{
	cout << "---------------------------------------------------------------------\n";
	cout << "WheelOfJeopardy -- SpinAgain" << "\n";
	cout << "Wheel: You get to spin again!" << "\n";
}