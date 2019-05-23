#include <iostream>
#include "gamecontroller.h"
#include "eventqueue.h"

GameController::GameController(){
	std::cout<<"Creating GameController"<<std::endl;
	try{
		std::cout<<"Initialization finishing..."<<std::endl;
		currentController=new FieldController();
		initFps();
		std::cout<<"Initialization success"<<std::endl;
	}catch(int code){
		std::cerr<<"Initialization failed with code "<<code<<std::endl;
		exit(code);
	}
	loop();
}
GameController::~GameController(){
	delete currentController;
	std::cout<<"Exited"<<std::endl;
}

void GameController::loop(){
	while(true){
		currentController->loop();
		EventQueue q=currentController->eventLoop();
		Event* c=nullptr;
		while(!(q.empty())){
			c=q.pop();
			delete c;
		}
		delayFps();
	}
}

void GameController::initFps(){
	mLastFrame=SDL_GetTicks();
}
void GameController::delayFps(){
	Uint32 c=SDL_GetTicks();
	Uint32 delta=c-mLastFrame;
	mLastFrame=c;
	Uint32 delay=1000/FUPS;
	delta+=3;
	if(delay<=delta){return;}
	delay-=delta;
	SDL_Delay(delay);
}

