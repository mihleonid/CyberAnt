#pragma once
#include "ui/lwindow.h"
#include "ui/lscene.h"
#include "view.h"
#include "eventqueue.h"


class GameOverView:public View{
	private:
		LWindow* win=nullptr;
	public:
		virtual void loop(const Model* m);
		virtual EventQueue getEvents();
		virtual void init(LWindow*);
		~GameOverView();
};

