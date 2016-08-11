#pragma once

/**
 * @class QCategory
 * @brief WoJ QCategory object.
 * @author Edwin Flores
 * @date 2016
 * @ingroup WheelOfJeopardy
 */
#include <queue>
#include <iostream>
#include "Sector.h"
#include "Question.h"
#include <string>


class QCategory : public Sector
{
public:
	QCategory(std::string const & categoryName);
	void initialize(std::string const & csv);
	Question getQuestionInfo();
	std::string getCategoryName();
	~QCategory();

	/** Define the functions to override the virtual Sector methods. */
	void Action(GameSession * session) override;

	bool isEmpty() override {
		return this->categoryQuestions.empty();
	}

private:
	std::queue<Question> categoryQuestions;

};

