#pragma once
#include "event.h"
#include "eventqueue.h"

class LWindow;

class Model{
	public:
		virtual EventQueue loop();
		virtual void applyEvent(Event* event);
		virtual ~Model();
};

