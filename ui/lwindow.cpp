#include <iostream>
#include <thread>
#include <chrono>
#include "lwindow.h"
#include "terminal/ltdrawer.h"
#include "terminal/terminal_size.h"
#include "sdl/lsdrawer.h"
#include "lcolor.h"

LWindow::LWindow(const char* title, bool force){
	wtitle=title;
#ifdef SDL
	if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
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
#endif
	}
}
void LWindow::add(){
}
void LWindow::update(){
	T_HOME();
	ldr->clear();
	ldr->color(LColor(154, 0, 160));
	ldr->drawTextCenter(tw/2, 1, wtitle);
	T_NL();
	char* cmd=new char[100];
	std::cin>>cmd;
	if(cmd[0]=='q'){
		exit(0);
	}
	delete cmd;
}
LWindow::~LWindow(){
	if(win!=nullptr){
		SDL_DestroyWindow(win);
	}
	delete ldr;
}

