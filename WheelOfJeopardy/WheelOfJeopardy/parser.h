#pragma once
#include <queue>
#include "questions.h"

/**
 * @class parser
 * @brief WoJ Parser object.
 * @author Edwin Flores
 * @date 2016
 * @ingroup WheelOfJeopardy
 */
class parser
{
public:
	parser();
	~parser();

	/**
	 * @brief Parse and store the question information for the given category.
	 *
	 * @param[in] category A string indicating the category input file.
	 * @param[in,out] queue A queue container housing questions objects.
	 */
	void parseCategory(std::queue<questions> &queue, std::string &category);
};

