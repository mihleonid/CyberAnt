#include <iostream>
#include <queue>
#include "controller.h"
#include "gamecontrollerevent.h"
#include "ui/lwindow.h"

void Controller::init(LWindow* win){
	std::cout<<"Calling Controller::init()"<<std::endl;
}
void Controller::initialize(Model* m, View* v, EventListener* el, LWindow* w){
	model=m;
	view=v;
	eventListener=el;
	win=w;
	scn=generateUIScene();
	if(v!=nullptr){
		v->init(w);
	}
}
LScene* Controller::generateUIScene(){
	std::cerr<<"Controller must generate UI Scene"<<std::endl;
	return nullptr;
}
Model* Controller::getModel(){
	return model;
}
View* Controller::getView(){
	return view;
}
LScene* Controller::getLScene(){
	return scn;
}
const Model* Controller::getModel() const{
	return model;
}
const View* Controller::getView() const{
	return view;
}
const LScene* Controller::getLScene() const{
	return scn;
}
void Controller::loop(){
	if(model!=nullptr){
		eventQueue.pipe(model->loop());
	}
	if(view==nullptr){
		win->clear(LColor(true, 0, 120, 230));
		win->draw();
	}else{
		view->loop(model);
	}
	win->present();
}
Controller::~Controller(){
	if(model!=nullptr){
		delete model;
	}
	if(view!=nullptr){
		delete view;
	}
	delete scn;
	if(eventListener!=nullptr){
		delete eventListener;
	}
}
EventQueue Controller::eventLoop(){
	EventQueue forGameController;
	// Сейчас мы получим события из LWindow.
	std::pair<EventQueue, std::queue<LEvent*>> pair=win->getEvents();
	EventQueue res=pair.first;
	std::queue<LEvent*> levents;
	while(!(pair.second.empty())){
		if(pair.second.front()->getType()==LEventType::Exit){
			res.push(new GameControllerEvent(true, false));
			goto quit;
		}
		if(pair.second.front()->getType()==LEventType::Back){
			res.push(new GameControllerEvent(false, true));
			goto quit;
		}
		levents.push(pair.second.front());
		pair.second.pop();
	}
	// Мы всё получили. res - очередь, куда надо складывать Event*, levents - события, которые надо слушать дополнительно.
	if(eventListener!=nullptr){
		EventQueue rr=eventListener->getEvents(levents, view);
		res.pipeM(rr);
	}
	res.pipeM(eventQueue);
	// Распределим
	quit:
	{
		Event* c=nullptr;
		while(!(res.empty())){
			c=res.pop();
			if(c->forGameController()){
				forGameController.push(c);
			}else{
				if(model==nullptr){
					std::cerr<<"Event is going to nullptr model"<<std::endl;
					delete c;
					continue;
				}
				model->applyEvent(c);
				delete c;
			}
		}
	}
	// Удаляем всё, что осталось
	while(!(pair.second.empty())){
		delete pair.second.front();
		pair.second.pop();
	}
	while(!(levents.empty())){
		delete levents.front();
		levents.pop();
	}
	return forGameController;
}

