#pragma once

#ifdef SDL
#include <SDL.h>
#endif

#include "ldrawer.h"
#include "lscene.h"
#include "lcontrol.h"
#include "../eventqueue.h"
#include "../point.h"

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
		void setScene(LScene* scn);

		void draw(); // Отрисовка
		void clear();
		void present(); // Обновть картинку на экране (во избежание частичных отрисовок)
		std::pair<EventQueue, std::queue<LEvent*>> getEvents();
		Point getCenter();
		Point getCorner();
		LDrawer* getDrawer(); ///@deprecated
		LControl* getControl();
		~LWindow();

};

