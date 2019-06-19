#include <cstddef>
#include <cassert>
#include <iostream>
#include "assets.h"
#include "common.hpp"

Assets::Assets(SDL_Renderer* ren) {
	loadfield();
	loadbase();
	loadiron();
	loadironmine();

	assert(field != nullptr);
	assert(base!=nullptr);
	assert(iron!=nullptr);
	assert(ironmine!=nullptr);

	fieldtex = tex(getfield(), ren, 0);
	font = TTF_OpenFont("assets/ubuntumono.ttf", 21);
}
Assets::~Assets(){
	SDL_FreeSurface(field);
	SDL_FreeSurface(base);
	SDL_FreeSurface(iron);

	SDL_DestroyTexture(fieldtex);
	TTF_CloseFont(font);
}

SDL_Surface* Assets::getNode(std::string type){
	return SDL_LoadBMP(("./assets/"+type+"node.bmp").c_str());
}

SDL_Texture* Assets::tex(SDL_Surface* surface, SDL_Renderer* ren, int lvl) {
	SDL_Surface* s = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA32, SDL_SWSURFACE);
	SDL_LockSurface(s);
	for (int x = 0; x < s->w; x++) {
		for (int y = 0; y < s->h; y++) {
			Uint32 color = pixelget(x, y, s);
			if ((color&0xFFFFFF) == 0x010101) {
				pixelset(x, y, (0x000000 | ((15 * lvl)*0x00010000)), s);
				//min 0xFF000000 max (17*15*0x00010000=255*0x00010000=0xFF*0x00010000=0x00FF0000)|0xFF000000=0xFFFF0000
			}
		}
	}
	SDL_UnlockSurface(s);
	SDL_Texture *t = SDL_CreateTextureFromSurface(ren, s);
	SDL_FreeSurface(s);
	if (t == nullptr) {
		std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
	}
	return t;
}
SDL_Texture* Assets::rtex(SDL_Surface* surface, SDL_Renderer* ren, int contain) {
	SDL_Surface* s = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA32, SDL_SWSURFACE);
	SDL_LockSurface(s);
	for (int x = 0; x < s->w; x++) {
		for (int y = 0; y < s->h; y++) {
			Uint32 color = pixelget(x, y, s);
			if ((color&0xFFFFFF) == 0x010101) {
				pixelset(x, y, (0x000000 | ((contain/4)*0x00000102)), s);
				//min 0xFF000000 max (17*15*0x00010000=255*0x00010000=0xFF*0x00010000=0x00FF0000)|0xFF000000=0xFFFF0000
			}
		}
	}
	SDL_UnlockSurface(s);
	SDL_Texture *t = SDL_CreateTextureFromSurface(ren, s);
	SDL_FreeSurface(s);
	if (t == nullptr) {
		std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
	}
	return t;
}

Uint32 Assets::pixelget(int x, int y, SDL_Surface* surface){
	Uint32 *pixels = (Uint32*)surface->pixels;
	return pixels[( y * surface->w ) + x];
}
void Assets::pixelset(int x, int y, Uint32 color, SDL_Surface* surface){
	Uint32 *pixels = (Uint32 *)surface->pixels;
	pixels[( y * surface->w ) + x] = SDL_MapRGB(surface->format, (color&0xFF0000)/0x10000, (color&0xFF00)/0x100, color&0xFF);
}

SDL_Texture* Assets::getFieldTex() {
	return fieldtex;
}
SDL_Texture* Assets::makeText(SDL_Renderer* ren, const char* c){
	SDL_Color white={255, 255, 255};
	SDL_Surface* surfaceMessage=TTF_RenderText_Solid(font, c, white);
	SDL_Texture* message=SDL_CreateTextureFromSurface(ren, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
	return message;
}
