#pragma once

/**
 * @class GameBoard
 * @brief WoJ GameBoard object.
 * @author Kevin Walther
 * @date 2016
 * @ingroup WheelOfJeopardy
 */

#include <vector>

#include "QCategory.h"
//#include "BoardFrame.h"

struct GameBoard
{
	// Alias the QCategory vector type.
	typedef std::vector<QCategory *> QCategoryVectorType;

	// Define the constructor and destructor.
	GameBoard(QCategoryVectorType & qCategories);
	~GameBoard();

	// Define the GameBoard object methods.
	void displayQuestion();		
private:
	QCategoryVectorType * qCategoryVector;
	// Still need to define the BoardFrame class.
	//BoardFrame * boardFrameHandle;
};

