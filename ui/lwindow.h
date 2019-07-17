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
		void add();//TODO add component
		void update(); // Наведение на кнопки м пр.
		void present(); // Обновть картинку на экране
		LDrawer* getDrawer(); ///@deprecated
		~LWindow();

};

