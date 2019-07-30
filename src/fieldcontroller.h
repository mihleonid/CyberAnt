#pragma once
#include "controller.h"

class LWindow;

class FieldController:public Controller{
	protected:
		virtual LScene* generateUIScene();
	public:
		virtual void init(LWindow* win);
};

