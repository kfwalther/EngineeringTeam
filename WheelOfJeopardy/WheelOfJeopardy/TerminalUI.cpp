
/**
* @file TerminalUI.cpp
* @brief This file contains the SCategory class definition.
* @author Kevin Walther
* @date 2016
*/
#include "TerminalUI.h"

#include <iostream>

using std::cout;
using std::cin;

TerminalUI::TerminalUI()
	: m_gameStarted(false),
	: m_exit(false)
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
	m_gameStarted = true;
	return m_gameStarted;
}

void TerminalUI::chooseCategory(int category)
{

}

bool TerminalUI::submitAnswer(int answer)
{
	return false;
}

void TerminalUI::spinWheel()
{

}

bool TerminalUI::useFreeTurnToken()
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

void TerminalUI::run()
{
	this->promptPreGame();
}