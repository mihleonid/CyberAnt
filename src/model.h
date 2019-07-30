#pragma once
#include "event.h"
#include "eventqueue.h"

class LWindow;

class Model{
	public:
		LWindow* win;
		virtual EventQueue loop();
		virtual void applyEvent(Event* event);
		virtual ~Model();
};

