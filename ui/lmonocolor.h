#pragma once

class LMonoColor{
	private:
		int mr;
		int mg;
		int mb;
	public:
		LMonoColor();
		LMonoColor(int c);
		LMonoColor(int r, int g, int b);
		LMonoColor(const LMonoColor& c);

		int r() const;
		int g() const;
		int b() const;
		int t(bool back) const;
};

