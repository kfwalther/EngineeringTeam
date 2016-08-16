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
bool Question::checkAnswer(std::string & playerAnswer)
{
	double const elapsedTime = std::difftime(std::time(nullptr), this->startTime);
	// Make answers to compare all lowercase.
	std::string correctAnswer = this->answerContent;
	std::transform(playerAnswer.begin(), playerAnswer.end(), playerAnswer.begin(), ::tolower);
	std::transform(correctAnswer.begin(), correctAnswer.end(), correctAnswer.begin(), ::tolower);
	// Compare the player answer against the correct answer, and check time.
    if (elapsedTime > this->timer) {
		// TODO: Make these cout statements calls to UI class.
		std::cout << "<<< Elapsed time was: " << elapsedTime << " seconds";// << std::endl;
		this->pointValue *= -1;	//if answered incorrectly, point value is now negative
		return false;
	}
	else if (playerAnswer != correctAnswer) {
		// TODO: Make these cout statements calls to UI class.
		std::cout << "<<< Correct answer was: " << this->answerContent;// << std::endl;
		this->pointValue *= -1;	//if answered incorrectly, point value is now negative
		return false;
	} else {
		// TODO: Make these cout statements calls to UI class.
		std::cout << "<<< Time remaining was: " << std::max(0.0, (this->timer - elapsedTime)) << " seconds";// << std::endl;//testcode
		return true;
	}
}


double Question::getTime()
{
	double const elapsedTime = std::difftime(std::time(nullptr), this->startTime);
	return std::max(0.0, (this->timer - elapsedTime));
}