#pragma once
#include "building.h"
#include "resource.h"

class Mine:public Building{
	private:
		int strength;//сила добычи - сколько за раз
		ResourceType typ;
	public:
		Mine(Point p, Field* f, int lvl, ResourceType t);
		virtual void update();
		virtual bool upgrade();
		virtual std::pair<LImage*, LColor> getImage(Assets* ass) const;
		
};

