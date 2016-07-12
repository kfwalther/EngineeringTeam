#pragma once
#include "category.h"

class WoJ
{
public:
	WoJ();
	~WoJ();

private:
	category category1;
	category category2;
	category category3;
	category category4;
	category category5;
	category category6;
	std::string category1_csv = "category1.csv";
	std::string category2_csv = "category2.csv";
	std::string category3_csv = "category3.csv";
	std::string category4_csv = "category4.csv";
	std::string category5_csv = "category5.csv";
	std::string category6_csv = "category6.csv";
};

