#include <iostream>
#include <thread>
#include <chrono>
#ifdef SDL
#include <SDL.h>
#include <SDL2/SDL_ttf.h>
#endif
#include "lapp.h"
#include "lwindow.h"
#include "limage.h"
#include "terminal/ltdrawer.h"
#include "terminal/terminal_size.h"
#include "terminal/terminal.h"

LApp::LApp(bool useText){
	LImage::textLoad=false;//TODO
#ifdef SDL
	if(!useText){
		if(SDL_Init(SDL_INIT_VIDEO)!=0){
			std::cerr<<"SDL_Init error: "<<SDL_GetError()<<std::endl;
			std::cout<<"SDL is unavailible. Do you want to enter non-sdl mode? [1/0]:"<<std::endl;
			int yn;
			std::cin>>yn;
			if(yn==0){
				throw 1;
			}
			useText=true;
		}
		if(TTF_Init()!=0){
			std::cerr<<"TTF_Init error: "<<SDL_GetError()<<std::endl;
			std::cout<<"SDL is unavailible. Do you want to enter non-sdl mode? [1/0]:"<<std::endl;
			int yn;
			std::cin>>yn;
			if(yn==0){
				throw 1;
			}
			useText=true;
		}
	}
#endif
	text=useText;
	if(text){
		T_CLEAR();
		T_GOTO(5, 5);
		T_OPT(F_MAGENTA);
		T_OPT(B_GREEN);
		std::cout<<"LUI v 1.0 (Terminal graphics)";
		T_NL();
		std::this_thread::sleep_for(std::chrono::milliseconds(1500)); // Micro sleep
	}
}
LApp* LApp::addWindow(LWindow* w){
	w->init(this, text);
	wins.insert(w);
	return this;
}
LApp* LApp::eraseWindow(LWindow* w){
	wins.erase(w);
	delete w;
	return this;
}
bool LApp::isTerm() const{
	return text;
}
LApp::~LApp(){
	for(auto win:wins){
		delete win;
	}
#ifdef SDL
	if(text){
		SDL_Quit();
		TTF_Quit();
	}
#endif
}
