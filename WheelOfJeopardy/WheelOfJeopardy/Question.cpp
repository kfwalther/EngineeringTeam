/**
* @file Question.cpp
* @brief This file contains the Question class definition.
* @author Edwin Flores
* @date 2016
*/
#include "Question.h"
#include <string>


Question::Question()
{
}

Question::Question(std::string const & question, std::string const & answer, int const points)
{
	questionContent = question;
	answerContent = answer;
	pointValue = points;
	// Initialize the timer for the question.
	// TODO: Check if this is the correct number of seconds...
	timer = 30;
	this->available = true;
}

/** Getter/setter methods. */
std::string Question::getAnswer(void)
{
	return answerContent;
}

std::string Question::getQuestion(void)
{
	return questionContent;
}

int Question::getPoints(void)
{
	return pointValue;
}

bool Question::getAvailable(void)
{
	return this->available;
}

void Question::setQuestion(std::string q)
{
	questionContent = q;
}

/** Functional methods. */
bool Question::checkAnswer(std::string const & playerAnswer)
{
	// TODO: Make this a little more robust, account for capitalizations, etc...
	if (playerAnswer == this->answerContent) {
		return true;
	} else {
		return false;
	}
}

