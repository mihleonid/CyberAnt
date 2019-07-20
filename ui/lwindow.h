#pragma once

#ifdef SDL
#include <SDL.h>
#endif

#include "ldrawer.h"
#include "lscene.h"
#include "lcontrol.h"
#include "../eventqueue.h"

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
		LScene* scene;
		LControl* cnt;
	public:
		LWindow(const char* title, bool forceTerminal=false);

		LScene* getScene();

		void update(); // Наведение на кнопки м пр.
		void present(); // Обновть картинку на экране
		std::pair<EventQueue, std::queue<LEvent*>> getEvents();
		LDrawer* getDrawer(); ///@deprecated
		LControl* getControl();
		~LWindow();

};

