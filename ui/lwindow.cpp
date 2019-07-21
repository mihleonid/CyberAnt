#include <iostream>
#include <thread>
#include <chrono>
#ifdef SDL
#include <SDL.h>
#include <SDL2/SDL_ttf.h>
#endif
#include "lwindow.h"
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
	LImage::textLoad=false;
#ifdef SDL
	if(SDL_Init(SDL_INIT_VIDEO)!=0){
		std::cerr<<"SDL_Init error: "<<SDL_GetError()<<std::endl;
		std::cout<<"SDL is unavailible. Do you want to enter non-sdl mode? [1/0]:"<<std::endl;
		int yn;
		std::cin>>yn;
		if(yn==0){
			throw 1;
		}
		force=true;
	}
#endif
	if(force){
		sdlMode=false;
		T_CLEAR();
		T_GOTO(5, 5);
		T_OPT(F_MAGENTA);
		T_OPT(B_GREEN);
		std::cout<<"LUI v 1.0 (Terminal graphics)";
		T_NL();
		Point p=terminal_size();
		tw=p.getX();
		th=p.getY();
		ldr=new LTDrawer;
		LImage::textLoad=true;
		//TODO Treminal control
		std::this_thread::sleep_for(std::chrono::milliseconds(1500)); // Micro sleep
	}else{
#ifdef SDL
		sdlMode=true;
		if(TTF_Init()!=0){
			std::cerr<<"TTF_Init error"<<std::endl;
			throw 1;
		}
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
		cnt=new LControl();
#endif
	}
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
std::pair<EventQueue, std::queue<LEvent*>> LWindow::getEvents(){
	cnt->loop();
	LEvent* e;
	EventQueue eq;
	std::queue<LEvent*> q;
	while((e=cnt->next())!=nullptr){
		eq.pipe(scene->applyEvent(e));
		q.push(e);
	}
	return std::pair<EventQueue, std::queue<LEvent*>>(eq, q);
}
void LWindow::clear(){
	ldr->clear();
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

