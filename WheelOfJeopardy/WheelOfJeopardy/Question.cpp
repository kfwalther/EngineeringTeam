/**
* @file Question.cpp
* @brief This file contains the Question class definition.
* @author Edwin Flores
* @date 2016
*/
#include "Question.h"
#include <string>
#include <iostream>//testcode
#include <algorithm>

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
	// Resonse: Assignment does not specificy
	timer = 10;
	this->available = true;
}


/** Getter/setter methods. */
std::string Question::getAnswer(void)
{
	return answerContent;
}

std::string Question::getQuestion(void)
{
	startTime = std::time(nullptr);
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
	double const elapsedTime = std::difftime(std::time(nullptr), this->startTime);
	if ((playerAnswer == this->answerContent) && (elapsedTime < this->timer)) {
		std::cout << "Correct! Time remaining was: " << std::max(0.0, (this->timer - elapsedTime)) << " seconds" << std::endl;//testcode
		return true;
	} else {
		std::cout << "Wrong! Correct answer was: " << this->answerContent << std::endl;//testcode
		this->pointValue *= -1;	//if answered incorrectly, point value is now negative
		return false;
	}
}

