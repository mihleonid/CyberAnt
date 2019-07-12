#pragma once

class LMonoColor{
	private:
		int mr;
		int mg;
		int mb;
		bool eq(int a, int b, int eps) const;
	public:
		LMonoColor();
		LMonoColor(int c);
		LMonoColor(int c, bool hex);
		LMonoColor(int r, int g, int b);
		LMonoColor(const LMonoColor& c);

		int r() const;
		int g() const;
		int b() const;
		int hex() const;
		int t(bool back, int eps=40) const; // TODO eps is a param for color recognization. We need a better recognization.
};
