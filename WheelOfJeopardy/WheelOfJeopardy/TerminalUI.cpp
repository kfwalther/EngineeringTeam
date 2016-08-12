
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

bool TerminalUI::startGame()
{
	return false;
}

void TerminalUI::chooseCategory(int category)
{

}

bool TerminalUI::submitAnswer(int answer)
{
	return false;
}

SectorType TerminalUI::spinWheel()
{
	cout << "Press enter to spin the wheel: ";
	
	// Wait for input
	cin.get();

	// We want to spin the wheel, this returns a sector, should really be at a top level
	return SectorType::CATEGORY;// m_session.spinWheel(&m_currentPlayer);
}

bool TerminalUI::useFreeTurnToken()
{
	return false;// m_session.useFreeTurnToken(&m_currentPlayer);
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

	cout << "Select an option:" << "\n";
	cout << "1. Start new game (hotseat)" << "\n";
	cout << "2. Exit" << "\n";
	cout << "Selection: ";
	cin >> selection;

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

void TerminalUI::promptGameLoop()
{
	while (!m_endGame && !m_exit)
	{
		for (int i = 0; i < m_players.size(); i++)
		{
			this->displayPlayerInfo();
			SectorType sector = this->spinWheel();
			
			switch (sector)
			{
			case SectorType::CATEGORY:
				break;
			case SectorType::LOSE_TURN:
				break;
			case SectorType::FREE_TURN:
				break;
			case SectorType::BANKRUPT:
				break;
			case SectorType::PLAYER_CHOICE:
				break;
			case SectorType::OPP_CHOICE:
				break;
			case SectorType::SPIN_AGAIN:
				break;
			}
		}
	}
}


void TerminalUI::run()
{
	this->promptPreGame();

	if (m_gameStarted)
		this->promptGameLoop();
}