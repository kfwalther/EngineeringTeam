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

std::string const parser::parseCategory(std::queue<Question> & queue, std::string const & category)
{
	std::string question;
	std::string answer;
	std::string tempPoints;
	std::string input = "categories/" + category;
	std::string categoryName;
	std::ifstream file;
	int points;

	file.open(input.c_str());

	if (file.fail())
		std::cerr << "error opening file " << std::endl;

	std::getline(file, categoryName, '\n');

	while (!file.eof())
	{
		std::getline(file, question, '\n');
		std::getline(file, answer, '\n');
		std::getline(file, tempPoints, '\n');

		points = std::atol(tempPoints.c_str());

		Question placeHolder(question, answer, points);

		queue.push(placeHolder);
	}

	//Closes the input file
	file.close();

	return categoryName;
}
