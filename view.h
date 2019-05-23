#pragma once
#include "eventqueue.h"

class View{
	public:
		virtual void loop(const Model* m);
		virtual EventQueue getEvents();
};

