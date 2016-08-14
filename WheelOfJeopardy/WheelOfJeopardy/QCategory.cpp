
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


QCategory::QCategory(std::string const & categoryName, SectorType sectorTypeIn)
{
	this->initialize(categoryName);
	this->whlSectorType = sectorTypeIn;
}

QCategory::~QCategory()
{
}

void QCategory::initialize(std::string const & csv)
{
	parser * Parse = new parser();
	Parse->parseCategory(this->categoryQuestions, (csv + ".csv"));
	this->sectorName = csv;
	this->sectorType = 1;		// 1 == QCategory, 2 == SCategory
	delete Parse;
}

void QCategory::Action(GameSession * session) {
	//std::cout << "Spins remaining: " << session->getGameRoom()->getWheel()->getSpinsLeft() << std::endl;//testcode
	//std::cout << "Player " << session->getPlayers().front()->getName() << " landed On:" << sectorName << std::endl;//testcode
	if (!(this->categoryQuestions.empty())) {
		// Provide the Question content to the user.
		// TODO: Using the UI_PlaceHolder function here, but can probably rename this UI function.
		//session->getUserInterfaceHandle()->UI_PlaceHolder("QCategory::Action - Question: " + this->getQuestionInfo().getQuestion());
		std::string response = "";
		
		//std::cout << "QCategory::Action - Answer: ";
		//std::cin.ignore();
		//std::getline(std::cin, response);

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
		std::cout << "QCategory::Action - Category Empty, rerolling\n";//testcode
		//tell the user that this category is empty, will automatically spin again
	}

}

Question & QCategory::getQuestionInfo()
{
	return categoryQuestions.front();
}

std::string QCategory::getCategoryName()
{
	return sectorName;
}

