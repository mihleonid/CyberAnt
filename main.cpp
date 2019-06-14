#include <iostream>
#include <SDL.h>
#include "gamecontroller.h"

int main(int argc, char * argv[]){
	// Starting
	std::cout<<"Starting..."<<std::endl;
	if (SDL_Init(SDL_INIT_EVERYTHING)!=0){
		std::cerr<<"SDL_Init error: "<<SDL_GetError()<<std::endl;
		return 1;
	}
	// Game
	GameController ctl;
	// Ending
	SDL_Quit();
	std::cout<<"Exiting"<<std::endl;
	return 0;
}

