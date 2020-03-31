#pragma once

#include <set>
#ifdef SDL
#include <SDL.h>
#endif

class LWindow;

class LApp{
	private:
		bool text;
		std::set<LWindow*> wins;
	public:
		LApp(bool useText=false);
		LApp* addWindow(LWindow* win);
		LApp* eraseWindow(LWindow* win);
		bool isTerm() const;
		~LApp();
};
