#pragma once
#include "ldrawer.h"

#define SCREEN_W 1024
#define SCREEN_H 764

class LWindow{
	private:
		bool sdlMode;
		SDL_Window* win=nullptr;
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

