
/**
 * @file QCategory.cpp
 * @brief This file contains the QCategory class definition.
 * @author Edwin Flores
 * @date 2016
 */
#include "QCategory.h"
#include "parser.h"
#include "Question.h"
#include "Player.h"


QCategory::QCategory(std::string const & categoryName)
{
	this->initialize(categoryName + ".csv");
}

QCategory::~QCategory()
{
}

void QCategory::initialize(std::string const & csv)
{
	parser * Parse = new parser();
	Parse->parseCategory(this->categoryQuestions, csv);
	this->sectorName = csv;
	this->sectorType = 1;		// 1 == QCategory, 2 == SCategory
	delete Parse;
}

void QCategory::Action(GameSession * session) {
	std::cout << "Spins remaining: " << session->getGameRoom()->getWheel()->getSize() << std::endl;//testcode
	std::cout << "Player " << session->getPlayers().front()->getName() << " landed On:" << sectorName << std::endl;//testcode
	if (!(this->categoryQuestions.empty())) {
		//this->getQuestionInfo();
		std::cout << this->getQuestionInfo().getQuestion() << std::endl;//testcode  //incomplete, needs to be passed to UI so player one can see the question
		std::string response;
		std::getline(std::cin, response);

		int score;
		if (this->getQuestionInfo().checkAnswer(response)) {
			score = this->getQuestionInfo().getPoints();
			session->getPlayers().front()->changeScore(score);
		}
		else {
			score = -1 * this->getQuestionInfo().getPoints();
			session->getPlayers().front()->changeScore(score);
			session->changeTurns();
		}
		this->categoryQuestions.pop();

	}
	else {
		std::cout << "Category Empty, rerolling\n";//testcode
		//tell the user that this category is empty, will automatically spin again
	}

}

Question QCategory::getQuestionInfo()
{
	Question Q = categoryQuestions.front();
	return Q;
}

std::string QCategory::getCategoryName()
{
	return sectorName;
}

