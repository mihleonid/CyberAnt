#include <iostream>
#include <chrono>
#include <thread>
#include "ui/lwindow.h"
#include "ui/lapp.h"
#include "gamecontroller.h"
#include "menucontroller.h"
#include "configurator.h"
#include "fieldcontroller.h"
#include "gamecontrollerevent.h"
#include "eventqueue.h"
#include "random.h"
#include "common.hpp"

GameController::GameController(){
#ifdef DEBUG
	std::cout<<"Creating GameController..."<<std::endl;
#endif
	try{
		Random::init();
		LApp* app=new LApp();
#ifdef DEBUG
		std::cout<<"Initialization finishing..."<<std::endl;
#endif
		win=new LWindow(Configurator::getWindowTitle());
		app->addWindow(win);
		currentController=new MenuController();
		currentController->init(win);
		win->setScene(currentController->getLScene());
		initFps();
#ifdef DEBUG
		std::cout<<"Initialization success."<<std::endl;
#endif
	}catch(int code){
		std::cerr<<"Initialization failed with code "<<code<<std::endl;
		exit(code);
	}
	loop();
}
GameController::~GameController(){
	clearHist(hist.size());
	delete currentController;
	delete app;
#ifdef DEBUG
	std::cout<<"Exited"<<std::endl;
#endif
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
	currentController->init(win);
	win->setScene(currentController->getLScene());
}
bool GameController::back(int d){
	for(int i=0;i<d;++i){
		if(hist.empty()){
			return true;
		}
		delete currentController;
		currentController=hist.top();
		win->setScene(currentController->getLScene());
		hist.pop();
	}
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
				delete c;
				goto quit;
			}
			if(back(c->getBack())){
				delete c;
				goto quit;
			}
			if(c->getController()!=nullptr){
				changeController(c->getController());
			}
			clearHist(c->getDeleting());
			FUPS+=c->getFUPSDelta();
			FUPS=mmin(FUPS, 200);
			FUPS=mmax(FUPS, 8);
			win->setFps(FUPS);
			delete c;
		}
		delayFps();
		continue;
		quit:;
		while(!q.empty()){
			delete q.pop();
		}
		return;
	}
}

void GameController::initFps(){
	// TODO not uint but chrono
	mLastFrame=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}
void GameController::delayFps(){
	uint c=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	uint delta=c-mLastFrame;
	mLastFrame=c;
	uint delay=1000/FUPS;
	delta+=3;
	if(delay<=delta){return;}
	delay-=delta;
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}

