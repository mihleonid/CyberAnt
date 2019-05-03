#include <iostream>
#include "gamecontroller.h"

GameController::GameController(){
	std::cout<<"Creating GameController"<<std::endl;
	gaming=false;
	ui=new UI;
	mModel=new Model;
}
GameController::~GameController(){
	std::cout<<"Exited"<<std::endl;
}
void GameController::start(){
	gaming=true;
	// Многопоточность лучше не делать (пока) - SDL2 не рекомендует
	try{
		std::cout<<"Initialization finishing..."<<std::endl;
		mModel->start();
		ui->start();
		initFps();
		std::cout<<"Initialization success"<<std::endl;
	}catch(int code){
		std::cerr<<"Initialization failed with code "<<code<<std::endl;
		exit(code);
	}
	loop();
}
// Пока это игровой, рисовальный и событийный цикл. TODO Нужно изменить механизм событий
void GameController::loop(){
	std::vector<Event*> current;
	while(gaming){
		for(Event* evt:current){
			mModel->applyEvent(evt);
			delete evt;
		}
		mModel->loop();
		ui->loop(this);
		current=ui->getEvent(this);
		delayFps();
	}
}
void GameController::stop(){
	gaming=false;
	ui->stop();
	mModel->stop();
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

