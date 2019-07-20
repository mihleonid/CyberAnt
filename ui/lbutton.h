#pragma once
#include <string>
#include "lcomponent.h"

class LButton:public LComponent{
	private:
		std::string text;
		Event* (*onClick)();
	public:
		LButton(Rect p, std::string t, Event* (*c)());
		~LButton();
		virtual void draw(LDrawer*);
		virtual Event* applyEvent(LEvent*);
};

