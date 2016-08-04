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


// Alias the std namespace for convenience.
using namespace std;

/**
 * @brief This is the main entry point to the WoJ program.
 */
void main()
{
	// Define a queue container of question objects.
	queue <Question> Q;
	// Define the category input file to use.
	string c = "category1.csv";
	// Define the parser object.
	parser Parse;
	// Call the parser for the given category.
	Parse.parseCategory(Q, c);
	// Print some output.
	cout << c << " " << Q.size() << endl;
}

