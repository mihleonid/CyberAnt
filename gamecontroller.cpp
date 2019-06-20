#include <iostream>
#include "gamecontroller.h"
#include "fieldcontroller.h"
#include "gamecontrollerevent.h"
#include "eventqueue.h"
#include "random.h"
#include "common.hpp"

GameController::GameController(bool m){
	std::cout<<"Creating GameController..."<<std::endl;
	sdlMode=m;
	try{
		Random::init();
		std::cout<<"Initialization finishing..."<<std::endl;
		currentController=new FieldController;
		initFps();
		std::cout<<"Initialization success."<<std::endl;
	}catch(int code){
		std::cerr<<"Initialization failed with code "<<code<<std::endl;
		exit(code);
	}
	loop();
}
GameController::~GameController(){
	clearHist(hist.size());
	delete currentController;
	std::cout<<"Exited"<<std::endl;
}

void GameController::clearHist(int k){
	if(k>0){
		for(int i=0;i<k;i++){
			if(hist.empty()){
				break;
			}
			delete hist.top();
			hist.pop();
		}
	}else{
		if(k<0){
			k=hist.size()+k;
			clearHist(k);
		}
	}
}
void GameController::changeController(Controller* ctl){
	Controller* old=currentController;
	currentController=ctl;
	hist.push(old);
}
bool GameController::back(){
	delete currentController;
	if(hist.empty()){
		return true;
	}
	currentController=hist.top();
	hist.pop();
	return false;
}

void GameController::loop(){
	while(true){
		currentController->loop();
		EventQueue q=currentController->eventLoop();
		GameControllerEvent* c=nullptr;
		while(!(q.empty())){
			c=(GameControllerEvent*)(q.pop());
			if(c->getExit()){
				goto quite;
			}
			if(c->getBack()){
				if(back()){
					goto quite;
				}
			}
			if(c->getController()!=nullptr){
				changeController(c->getController());
			}
			clearHist(c->getDeleting());
			FUPS+=c->getFUPSDelta();
			FUPS=mmin(FUPS, 40);
			FUPS=mmax(FUPS, 8);
			delete c;
		}
		delayFps();
	}
	quite:;
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

