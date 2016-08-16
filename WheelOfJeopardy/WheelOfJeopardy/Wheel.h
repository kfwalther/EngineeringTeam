#pragma once

/**
 * @class Wheel
 * @brief WoJ Wheel object.
 * @author Kevin Walther
 * @date 2016
 * @ingroup WheelOfJeopardy
 */

#include <string>
#include <vector>

#include "Sector.h"

// Forward declaration
struct GameRoom;

struct Wheel
{
	// Alias the vector of strings type.
	typedef std::vector<std::string> StringVectorType;
	// Alias the vector of Sector objects type.
	typedef std::vector<Sector *> SectorVectorType;

	// Define the constructor and destructor.
	Wheel(std::string const & inputFileName);
	~Wheel();

	// Define the Wheel object methods.
	Sector * const & Spin(int const sectorIndex); //Spin Specific Sector
	Sector * const & Spin();//Spin Random Sector
	Wheel::SectorVectorType const & getSectors();
	int const getSize();
	Wheel::StringVectorType const & listCategories();
	bool const isSpinnable();
	int getSpinsLeft();
	Sector* getCurrentSector()
	{
		return m_currentSector;
	}
private:
	int wheelID;
	int counter;
	int wheelSize;
	SectorVectorType * sectors;
	StringVectorType * categories;
	Sector * m_currentSector;
	// Still need to define WheelFrame class.
	//WheelFrame * wheelFrame; 
};

