#pragma once
#include <string>
#include "lcolor.h"
#include "terminal/ltsurface.h"

#ifdef SDL
#include <SDL.h>
#endif

class LImage{
	private:
#ifdef SDL
		SDL_Surface* surf;
#endif
		LTSurface* tsurf;
	public:
		LImage();
		LImage(const char* str); // path withowt ext
		LImage(const std::string& str); // path withowt ext
		LImage(const LImage& img);
		LImage(const LImage& img, const LColor& c);
		~LImage();
		void applyColors(const LColor& c);
		void applyColors(int hex);

#ifdef SDL
		SDL_Texture* newTexture(const LColor& c, SDL_Renderer* ren); // Special color (1, 1, 1)=>(c)
		SDL_Texture* newTexture(SDL_Renderer* ren);
		void pixelSet(int x, int y, Uint32 color);
		Uint32 pixelGet(int x, int y);
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

