#include "controller.h"

void Controller::initialize(Model* m, View* v){
	model=m;
	view=v;
	v->init();
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
	model->loop();
	view->loop(model);
}
Controller::~Controller(){
	delete model;
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
			model->applyEvent(c);
			delete c;
		}
	}
	return res;
}

