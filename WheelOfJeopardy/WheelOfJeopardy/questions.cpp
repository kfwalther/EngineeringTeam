#include "questions.h"
#include <string>

questions::questions(std::string q, std::string a, int p)
{
	question = q;
	answer = a;
	points = p;
}

std::string questions::getAnswer(void)
{
	return answer;
}

std::string questions::getQuestion(void)
{
	return question;
}

int questions::getPoints(void)
{
	return points;
}

questions::questions()
{
}

void questions::setQuestion(std::string q)
{
	question = q;
}

