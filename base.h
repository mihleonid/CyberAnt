#pragma once
#include "building.h"
#include "resourced.h"
#include "putable.h"
#include "storage.h"

class Base:public Building, public Storage, public Resourced, public Putable{
	public:
		virtual void update();
		virtual LImage* getImage(Assets* ass) const;
		Base(Point p, Field* f, int lvl);
		bool empty() const;
		void put(ResourceSet g);
		ResourceSet mine(ResourceSet need);
};

