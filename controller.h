#pragma once
#include "model.h"
#include "view.h"
#include "eventqueue.h"

class Controller{
	private:
		Model* model;
		View* view;
		View* tview;
		bool sdlMode;
	protected:
		void initialize(Model* m, View* v, View* tv);
	public:
		Controller(bool sdl);
		Model* getModel();
		View* getView();
		View* getTView();

		void loop();
		EventQueue eventLoop();

		~Controller();
};

