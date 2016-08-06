
/**
 * @file Wheel.cpp
 * @brief WoJ Wheel class.
 * @author Kevin Walther
 * @date 2016
 */

#include "Wheel.h"
#include "SCategory.h"


// Define the constructor and destructor.
Wheel::Wheel()
{
	this->wheelSize = 12;
	this->sectors = new Wheel::SectorVectorType;
	this->sectors->push_back(new SCategory(2, "Bankrupt"));
	this->sectors->push_back(new SCategory(2, "Lose Turn"));
	this->sectors->push_back(new SCategory(2, "Free Turn"));
	this->sectors->push_back(new SCategory(2, "Player Choice"));
	this->sectors->push_back(new SCategory(2, "Opponent Choice"));
	this->sectors->push_back(new SCategory(2, "Spin Again"));
	// TODO: Instantiate the QCategory classes next...
}

Wheel::~Wheel()
{
}

// Define the Wheel object methods.
//Sector const & Wheel::getSector(int const sectorIndex)
//{
//
//}
//
//Wheel::StringVectorType const & Wheel::listCategories()
//{
//
//}


