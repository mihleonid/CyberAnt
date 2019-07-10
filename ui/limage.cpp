#include "limage.h"

LImage::Limage(){
	surf=nullptr;
	//tsurf=nullptr;
}
LImage::LImage(const char* str){
	surf=SDL_LoadBMP((std::string("./assets/")+std::string(str)+std::string(".bmp")).c_str());
	//tsurf=new LTSurface((std::string("./assets/")+std::string(str)+std::string(".txt")).c_str());
}
LImage::LImage(const std::string& str){
	surf=SDL_LoadBMP((std::string("./assets/")+str+std::string(".bmp")).c_str());
	//tsurf=new LTSurface((std::string("./assets/")+str+std::string(".txt")).c_str());
}
LImage::Limage(const LImage& img){
	SDL_Surface* surf=SDL_ConvertSurfaceFormat(img.surf, SDL_PIXELFORMAT_RGBA32, SDL_SWSURFACE);
	//tsurf=img.tsurf;
}
LImage::~LImage(){
	if(surf!=nullptr){
		delete surf;
	}
	/*
	if(tsurf!=nullptr){
		delete tsurf;
	}
	*/
}

SDL_Texture* LImage::newTexture(const LColor& c, SDL_Renderer* ren) {
	if(surf==nullptr){
		std::cerr<<"LImage is not initialized"<<std::endl;
		return nullptr;
	}
	SDL_Surface* s=SDL_ConvertSurfaceFormat(surf, SDL_PIXELFORMAT_RGBA32, SDL_SWSURFACE);
	SDL_LockSurface(s);
	for(int x=0;x<s->w;x++){
		for(int y=0;y<s->h;y++){
			Uint32 color=pixelGet(x, y, s);
			if((color&0xFFFFFF)==0x010101){
				pixelSet(x, y, ((Uint32)c.fg().hex(), s);
			}
		}
	}
	SDL_UnlockSurface(s);
	SDL_Texture* t=SDL_CreateTextureFromSurface(ren, s);
	SDL_FreeSurface(s);
	if(t==nullptr){
		std::cerr<<"SDL_CreateTextureFromSurface Error: "<<SDL_GetError()<<std::endl;
	}
	return t;
}
SDL_Texture* LImage::newTexture(SDL_Renderer* ren) {
	if(surf==nullptr){
		std::cerr<<"LImage is not initialized"<<std::endl;
		return nullptr;
	}
	SDL_Surface* s=SDL_ConvertSurfaceFormat(surf, SDL_PIXELFORMAT_RGBA32, SDL_SWSURFACE);
	SDL_Texture* t=SDL_CreateTextureFromSurface(ren, s);
	SDL_FreeSurface(s);
	if(t==nullptr){
		std::cerr<<"SDL_CreateTextureFromSurface Error: "<<SDL_GetError()<<std::endl;
	}
	return t;
}
Uint32 LImage::pixelGet(int x, int y){
	if(surf==nullptr){
		std::cerr<<"LImage is not initialized"<<std::endl;
		return 0;
	}
	Uint32 *pixels=(Uint32*)surf->pixels;
	return pixels[(y*surf->w)+x];
}
void LImage::pixelSet(int x, int y, Uint32 color){
	if(surf==nullptr){
		std::cerr<<"LImage is not initialized"<<std::endl;
	}
	Uint32 *pixels=(Uint32*)surf->pixels;
	pixels[(y*surf->w)+x]=SDL_MapRGB(surf->format, (color&0xFF0000)/0x10000, (color&0xFF00)/0x100, color&0xFF);
}
SDL_Surface* getSurface(){
	return surf;
}

