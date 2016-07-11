#pragma once
#include <queue>
#include "questions.h"
class parser
{
public:
	parser();
	~parser();
	void parseCategory(std::queue<questions> &queue, std::string &category);
};

