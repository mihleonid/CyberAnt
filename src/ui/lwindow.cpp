#include <iostream>
#include <thread>
#include <chrono>
#ifdef SDL
#include <SDL.h>
#include <SDL2/SDL_ttf.h>
#endif
#include "lwindow.h"
#include "levent.h"
#include "limage.h"
#include "terminal/ltdrawer.h"
#include "terminal/terminal_size.h"
#include "terminal/terminal.h"
#ifdef SDL
#include "sdl/lsdrawer.h"
#endif
#include "lcolor.h"

LWindow::LWindow(const char* title, bool force){
	wtitle=title;
	if(force){
		sdlMode=false;
		//ldr=new LTDrawer;
		LImage::textLoad=true;
		//TODO Treminal control
	}else{
#ifdef SDL
		sdlMode=true;
		tw=SCREEN_W;
		th=SCREEN_H;
		win=SDL_CreateWindow(wtitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
		if(win==nullptr){
			std::cerr<<"SDL_CreateWindow error:"<<SDL_GetError()<<std::endl;
			throw 1;
		}
		SDL_Renderer* ren=SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if(ren==nullptr){
			std::cerr<<"SDL_CreateRenderer error:"<<SDL_GetError()<<std::endl;
			throw 1;
		}
		ldr=new LSDrawer(ren);
#endif
	}
	cnt=new LControl();
}
LScene* LWindow::getScene(){
	return scene;
}
void LWindow::setScene(LScene* scn){
	scene=scn;
}
LDrawer* LWindow::getDrawer(){
	return ldr;
}
LControl* LWindow::getControl(){
	return cnt;
}
int LWindow::getFps(){
	return fps;
}
void LWindow::setFps(int f){
	if(f<8){
		fps=8;
		return;
	}
	if(f>200){
		fps=200;
		return;
	}
	fps=f;
}
std::pair<EventQueue, std::queue<LEvent*>> LWindow::getEvents(){
	cnt->loop();
	LEvent* e=nullptr;

	EventQueue eq;
	std::queue<LEvent*> q;

	while((e=cnt->next())!=nullptr){
		eq.pipe(scene->applyEvent(e));
		if(e->getPrevented()){
			delete e;
		}else{
			q.push(e);
		}
	}
	return std::pair<EventQueue, std::queue<LEvent*>>(eq, q);
}
void LWindow::clear(){
	ldr->clear();
}
void LWindow::clear(const LColor& c){
	ldr->clear(c);
}
void LWindow::draw(){
	scene->draw(ldr);
	if(!sdlMode){
		ldr->color(LColor(154, 0, 160));
		ldr->drawTextCenter(tw/2, 1, wtitle);
		T_NL();
	}
}
void LWindow::present(){
	ldr->present();
}
Point LWindow::getCenter(){
	if(sdlMode){
		return Point(SCREEN_W/2, SCREEN_H/2);
	}else{
		return Point(tw/2, th/2);
	}
}
Point LWindow::getCorner(){
	if(sdlMode){
		return Point(SCREEN_W, SCREEN_H);
	}else{
		return Point(tw, th);
	}
}
LWindow::~LWindow(){
	delete cnt;
#ifdef SDL
	if(win!=nullptr){
		SDL_DestroyWindow(win);
	}
#endif
	delete ldr;
#ifdef SDL
	if(sdlMode){
		SDL_Quit();
		TTF_Quit();
	}
#endif
}
