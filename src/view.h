#pragma once
#include "eventqueue.h"
#include "model.h"

class LWindow;

class View{
	public:
		virtual void init(LWindow*);
		virtual void loop(const Model* m);
		virtual ~View();
};

