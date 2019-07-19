#include <iostream>
#include <cassert>
#include "limage.h"

LImage::LImage(){
#ifdef SDL
	surf=nullptr;
#endif
	tsurf=nullptr;
}
LImage::LImage(const char* str){
#ifdef SDL
	surf=SDL_LoadBMP((std::string(str)+std::string(".bmp")).c_str());
#ifdef DEBUG
	std::cout<<"Loaded "<<std::string(str)+std::string(".bmp")<<std::endl;
#endif
#endif
	tsurf=new LTSurface((std::string(str)+std::string(".txt")).c_str());
#ifdef DEBUG
	std::cout<<"Loaded "<<std::string(str)+std::string(".txt")<<std::endl;
#endif
}
LImage::LImage(const std::string& str){
#ifdef SDL
	surf=SDL_LoadBMP((str+std::string(".bmp")).c_str());
#ifdef DEBUG
	std::cout<<"Loaded "<<str+std::string(".bmp")<<std::endl;
#endif
#endif
	tsurf=new LTSurface((str+std::string(".txt")).c_str());
#ifdef DEBUG
	std::cout<<"Loaded "<<str+std::string(".txt")<<std::endl;
#endif
}
LImage::LImage(LImage* img){
#ifdef SDL
	if(img->surf==nullptr){
		surf=nullptr;
	}else{
		surf=SDL_ConvertSurfaceFormat(img->surf, SDL_PIXELFORMAT_RGBA32, SDL_SWSURFACE);
	}
#endif
	if(img->tsurf==nullptr){
		tsurf=nullptr;
	}else{
		tsurf=new LTSurface(img->tsurf);
	}
}
LImage::LImage(LImage* img, const LColor& c){
#ifdef SDL
	surf=SDL_ConvertSurfaceFormat(img->surf, SDL_PIXELFORMAT_RGBA32, SDL_SWSURFACE);
#endif
	tsurf=new LTSurface(img->tsurf);
	applyColors(c);
}
LImage::~LImage(){
#ifdef SDL
	if(surf!=nullptr){
		SDL_FreeSurface(surf);
	}
#endif
	if(tsurf!=nullptr){
		delete tsurf;
	}
}
LImage* LImage::applyColors(const LColor& c){
#ifdef SDL
	applySDL(c);
#endif
	applyT(c);
	return this;
}
LImage* LImage::applyColors(int hex){
	return applyColors(LColor(hex, true));
}

#ifdef SDL
SDL_Texture* LImage::newTexture(const LColor& c, SDL_Renderer* ren) {
	if(surf==nullptr){
		std::cerr<<"LImage is not initialized"<<std::endl;
		return nullptr;
	}
	SDL_Surface* s=SDL_ConvertSurfaceFormat(surf, SDL_PIXELFORMAT_RGBA32, SDL_SWSURFACE);
	SDL_LockSurface(s);
	for(int x=0;x<s->w;x++){
		for(int y=0;y<s->h;y++){
			Uint32 color=pixelGet(x, y);
			if((color&0xFFFFFF)==0x010101){
				pixelSet(x, y, (Uint32)c.fg().hex());
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
SDL_Surface* LImage::getSurface(){
	return surf;
}
void LImage::applySDL(const LColor& c){
	if(surf==nullptr){
		std::cerr<<"LImage is not initialized"<<std::endl;
	}
	SDL_Surface* s=SDL_ConvertSurfaceFormat(surf, SDL_PIXELFORMAT_RGBA32, SDL_SWSURFACE);
	assert(s!=nullptr);
	SDL_LockSurface(s);
	for(int x=0;x<s->w;x++){
		for(int y=0;y<s->h;y++){
			Uint32 color=pixelGet(x, y);
			if((color&0xFFFFFF)==0x010101){
				pixelSet(x, y, (Uint32)c.fg().hex());
			}
		}
	}
	SDL_UnlockSurface(s);
	SDL_FreeSurface(surf);
	surf=s;
}
#endif
void LImage::applyT(const LColor& c){
	tsurf->applyColors(c);
}
LTSurface LImage::newTSurface(const LColor& c){
	return LTSurface(*tsurf, c);
}
void LImage::letterSet(int x, int y, char let, LColor c){
	tsurf->set(x, y, let, c);
}
void LImage::letterSet(int x, int y, std::pair<char, LColor> c){
	tsurf->set(x, y, c);
}
std::pair<char, LColor> LImage::letterGet(int x, int y) const{
	return tsurf->get(x, y);
}
const LTSurface& LImage::getTSurface(){
	return *tsurf;
}

