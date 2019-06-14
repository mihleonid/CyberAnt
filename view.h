#pragma once
#include "eventqueue.h"
#include "model.h"

class View{
	public:
		virtual void loop(const Model* m);
		virtual EventQueue getEvents();
};

