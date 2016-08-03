#pragma once

/**
 * @class QCategory
 * @brief WoJ QCategory object.
 * @author Edwin Flores
 * @date 2016
 * @ingroup WheelOfJeopardy
 */
#include <queue>
#include "Sector.h"
#include "Question.h"

class QCategory : public Sector
{
public:
	QCategory();
	void initialize(std::string csv);
	Question getQuestionInfo();
	std::string getCategoryName();
	~QCategory();

	/** Define the functions to override the virtual Sector methods. */
	void Action() override {
		// TODO: How will Action return type be compatible with QCategory and SCategory actions?
		//this->getQuestionInfo();
	}

	bool isEmpty() override {
		return this->categoryQuestions.empty();
	}

private:
	std::queue<Question> categoryQuestions;

};

