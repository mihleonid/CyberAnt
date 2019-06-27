#pragma once
#include <SDL.h>
#include "view.h"
#include "eventqueue.h"
#include "assets.h"
#include "ui/lui.h"


class FieldView:public View{
	private:
		int scrollX;
		int scrollY;
		bool mouseDown;
		bool mouseMoved;
		int mouseX;
		int mouseY;
		LWindow* win=nullptr;
		Assets* ass=nullptr;
	public:
		virtual void loop(const Model* m);
		virtual EventQueue getEvents();
		virtual void init();
		~FieldView();
};

