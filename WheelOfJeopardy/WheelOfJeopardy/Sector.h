#pragma once

/**
 * @class Sector
 * @brief WoJ Sector object.
 * @author Kevin Walther
 * @date 2016
 * @ingroup WheelOfJeopardy
 */

#include <string>

struct Sector
{
	//Sector(std::string const sectorName);
	//virtual ~Sector();

	/** Functional methods. (Pure-virtual) */
	virtual void Action() = 0;
	virtual bool isEmpty() = 0;
	//virtual std::string toString() = 0;
	int const getType() {
		return sectorType;
	}
protected:
	int sectorID;
	std::string sectorName;
	int sectorType;
};

