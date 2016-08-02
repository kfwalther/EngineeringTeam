#include "parser.h"
#include "Question.h"
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

parser::parser()
{
}

parser::~parser()
{
}

void parser::parseCategory(std::queue<Question> &queue, std::string &category)
{
	string question;
	string answer;
	string tempPoints;
	string input = category;
	ifstream file;
	int points;

	file.open(input.c_str());

	if (file.fail())
		cerr << "error opening file " << endl;

	getline(file, category, '\n');

	while (!file.eof())
	{
		getline(file, question, ',');
		getline(file, answer, ',');
		getline(file, tempPoints, '\n');

		points = atol(tempPoints.c_str());

		Question placeHolder(question, answer, points);

		queue.push(placeHolder);
	}

	//Closes the input file
	file.close();
}
