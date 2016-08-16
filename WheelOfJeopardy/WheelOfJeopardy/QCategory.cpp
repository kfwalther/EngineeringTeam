
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
	//Parse->parseCategory(this->categoryQuestions, (csv + ".csv"));
	this->sectorName = Parse->parseCategory(this->categoryQuestions, (csv + ".csv"));
	this->sectorType = 1;		// 1 == QCategory, 2 == SCategory
	delete Parse;
}

void QCategory::Action(GameSession * session) {
	if (!(this->categoryQuestions.empty())) {
		// Push the Question content to the GameSession instance, accessible via the UserInterface.
		session->setCurrentQuestion(this->getQuestionInfo());
		this->categoryQuestions.pop();
	}
	else {
		std::cout << "QCategory::Action - Category Empty, rerolling\n";//testcode
		// TODO: tell the user that this category is empty, will automatically spin again
	}

}

Question QCategory::getQuestionInfo()
{
	// Make a copy of the current question and return it.
	Question currentQuestion = categoryQuestions.front();
	return currentQuestion;
}

std::string QCategory::getCategoryName()
{
	return sectorName;
}

