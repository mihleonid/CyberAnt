#pragma once
#include <SDL.h>
#include "view.h"
#include "eventqueue.h"
#include "assets.h"
#include "ui/lui.h"


class FieldView:public View{
	private:
		/*
		std::pair<int, int> draw(int x, int y, SDL_Texture* tex);
		std::pair<int, int> drawText(int x, int y, int text);
		std::pair<int, int> drawText(int x, int y, const char* text);
		std::pair<int, int> drawRight(int x, int y, SDL_Texture* tex);
		std::pair<int, int> drawTextRight(int x, int y, int text);
		std::pair<int, int> drawTextRight(int x, int y, const char* text);
		*/
		int scrollX;
		int scrollY;
		bool mouseDown;
		bool mouseMoved;
		int mouseX;
		int mouseY;
		LWindow* win=nullptr;
		Assets* ass=nullptr;
	public:
		virtual void loop(const Model* m);
		virtual EventQueue getEvents();
		virtual void init();
		~FieldView();
};

