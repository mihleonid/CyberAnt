#pragma once
#include "assets.h"
#include "field.h"
#include "resourced.h"
#include "resource.h"
#include "resourceset.h"
#include "storage.h"

class ResourceNode:public Resourced, public Storage{
	private:
		int add;
		int addPossible;
		int taxMin;
		int taxMax;
		ResourceType rtype;
	public:
		virtual void update();
		virtual SDL_Texture* getTexture(Assets* ass, SDL_Renderer* ren);
		ResourceNode(int xx, int yy, Field* f, ResorceType type);
		bool empty();
		ResourceSet mine(ResourceSet need);
};

