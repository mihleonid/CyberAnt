#pragma once
#include "fo.h"
#include "field.h"

class Building:public FO{//можно строить, имеет уровень
	public:
		int level=0;
		Building(Point p, Field* currF, int lvl);
};

