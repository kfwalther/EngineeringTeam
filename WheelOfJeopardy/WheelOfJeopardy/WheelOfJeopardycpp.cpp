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
	std::string player1 = "Player 1";
	std::string player2 = "Player 2";

	cout << "Enter a name for Player 1: ";
	cin >> player1;

	cout << "Enter a name for Player 2: ";
	cin >> player2;

	Player * player_Player1 = new Player(player1);
	player_Player1->createGame();

	Player * player_Player2 = new Player(player2);

	TerminalUI * userInterface = new TerminalUI(player_Player1, player_Player2);
	userInterface->run();

	//// Define a queue container of question objects.
	//queue<Question> Q;
	//// Define the category input file to use.
	//string c = "category1.csv";
	//// Define the parser object.
	//parser Parse;
	//// Call the parser for the given category.
	//Parse.parseCategory(Q, c);
	//// Print some output.
	//cout << c << " " << Q.size() << endl;
	exit(0);
}

