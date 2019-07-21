#pragma once
#include "ui/lcolor.h"
#include "fo.h"
#include "field.h"

class Building:public FO{ // Можно строить, имеет уровень
	protected:
		LColor levelColor() const; // Цвет уровня
		int level=0;
	public:
		int getLevel() const;
		virtual void upgrade();
		Building(Point p, Field* currF, int lvl);
};

