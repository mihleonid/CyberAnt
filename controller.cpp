#include "controller.h"

Controller::Controller(bool sdl){
	sdlMode=sdl;
}
void Controller::initialize(Model* m, View* v, View* tv){
	model=m;
	view=v;
	tview=tv;
	if(sdlMode){
		v->init();
	}else{
		tv->init();
	}
}
Model* Controller::getModel(){
	return model;
}
View* Controller::getView(){
	return view;
}
View* Controller::getTView(){
	return tview;
}
void Controller::loop(){
	model->loop();
	if(sdlMode){
		view->loop(model);
	}else{
		tview->loop(model);
	}
}
Controller::~Controller(){
	delete model;
	delete view;
	delete tview;
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

