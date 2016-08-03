#pragma once

/**
 * @class Sector
 * @brief WoJ Sector object.
 * @author Kevin Walther
 * @date 2016
 * @ingroup WheelOfJeopardy
 */

#include <string>

class Sector
{
public:
	//Sector();
	//virtual ~Sector();

	/** Functional methods. (Pure-virtual) */
	virtual void Action() = 0;
	virtual bool isEmpty() = 0;
	//virtual std::string toString() = 0;

protected:
	int sectorID;
	std::string sectorName;
	int sectorType;
};

