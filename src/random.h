#pragma once

class Random{
	private:
		static const int SIZE=2000; // Big value
		static const int CYCLES=20; // Smaller - better random, bigger - faster
		static int current;
		static int cyclesdone;
		static int rands[SIZE];
		static void recycle();
	public:
		static void init();
		static int rnd();
		static int rnd(int max); // From 1 to max
		static int rnd(int min, int max); // From min to max
};

