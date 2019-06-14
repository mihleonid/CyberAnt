#pragma once
#include "resource.h"
#include "assets.h"
#include "field.h"
#include "resourced.h"
#include "resourceset.h"
#include "storage.h"

class ResourceNode:public Resourced, public Storage, public FO{
	private:
		int add;
		int addPossible;
		int taxMin;
		int taxMax;
		ResourceType rtype;
	public:
		virtual void update();
		virtual SDL_Texture* getTexture(Assets* ass, SDL_Renderer* ren);
		ResourceNode(Point pos, Field* f, ResourceType type);
		bool empty();
		ResourceSet mine(ResourceSet need);
};

