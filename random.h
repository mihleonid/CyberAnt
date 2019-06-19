#pragma once

class Random{
	public:
		static void init();
		static int rnd();
		static int rnd(int max); // From 1 to max
		static int rnd(int min, int max); // From min to max
};

