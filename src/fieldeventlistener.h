#pragma once
#include "eventlistener.h"

class FieldEventListener:public EventListener{
	public:
		virtual EventQueue getEvents(std::queue<LEvent*>, View*);
};

