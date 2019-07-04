#pragma once
#include <SDL.h>
class FO;
#include "field.h"
#include "assets.h"
#include "point.h"
#include "foenum.h"

class FO{
	protected:
		FOType type;
		FOWhat what;
		Field* currField;
		Point pos;
		int order=-1; // Нужно для Field
	public:
		FOType getType() const;
		FOWhat getWhat() const;
		Field* getField();
		Point getPos() const;

		void setPos(Point p);

		FO(Point p, Field* currField);
		virtual ~FO();

		virtual void update();
		virtual SDL_Texture* getTexture(Assets* ass, SDL_Renderer* ren) const;

		friend class Field;
};

