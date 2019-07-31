#pragma once
#include "building.h"

class Gun:public Building{
	private:
		int strength;
	public:
		Gun(Point, Field*, int lvl);
		virtual void update();
		virtual std::pair<LImage*, LColor> getImage(Assets* ass) const;
};

