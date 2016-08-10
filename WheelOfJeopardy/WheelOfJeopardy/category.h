#pragma once

#include <queue>
#include "questions.h"

class category
{
public:
	category();
	void initialize(std::string csv);
	questions getQuestionInfo();
	std::string getCategoryName();
	~category();
private:
	std::queue<questions> categoryQuestions;
	std::string categoryName;
};

