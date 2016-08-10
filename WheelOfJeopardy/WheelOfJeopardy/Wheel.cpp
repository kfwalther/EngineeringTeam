
/**
 * @file Wheel.cpp
 * @brief WoJ Wheel class.
 * @author Kevin Walther
 * @date 2016
 */

#include <iostream>

#include "Wheel.h"
#include "SCategory.h"


// Define the constructor and destructor.
Wheel::Wheel()
{
	this->wheelSize = 12;
	this->sectors = new Wheel::SectorVectorType;
	// Create the 12 wheel sectors.
	// TODO: Should the ordering of these be randomized?
	this->sectors->push_back(new QCategory("category1"));
	this->sectors->push_back(new QCategory("category2"));
	this->sectors->push_back(new QCategory("category3"));
	this->sectors->push_back(new QCategory("category4"));
	this->sectors->push_back(new QCategory("category5"));
	this->sectors->push_back(new QCategory("category6"));
	this->sectors->push_back(new SCategory("Bankrupt"));
	this->sectors->push_back(new SCategory("Lose Turn"));
	this->sectors->push_back(new SCategory("Free Turn"));
	this->sectors->push_back(new SCategory("Player Choice"));
	this->sectors->push_back(new SCategory("Opponent Choice"));
	this->sectors->push_back(new SCategory("Spin Again"));
}

Wheel::~Wheel()
{
}

// Define the Wheel object methods.
Sector const & Wheel::getSector(int const sectorIndex)
{
	if ((sectorIndex >= 0) && (sectorIndex < this->wheelSize)) {
		return *(sectors->at(sectorIndex));
	} else {
		std::cerr << "Invalid index provided." << std::endl;
		return *(sectors->at(0));
	}
}

Wheel::SectorVectorType const & Wheel::getSectors()
{
	return *(this->sectors);
}

int const Wheel::getSize() {
	return this->wheelSize;
}

//Wheel::StringVectorType const & Wheel::listCategories()
//{
//
//}


