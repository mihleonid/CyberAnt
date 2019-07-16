#pragma once
#include "../lcolor.h"

class LTSurface{
	private:
		std::pair<char, LColor>* surf;
		int w;
		int h;
	public:
		LTSurface(const char* fullpath); // full path
		LTSurface(const LTSurface& a);
		LTSurface(const LTSurface& a, const LColor& c);
		LTSurface(int w, int h);
		LTSurface();
		~LTSurface();
		int getW() const;
		int getH() const;
		void set(int x, int y, char let, LColor c);
		void set(int x, int y, std::pair<char, LColor> c);
		std::pair<char, LColor> get(int x, int y) const;
		void applyColors(LColor c);
};

