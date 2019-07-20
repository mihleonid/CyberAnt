#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "../ldrawer.h"
#include "../limage.h"
#include "../../point.h"

class LSDrawer:public LDrawer{
	private:
		SDL_Texture* makeText(SDL_Renderer* ren, const char* c);
		SDL_Renderer* ren=nullptr;
		TTF_Font* font;

		LColor col;
	public:
		virtual Rect draw(int x, int y, LImage* img);

		Rect draw(int x, int y, SDL_Texture* tex);//destroys texture
		Rect drawRight(int x, int y, SDL_Texture* tex);
		Rect drawCenter(int x, int y, SDL_Texture* tex);
		LSDrawer(SDL_Renderer* r);
		virtual ~LSDrawer();

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

