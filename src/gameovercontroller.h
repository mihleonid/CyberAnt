#pragma once
#include "controller.h"

class GameOverController:public Controller{
	protected:
		LScene* generateUIScene();
	public:
		GameOverController(LWindow* win);
};

