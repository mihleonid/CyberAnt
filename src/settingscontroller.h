#pragma once
#include "controller.h"

class SettingsController:public Controller{
	protected:
		LScene* generateUIScene();
	public:
		SettingsController(LWindow* win);
};

