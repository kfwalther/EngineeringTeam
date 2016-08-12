
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

}