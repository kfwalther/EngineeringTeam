#pragma once

/**
 * @class Sector
 * @brief WoJ Sector object.
 * @author Kevin Walther
 * @date 2016
 * @ingroup WheelOfJeopardy
 */

#include <string>
struct Player;//{void setScore(int x){}}; //forward declaration

struct Sector
{
	//Sector(std::string const sectorName);
	//virtual ~Sector();

	/** Functional methods. (Pure-virtual) */
	virtual void Action(Player *) = 0;
	virtual std::string Action() = 0;//workaround int return type
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

