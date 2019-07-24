#pragma once
#include "controller.h"

class LWindow;

class FieldController:public Controller{
	protected:
		virtual LScene* generateUIScene();
	public:
		FieldController(LWindow* win);
};

