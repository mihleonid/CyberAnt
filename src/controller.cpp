#include <iostream>
#include "controller.h"
#include "ui/lwindow.h"

void Controller::initialize(Model* m, View* v, LWindow* w){
	model=m;
	view=v;
	win=w;
	scn=generateUIScene();
	v->init(w);
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
	win->setScene(scn);
	if(model!=nullptr){
		eventQueue.pipe(model->loop());
	}
	view->loop(model);
}
Controller::~Controller(){
	if(model!=nullptr){
		delete model;
	}
	delete view;
	delete scn;
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
	res.pipeM(eventQueue);
	return res;
}

