#pragma once
class FO;
#include "field.h"
#include "assets.h"
#include "point.h"
#include "foenum.h"

class FO{
	private:
		FOType type;
		FOWhat what;
		Field* currField;
		Point pos;
		int order=-1; // Нужно для Field
	public:
		FOType getType();
		FOWhat getWhat();
		Field* getField();
		Point getPos();
		void setPos(Point p);

		FO(Point p, Field* currField);
		virtual void update();
		virtual SDL_Texture* getTexture(Assets* ass, SDL_Renderer* ren);

		friend class Field;
};
