#include "category.h"
#include "parser.h"
#include "Question.h"

category::category()
{
}

void category::initialize(std::string csv)
{
	parser Parse;
	Parse.parseCategory(categoryQuestions, csv);
	categoryName = csv;
	Parse.~parser();
}

Question category::getQuestionInfo()
{
	Question Q = categoryQuestions.front();
	categoryQuestions.pop();
	return Q;
}

std::string category::getCategoryName()
{
	return categoryName;
}

category::~category()
{
}
