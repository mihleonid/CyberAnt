#pragma once
#include "event.h"

class Model{
	public:
		virtual void loop();
		virtual void applyEvent(Event* event);
		virtual ~Model();
};

