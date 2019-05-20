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

