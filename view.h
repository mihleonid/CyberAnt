#pragma once
#include "eventqueue.h"
#include "model.h"

class View{
	public:
		virtual void init();
		virtual void loop(const Model* m);
		virtual EventQueue getEvents();
		virtual ~View();
};

