#pragma once
#include "lcomponent.h"
#include "../callback.h"
#include "lkeyboardevent.h"

class LKeyboardListener:public LComponent{
	private:
		Callback<Event*>* onDown;
		LKey key;
	public:
		LKeyboardListener(LKey, Callback<Event*>*);
		virtual ~LKeyboardListener();
		virtual void draw(LDrawer*);
		virtual std::pair<Event*, bool> applyEvent(LEvent*);
};

