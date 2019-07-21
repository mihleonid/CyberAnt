#pragma once
#include <string>
#include <map>
#include "lcolor.h"
#include "terminal/ltsurface.h"

#ifdef SDL
#include <SDL.h>
#endif

class LImage{
	private:
#ifdef SDL
		SDL_Surface* surf;
		std::map<LColor, SDL_Texture*> sdlcache;
#endif
		LTSurface* tsurf;
	public:
		LImage();
		LImage(const char* str); // path withowt ext
		LImage(const std::string& str); // path withowt ext
		LImage(LImage* img);
		LImage(LImage* img, const LColor& c);
		~LImage();
		LImage* applyColors(const LColor& c); // this
		LImage* applyColors(int hex);

#ifdef SDL
		SDL_Texture* newTexture(const LColor& c, SDL_Renderer* ren); // Special color (1, 1, 1)=>(c)
		SDL_Texture* newTexture(SDL_Renderer* ren);
		void pixelSet(int x, int y, Uint32 colorr, SDL_Surface* s);
		Uint32 pixelGet(int x, int yr, SDL_Surface* s);
		SDL_Surface* getSurface();
		void applySDL(const LColor& c); // Special color (1, 1, 1)=>(c)
#endif
		LTSurface newTSurface(const LColor& c); // Special color (^S)=>(c)
		void letterSet(int x, int y, char let, LColor c);
		void letterSet(int x, int y, std::pair<char, LColor> c);
		std::pair<char, LColor> letterGet(int x, int y) const;
		const LTSurface& getTSurface();
		void applyT(const LColor& c); // Special color (^S)=>(c)
};

