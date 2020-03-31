#pragma once

#ifdef SDL
#include <SDL.h>
#endif

#include "ldrawer.h"
#include "lscene.h"
#include "lcontrol.h"
#include "../eventqueue.h"
#include "../point.h"

class LApp;

class LWindow{
	private:
		LApp* app=nullptr;
#ifdef SDL
		SDL_Window* win=nullptr;
#endif
		int tw=1024;
		int th=764;
		const char* wtitle;
		LDrawer* ldr;
		LScene* scene;
		LControl* cnt;
		int fps=26; // Это нужно будет при многопоточности
		void postResize();
	public:
		void init(LApp* a, bool text);
		int getFps();
		void setFps(int);

		LWindow(const char* title);
		LWindow();

		LScene* getScene();
		void setScene(LScene* scn);

		void draw(); // Отрисовка
		void clear(const LColor&);
		void clear();
		void present(); // Обновть картинку на экране (во избежание частичных отрисовок)
		std::pair<EventQueue, std::queue<LEvent*>> getEvents();
		Point getCenter();
		Point getCorner();
		LDrawer* getDrawer(); ///@deprecated
		LControl* getControl();

		int getH() const;
		int getW() const;
		LWindow* setH(int h);
		LWindow* setW(int w);

		~LWindow();

};
