#pragma once
#include "controller.h"

class MenuController:public Controller{
	protected:
		LScene* generateUIScene();
	public:
		MenuController(LWindow* win);
};

