#pragma once
#include <queue>
#include "Question.h"

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
	 * @param[in,out] queue A queue container housing Question objects.
	 */
	void parseCategory(std::queue<Question> & queue, std::string const & category);
};

