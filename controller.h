#pragma once
#include "model.h"
#include "view.h"
#include "eventqueue.h"

class Controller{
	private:
		Model* model;
		View* view;
		void initialize(Model* m, View* v);
	public:
		Model* getModle();
		View* getView();

		void loop();
		EventQueue eventLoop();

		Controller~();
};

