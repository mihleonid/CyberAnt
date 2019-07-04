#pragma once
#include "lmonocolor.h"

class LColor{
	private:
		LMonoColor f;
		LMonoColor b;
	public:
		LColor();
		LColor(const LMonoColor& fc, const LMonoColor& bc);
		LColor(const LMonoColor& a);
		LColor(const LColor& a);
		LColor(int r, int g, int b);

		LMonoColor fg() const;
		LMonoColor bg() const;
		void def();
};

