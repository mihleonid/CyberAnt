#pragma once
#include "fo.h"

class StandingEnemy:public FO{
	public:
		StandingEnemy(Point, Field*);
		virtual void update();
		virtual std::pair<LImage*, LColor> getImage(Assets* ass) const;
};

