#pragma once
#include <string>
#include "lcomponent.h"
#include "../callback.h"

class LButton:public LComponent{
	private:
		std::string text;
		Callback<Event*>* onClick;
	public:
		LButton(Rect p, std::string t, Callback<Event*>*);
		virtual ~LButton();
		virtual void draw(LDrawer*);
		virtual Event* applyEvent(LEvent*);
};

