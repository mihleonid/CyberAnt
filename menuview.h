#pragma once
#include "ui/lwindow.h"
#include "view.h"
#include "eventqueue.h"


class MenuView:public View{
	private:
		LWindow* win=nullptr;
	public:
		virtual void loop(const Model* m);
		virtual EventQueue getEvents();
		virtual void init(LWindow*);
};

