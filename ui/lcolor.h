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
		// Constructors for fg
		LColor(int r, int g, int b);
		LColor(int c);
		LColor(int c, bool hex);
		// Constructors for bg
		LColor(bool, int r, int g, int b);
		LColor(bool, int c);
		LColor(bool, int c, bool hex);

		LMonoColor fg() const;
		LMonoColor bg() const;

		void setFg(const LMonoColor& c);
		void setBg(const LMonoColor& c);
		void setFg(char c);
		void setBg(char c);

		void def();
};
bool operator==(const LColor& a, const LColor& b);
bool operator<(const LColor& a, const LColor& b);
bool operator>(const LColor& a, const LColor& b);
bool operator<=(const LColor& a, const LColor& b);
bool operator>=(const LColor& a, const LColor& b);
bool operator!=(const LColor& a, const LColor& b);

