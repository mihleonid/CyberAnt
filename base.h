#pragma once
#include "resource.h"
#include "assets.h"
#include "building.h"
#include "field.h"
#include "putable.h"
#include "resourced.h"
#include "resourceset.h"
#include "storage.h"

class Base:public Building, public Storage, public Resourced, public Putable{
	public:
		virtual void update();
		virtual SDL_Texture* getTexture(Assets* ass, SDL_Renderer* ren);
		Base(int xx, int yy, Field* f, int lvl);
		bool empty();
		void put(ResourceSet g);
		ResourceSet mine(ResourceSet need);
};

