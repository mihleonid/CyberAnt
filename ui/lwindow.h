#pragma once

#ifdef SDL
#include <SDL.h>
#endif

#include "ldrawer.h"

#define SCREEN_W 1024
#define SCREEN_H 764

class LWindow{
	private:
		bool sdlMode;
#ifdef SDL
		SDL_Window* win=nullptr;
#endif
		int tw;
		int th;
		const char* wtitle;
		LDrawer* ldr;
	public:
		LWindow(const char* title, bool forceTerminal=false);
		void add();
		void update();
		~LWindow();

};

