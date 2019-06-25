#pragma once
#include "view.h"
#include "eventqueue.h"
#include "assets.h"

class FieldTView:public View{
	public:
		virtual void init();
		virtual void loop(const Model* m);
		virtual EventQueue getEvents();
		~FieldTView();
};

