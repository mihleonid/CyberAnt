#pragma once
#include "ui/limage.h"
#include <string>

class Assets{
	private:
		LImage field;
	public:
		Assets();
		~Assets();
		SDL_Surface* getNode(std::string str);

		getload(field);
		getload(base);
		getload(ironmine);

		SDL_Texture* getFieldTex();

		SDL_Texture* tex(SDL_Surface* s, SDL_Renderer* ren, int lvl);
		SDL_Texture* rtex(SDL_Surface* s, SDL_Renderer* ren, int contain);
};

