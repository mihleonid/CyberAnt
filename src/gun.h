#pragma once
#include "building.h"
#include "putable.h"

class Gun:public Building, public Putable{ // Зарежается железом.
	private:
		int strength;
		int iron;
		int cost;
	public:
		Gun(Point, Field*, int lvl);
		virtual void update();
		virtual bool upgrade();
		virtual std::pair<LImage*, LColor> getImage(Assets* ass) const;
		virtual void put(ResourceSet give);
};

