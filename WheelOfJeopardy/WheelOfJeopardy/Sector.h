#pragma once

/**
 * @class Sector
 * @brief WoJ Sector object.
 * @author Kevin Walther
 * @date 2016
 * @ingroup WheelOfJeopardy
 */

#include <string>
struct GameSession;//forward declaration

enum class SectorType { CATEGORY, LOSE_TURN, FREE_TURN, BANKRUPT, PLAYER_CHOICE, OPP_CHOICE, SPIN_AGAIN };

struct Sector
{
	//Sector(std::string const sectorName);
	//virtual ~Sector();

	/** Functional methods. (Pure-virtual) */
	virtual void Action(GameSession *) = 0;
	virtual bool isEmpty() = 0;
	int const getType() {
		return sectorType;
	}

	std::string getSectorName()
	{
		return sectorName;
	}

	SectorType getSectorType()
	{
		return whlSectorType;
	}

protected:
	int sectorID;
	std::string sectorName;
	int sectorType;
	SectorType whlSectorType;
};

