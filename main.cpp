#include <iostream>
#include <SDL.h>
#include "gamecontroller.h"

int main(int argc, char * argv[]){
	// Starting
	std::cout<<"Starting..."<<std::endl;
	bool sdlMode=true;
	if (SDL_Init(SDL_INIT_EVERYTHING)!=0){
		std::cerr<<"SDL_Init error: "<<SDL_GetError()<<std::endl;
		std::cout<<"SDL is unavailible. Do you want to enter non-sdl mode? [1/0]"<<std::endl; //TODO non-sdl mode
		int yn;
		std::cin>>yn;
		if(yn==0){
			return 1;
		}
		sdlMode=false;
	}
	// Game
	GameController ctl(sdlMode);
	// Ending
	SDL_Quit();
	std::cout<<"Exiting"<<std::endl;
	return 0;
}

