#pragma once
#include "ui/lwindow.h"
#include "view.h"
#include "eventqueue.h"
#include "assets.h"

class LWindow;

class FieldView:public View{
	private:
		int scrollX;
		int scrollY;
		bool mouseDown;
		bool mouseMoved;
		int mouseX;
		int mouseY;
		Assets* ass=nullptr;
		LWindow* win=nullptr;
	public:
		virtual void loop(const Model* m);
		virtual void init(LWindow* win);
		virtual ~FieldView();
		friend class FieldEventListener;
};

