#pragma once
#include <SDL.h>
#include <string>

class LImage{
	private:
		SDL_Surface* surf;
		//TODO LTSurface* tsurf;
	public:
		LImage();
		LImage(const char* str); // path withowt ext
		LImage(const std::string& str); // path withowt ext
		LImage(const LImage& img);
		LImage(const LImage& img, const LColor& c); // TODO copy with preobr
		~Limage();

		//SDL
		SDL_Texture* newTexture(const LColor& c, SDL_Renderer* ren); // Special color (1, 1, 1)=>(c)
		SDL_Texture* newTexture(SDL_Renderer* ren);
		void pixelSet(int x, int y, Uint32 color);
		Uint32 pixelGet(int x, int y);
		SDL_Surface* getSurface();
		//Term
		//LTSurface newTSurface(const LColor& c); // Special color (^S)=>(c)
		//void letterSet(int x, int y, char let, LColor c);
		//std::pair<char, LColor> letterGet(int x, int y);
		//const LTSurface& getTSurface();
};

