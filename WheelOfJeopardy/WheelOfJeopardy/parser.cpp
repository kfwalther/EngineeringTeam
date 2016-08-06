#include "parser.h"
#include "Question.h"
#include <iostream>
#include <fstream>
#include <string>
#include <queue>


parser::parser()
{
}

parser::~parser()
{
}

void parser::parseCategory(std::queue<Question> & queue, std::string const & category)
{
	std::string question;
	std::string answer;
	std::string tempPoints;
	std::string input = category;
	std::ifstream file;
	int points;

	file.open(input.c_str());

	if (file.fail())
		std::cerr << "error opening file " << std::endl;

	std::getline(file, input, '\n');

	while (!file.eof())
	{
		std::getline(file, question, ',');
		std::getline(file, answer, ',');
		std::getline(file, tempPoints, '\n');

		points = std::atol(tempPoints.c_str());

		Question placeHolder(question, answer, points);

		queue.push(placeHolder);
	}

	//Closes the input file
	file.close();
}
