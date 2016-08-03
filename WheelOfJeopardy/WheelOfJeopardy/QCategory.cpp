
/**
 * @file QCategory.cpp
 * @brief This file contains the QCategory class definition.
 * @author Edwin Flores
 * @date 2016
 */
#include "QCategory.h"
#include "parser.h"
#include "Question.h"


QCategory::QCategory()
{
}

QCategory::~QCategory()
{
}

void QCategory::initialize(std::string csv)
{
	parser Parse;
	Parse.parseCategory(categoryQuestions, csv);
	sectorName = csv;
	sectorType = 1;		// 1 == QCategory, 2 == SCategory
	Parse.~parser();
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

