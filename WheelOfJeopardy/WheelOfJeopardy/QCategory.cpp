
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
	this->getQuestionInfo().getQuestion();//incomplete, needs to be passed to UI so player one can see the question

}

Question QCategory::getQuestionInfo()
{
	Question Q = categoryQuestions.front();
	categoryQuestions.pop();
	return Q;
}

std::string QCategory::getCategoryName()
{
	return sectorName;
}

