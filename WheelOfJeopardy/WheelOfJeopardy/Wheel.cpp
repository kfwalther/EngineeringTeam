
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
	this->wheelSize = 12;
	this->sectors = new Wheel::SectorVectorType;
	this->categories = new Wheel::StringVectorType;
	// Create the 12 wheel sectors.
	// TODO: Should the ordering of these be randomized?
	this->sectors->push_back(new QCategory("category1"));
	this->categories->push_back("category1");
	this->sectors->push_back(new QCategory("category2"));
	this->categories->push_back("category2");
	this->sectors->push_back(new QCategory("category3"));
	this->categories->push_back("category3");
	this->sectors->push_back(new QCategory("category4"));
	this->categories->push_back("category4");
	this->sectors->push_back(new QCategory("category5"));
	this->categories->push_back("category5");
	this->sectors->push_back(new QCategory("category6"));
	this->categories->push_back("category6");
	this->sectors->push_back(new SCategory("Bankrupt"));
	this->categories->push_back("Bankrupt");
	this->sectors->push_back(new SCategory("Lose Turn"));
	this->categories->push_back("Lose Turn");
	this->sectors->push_back(new SCategory("Free Turn"));
	this->categories->push_back("Free Turn");
	this->sectors->push_back(new SCategory("Player Choice"));
	this->categories->push_back("Player Choice");
	this->sectors->push_back(new SCategory("Opponent Choice"));
	this->categories->push_back("Opponent Choice");
	this->sectors->push_back(new SCategory("Spin Again"));
	this->categories->push_back("Spin Again");
}

Wheel::~Wheel()
{
}

// Define the Wheel object methods.
Sector * const & Wheel::getSector(int const sectorIndex)
{
	if ((sectorIndex >= 0) && (sectorIndex < this->wheelSize)) {
		return (sectors->at(sectorIndex));
	} else if(sectorIndex==-1) {//get random Sector
		 srand (time(NULL));
		 int randomIndex;
		 randomIndex = rand() % this->wheelSize;
		return (sectors->at(randomIndex));
	} else {
		std::cerr << "Invalid index provided." << std::endl;
		return (sectors->at(0));
	}
}

Wheel::SectorVectorType const & Wheel::getSectors()
{
	return *(this->sectors);
}

int const Wheel::getSize() {
	return this->wheelSize;
}

Wheel::StringVectorType const & Wheel::listCategories()
{
		return *(this->categories);
}


