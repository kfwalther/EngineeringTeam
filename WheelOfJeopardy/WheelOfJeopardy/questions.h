#pragma once
#include <string>
class questions
{
public:
	questions(std::string q, std::string a, int p);
	std::string getAnswer(void);
	std::string getQuestion(void);
	int getPoints(void);
	questions();

	void setQuestion(std::string q);

private:
	std::string question;
	std::string answer;
	int points;
};

