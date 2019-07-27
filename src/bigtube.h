#pragma once
#include <vector>
#include "tubed.h"
#include "building.h"
#include "tubed.h"
#include "foenum.h"

class BigTube:public Tubed, public Building{
	private:
		std::vector<TO*> tos;
	public:
		virtual void update();
		virtual std::pair<LImage*, LColor> getImage(Assets* ass) const;
		BigTube(Point p, Field* f, int lvl);
		virtual void send(TO* give);
};

