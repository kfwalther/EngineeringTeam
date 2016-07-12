#include "WoJ.h"
#include "category.h"
#include <iostream>

WoJ::WoJ()
{
	category1.initialize(category1_csv);
	category2.initialize(category2_csv);
	category3.initialize(category3_csv);
	category4.initialize(category4_csv);
	category5.initialize(category5_csv);
	category6.initialize(category6_csv);
}


WoJ::~WoJ()
{
}
