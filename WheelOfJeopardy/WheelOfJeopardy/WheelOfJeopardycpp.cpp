/**
 * @file WheelOfJeopardycpp.cpp
 * @brief This file contains the main function.
 * @author Edwin Flores
 * @date 2016
 */
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "Question.h"
#include "parser.h"
#include "Player.h"
#include "TerminalUI.h"

// Alias the std namespace for convenience.
using namespace std;

/**
 * @brief This is the main entry point to the WoJ program.
 */
void main()
{
	std::vector<Player*> players;
	std::string input;

	cout << "Enter a name for player 1: ";
	cin >> input;
	players.push_back(new Player(input));
	players.at(0)->createGame();

	cout << "Enter a name for player 2: ";
	cin >> input;
	players.push_back(new Player(input));

	// logic is available  for multiple players, possible engine changes needed
	/*
	bool add = true;
	while (add && players.size() < 6)
	{
		cout << "Add more players? (Y/n): ";
		cin >> input;

		if (input == "Y")
		{
			add = true;
			cout << "Enter a name for player " << players.size() + 1 << " : ";
			cin >> input;
			players.push_back(new Player(input));
		}
		else
		{
			add = false;
		}
	} */

	TerminalUI * userInterface = new TerminalUI(players);
	userInterface->run();

	exit(0);
}

