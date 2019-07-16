#pragma once
#include "ui/lcolor.h"
#include "fo.h"
#include "field.h"

class Building:public FO{ // Можно строить, имеет уровень
	protected:
		LColor levelColor() const; // Цвет уровня
	public:
		int level=0;
		Building(Point p, Field* currF, int lvl);
};

