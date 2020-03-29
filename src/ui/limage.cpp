#include <iostream>
#include <cassert>
#include <vector>
#include <SDL.h>
#include "sdl/lsdrawer.h"
#include "ldrawer.h"
#include "limage.h"
#include "../configurator.h"

bool LImage::textLoad=false;
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
	if(textLoad){
		tsurf=new LTSurface((std::string(str)+std::string(".txt")).c_str());
#ifdef DEBUG
		std::cout<<"Loaded "<<std::string(str)+std::string(".txt")<<std::endl;
#endif
	}else{
		tsurf=nullptr;
	}
}
LImage::LImage(const std::string& str){
#ifdef SDL
	surf=SDL_LoadBMP((str+std::string(".bmp")).c_str());
#ifdef DEBUG
	std::cout<<"Loaded "<<str+std::string(".bmp")<<std::endl;
#endif
#endif
	if(textLoad){
		tsurf=new LTSurface((str+std::string(".txt")).c_str());
#ifdef DEBUG
		std::cout<<"Loaded "<<str+std::string(".txt")<<std::endl;
#endif
	}else{
		tsurf=nullptr;
	}
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
	/*
	tsurf=new LTSurface(img->tsurf);
	applyColors(c);
	*/
}
LImage::~LImage(){
#ifdef SDL
	if(surf!=nullptr){
		SDL_FreeSurface(surf);
		for(auto i=sdlcache.begin();i!=sdlcache.end();++i){
			SDL_DestroyTexture(i->second);
		}
	}
#endif
	/*
	if(tsurf!=nullptr){
		delete tsurf;
	}
	*/
	delete ldr;
}
LImage* LImage::applyColors(const LColor& c){
	std::cerr<<"Using deprecated function LImage::applyColors"<<std::endl;
#ifdef SDL
	applySDL(c);
#endif
	/*
	applyT(c);
	*/
	return this;
}
LImage* LImage::applyColors(int hex){
	return applyColors(LColor(hex, true));
}

#ifdef SDL
void LImage::smooth(SDL_Surface* s){
	if(!Configurator::getSmooth()){
		return;
	}
	SDL_LockSurface(s);
	for(int x=1;x<(s->w-1);x++){
		for(int y=1;y<(s->h-1);y++){
			std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> cls;
			for(int xx=x-1;xx<=x+1;++xx){
				for(int yy=y-1;yy<=y+1;++yy){
					Uint32 color=pixelGet(xx, yy, s);
					int r=(color&0xFF0000)/0x010000;
					int g=(color&0x00FF00)/0x000100;
					int b=(color&0x0000FF)/0x000001;
					if(xx==x){
						cls.push_back({{r, g}, {b, 3}});
					}
					if(yy==y){
						cls.push_back({{r, g}, {b, 2}});
					}
					if(xx==x){
						if(yy==y){
							cls.push_back({{r, g}, {b, 24}});
						}
					}
				}
			}
			int r=0;
			int g=0;
			int b=0;
			int cnt=0;
			for(int i=0;i<cls.size();++i){
				r+=cls[i].first.first*cls[i].second.second;
				g+=cls[i].first.second*cls[i].second.second;
				b+=cls[i].second.first*cls[i].second.second;
				cnt+=cls[i].second.second;
			}
			r/=cnt;
			g/=cnt;
			b/=cnt;
			pixelSet(x, y, (Uint32)(b*0x10000+g*0x100+r), s);
		}
	}
	SDL_UnlockSurface(s);
}
SDL_Texture* LImage::newTexture(const LColor& c, SDL_Renderer* ren) {
	if(surf==nullptr){
		std::cerr<<"LImage is not initialized"<<std::endl;
		return nullptr;
	}
	if((sdlcache.count(c))){//TODO clear cache
		return sdlcache[c];
	}
	SDL_Surface* s=SDL_ConvertSurfaceFormat(surf, SDL_PIXELFORMAT_RGBA32, SDL_SWSURFACE);
	SDL_LockSurface(s);
	for(int x=0;x<s->w;x++){
		for(int y=0;y<s->h;y++){
			Uint32 color=pixelGet(x, y, s);
			if((color&0xFFFFFF)==0x010101){
				pixelSet(x, y, (Uint32)c.fg().hex(), s);
			}
		}
	}
	SDL_UnlockSurface(s);
	smooth(s);
	SDL_Texture* t=SDL_CreateTextureFromSurface(ren, s);
	SDL_FreeSurface(s);
	if(t==nullptr){
		std::cerr<<"SDL_CreateTextureFromSurface Error: "<<SDL_GetError()<<std::endl;
	}
	sdlcache[c]=t;
	return t;
}
SDL_Texture* LImage::newTexture(SDL_Renderer* ren) {
	if(surf==nullptr){
		std::cerr<<"LImage is not initialized"<<std::endl;
		return nullptr;
	}
	SDL_Surface* s=SDL_ConvertSurfaceFormat(surf, SDL_PIXELFORMAT_RGBA32, SDL_SWSURFACE);
	smooth(s);
	SDL_Texture* t=SDL_CreateTextureFromSurface(ren, s);
	SDL_FreeSurface(s);
	if(t==nullptr){
		std::cerr<<"SDL_CreateTextureFromSurface Error: "<<SDL_GetError()<<std::endl;
	}
	return t;
}
Uint32 LImage::pixelGet(int x, int y, SDL_Surface* s){
	if(s==nullptr){
		std::cerr<<"LImage is not initialized"<<std::endl;
		return 0;
	}
	Uint32 *pixels=(Uint32*)s->pixels;
	return pixels[(y*s->w)+x];
}
void LImage::pixelSet(int x, int y, Uint32 color, SDL_Surface* s){
	if(s==nullptr){
		std::cerr<<"LImage is not initialized"<<std::endl;
	}
	Uint32 *pixels=(Uint32*)s->pixels;
	pixels[(y*surf->w)+x]=SDL_MapRGB(s->format, (color&0xFF0000)/0x10000, (color&0xFF00)/0x100, color&0xFF);
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
			Uint32 color=pixelGet(x, y, s);
			if((color&0xFFFFFF)==0x010101){
				pixelSet(x, y, (Uint32)c.fg().hex(), s);
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
LDrawer* LImage::getDrawer(){
	if(ldr==nullptr){
		ldr=new LSDrawer(SDL_CreateSoftwareRenderer(surf));
	}
	return ldr;
}

