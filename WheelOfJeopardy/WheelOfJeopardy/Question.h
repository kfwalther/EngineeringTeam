#pragma once
#include <string>
#include <ctime>

/**
 * @class Question
 * @brief WoJ Question object.
 * @author Edwin Flores
 * @date 2016
 * @ingroup WheelOfJeopardy
 */
class Question
{
public:
	Question();
	Question(std::string const & question, std::string const & answer, int const points);

	/** Getter/setter methods. */
	std::string getAnswer(void);
	std::string getQuestion(void);
	int getPoints(void);
	bool getAvailable(void);
	void setQuestion(std::string q);

	/** Functional methods. */
	bool checkAnswer(std::string const & playerAnswer);
private:

	/** Define the Question class attributes. */
	std::string questionContent;
	std::string answerContent;
	std::time_t startTime;
	int pointValue;
	int timer;
	bool available;
};

