
/**
 * @file Wheel.cpp
 * @brief WoJ Wheel class.
 * @author Kevin Walther
 * @date 2016
 */
#include <iostream>

#include "Wheel.h"
#include "SCategory.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


// Define the constructor and destructor.
Wheel::Wheel()
{
	this->wheelSize = 12;	//number of different sectors
	this->counter = 10; //number of wheel spins //testcode, switch to 50 for realcode
	this->sectors = new Wheel::SectorVectorType;	//Vector containing all sectors
	this->categories = new Wheel::StringVectorType;	//Vector containing the names of the sectors
	srand(static_cast<unsigned int>(std::time(NULL)));
	// Create the 12 wheel sectors
	//TODO use a for loop and Question
	this->sectors->push_back(new QCategory("category1", SectorType::CATEGORY));
	this->categories->push_back("category1");
	this->sectors->push_back(new QCategory("category2", SectorType::CATEGORY));
	this->categories->push_back("category2");
	this->sectors->push_back(new QCategory("category3", SectorType::CATEGORY));
	this->categories->push_back("category3");
	this->sectors->push_back(new QCategory("category4", SectorType::CATEGORY));
	this->categories->push_back("category4");
	this->sectors->push_back(new QCategory("category5", SectorType::CATEGORY));
	this->categories->push_back("category5");
	this->sectors->push_back(new QCategory("category6", SectorType::CATEGORY));
	this->categories->push_back("category6");
	this->sectors->push_back(new SCategory("Bankrupt", SectorType::BANKRUPT));
	this->sectors->push_back(new SCategory("Lose Turn", SectorType::LOSE_TURN));
	this->sectors->push_back(new SCategory("Free Turn", SectorType::FREE_TURN));
	this->sectors->push_back(new SCategory("Player Choice", SectorType::PLAYER_CHOICE));
	this->sectors->push_back(new SCategory("Opponent Choice", SectorType::OPP_CHOICE));
	this->sectors->push_back(new SCategory("Spin Again", SectorType::SPIN_AGAIN));
}

Wheel::~Wheel()
{
}

// Define the Wheel object methods.
Sector * const & Wheel::Spin(int const sectorIndex)
{
	//TODO only allow QSectors that still have valid questions be picked
	if ((sectorIndex >= 0) && (sectorIndex < this->wheelSize)) {//get nth sector where n=sectorIndex
		return (sectors->at(sectorIndex));
	} else {
		std::cerr << "Invalid index provided." << std::endl;
		return (sectors->at(0));//this should probably be null or something else
	}
}

Sector * const & Wheel::Spin()
{
	//TODO only allow QSectors that still have valid questions be picked
	//get random Sector
		int randomIndex;
		randomIndex = rand() % this->wheelSize;
		this->counter--;
		m_currentSector = sectors->at(randomIndex);
		return (m_currentSector);
}

Wheel::SectorVectorType const & Wheel::getSectors()
{
	return *(this->sectors);
}

//Checks the spin counter and if all QCategory Questions have been answered
bool const Wheel::isSpinnable() {

	bool noQuestions = true;

	// Iterate through the sectors and check if any QCategory is
	// empty. When there are no questions remaining noQuestions will
	// be set to true.
	for (std::vector<Sector *>::iterator iter = this->sectors->begin(); iter != this->sectors->begin(); ++iter) {
		if ((*iter)->getType() == 1) {
			noQuestions &= (*iter)->isEmpty();
		}
	}
	return ((!noQuestions) | (this->counter > 0));
}

int const Wheel::getSize() {
	return this->wheelSize;
}

//Returns a vector of strings containing the names of all categories
Wheel::StringVectorType const & Wheel::listCategories()
{
	return *(this->categories);
}


int Wheel::getSpinsLeft()
{
	return this->counter;
}