#include <iostream>
#include <SDL.h>

int main(int argc, char * argv[]){
	// Starting
	std::cout<<"Starting..."<<std::endl;
	if (SDL_Init(SDL_INIT_EVERYTHING)!=0){
		std::cerr<<"SDL_Init error: "<<SDL_GetError()<<std::endl;
		return 1;
	}
	// Game
	GameController ctl;
	ctl.start();
	// Ending
	SDL_Quit();
	std::cout<<"Exiting"<<std::endl;
	return 0;
}

