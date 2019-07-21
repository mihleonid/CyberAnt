#include <iostream>
#include "controller.h"

void Controller::initialize(Model* m, View* v, LWindow* win){
	model=m;
	view=v;
	v->init(win);
}
Model* Controller::getModel(){
	return model;
}
View* Controller::getView(){
	return view;
}
const Model* Controller::getModel() const{
	return model;
}
const View* Controller::getView() const{
	return view;
}
void Controller::loop(){
	if(model!=nullptr){
		model->loop();
	}
	view->loop(model);
}
Controller::~Controller(){
	if(model!=nullptr){
		delete model;
	}
	delete view;
}
EventQueue Controller::eventLoop(){
	EventQueue res;
	EventQueue rr=view->getEvents();
	Event* c=nullptr;
	while(!(rr.empty())){
		c=rr.pop();
		if(c->forGameController()){
			res.push(c);
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
	return res;
}

