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
#include "lapp.h"

LWindow::LWindow(const char* title){
	wtitle=title;
	cnt=new LControl();
}
LWindow::LWindow(){
}
void LWindow::init(LApp* a, bool text){
	app=a;
	if(text){
		//ldr=new LTDrawer;
		LImage::textLoad=true;
		//TODO Treminal control
		Point p=terminal_size();
		tw=p.getX();
		th=p.getY();
	}else{
#ifdef SDL
		win=SDL_CreateWindow(wtitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, tw, th, SDL_WINDOW_SHOWN);// TODO ch title, resizable
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
	if(app->isTerm()){
		ldr->color(LColor(154, 0, 160));
		ldr->drawTextCenter(tw/2, 1, wtitle);
		T_NL();
	}
}
void LWindow::present(){
	ldr->present();
}
Point LWindow::getCenter(){
	return Point(tw/2, th/2);
}
Point LWindow::getCorner(){
	return Point(tw, th);
}
int LWindow::getH() const{
	return th;
}
int LWindow::getW() const{
	return tw;
}
void LWindow::postResize(){
#ifdef SDL
	if(win!=nullptr){
		SDL_SetWindowSize(win, tw, th);
	}
#endif
}
LWindow* LWindow::setH(int h){
	th=h;
	return this;
}
LWindow* LWindow::setW(int w){
	tw=w;
	return this;
}
LWindow::~LWindow(){
	delete cnt;
#ifdef SDL
	if(win!=nullptr){
		SDL_DestroyWindow(win);
	}
#endif
	delete ldr;
}
