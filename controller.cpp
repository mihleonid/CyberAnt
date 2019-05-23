#include "controller.h"

void Controller::initialize(Model* m, View* v){
	model=m;
	view=v;
}
Model* Controller::getModel(){
	return model;
}
View* Controller::getView(){
	return view;
}
void Controller::loop(){
	model->loop();
	view->loop(model);
}
EventQueue Controller::eventLoop(){
	EventQueue res;
	EventQueue rr=view->getEvents(model);
	Event* c=nullptr;
	while(!(rr.empty())){
		c=rr.pop();
		if(c.forGameController()){
			res.push(c);
		}else{
			model->applyEvent(c);
			delete c;
		}
	}
	return res;
}

