#pragma once

#include <queue>
#include "Question.h"

class category
{
public:
	category();
	void initialize(std::string csv);
	Question getQuestionInfo();
	std::string getCategoryName();
	~category();
private:
	std::queue<Question> categoryQuestions;
	std::string categoryName;
};

