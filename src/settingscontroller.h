#pragma once
#include "controller.h"

class SettingsController:public Controller{
	protected:
		LScene* generateUIScene();
	public:
		virtual void init(LWindow* win);
};

