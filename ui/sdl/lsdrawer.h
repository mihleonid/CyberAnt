#pragma once
#include <SDL.h>
#include "../ldrawer.h"
#include "../../point.h"

class LSDrawer:public LDrawer{
	private:
		SDL_Texture* makeText(SDL_Renderer* ren, const char* c);
		SDL_Renderer* ren=nullptr;

		LColor col;
	public:
		Rect draw(int x, int y, SDL_Texture* tex);//TODO Limage
		Rect drawRight(int x, int y, SDL_Texture* tex);
		Rect drawCenter(int x, int y, SDL_Texture* tex);
		LSDrawer(SDL_Renderer* r);
		~LSDrawer();

		virtual Rect drawText(int x, int y, int text);
		virtual Rect drawText(int x, int y, const char* text);

		virtual Rect drawTextRight(int x, int y, int text);
		virtual Rect drawTextRight(int x, int y, const char* text);

		virtual Rect drawTextCenter(int x, int y, const char* text);
		virtual Rect drawTextCenter(int x, int y, int text);

		virtual void clear();
		virtual void present();

		virtual void color(LColor c);
		virtual void color();
};

