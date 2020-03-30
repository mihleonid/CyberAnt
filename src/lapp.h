#pragma once
#include <vector>
#ifdef SDL
#include <SDL.h>
#endif

class LWindow;

class LApp{
	private:
		bool text;
		std::vector<LWindow*> wins;
	public:
		LApp(bool useText);
		void addWindow(LWindw* win);
		~LApp();
};
