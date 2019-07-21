#pragma once
#include "../ldrawer.h"
#include "../limage.h"
#include "../../point.h"

class LTDrawer:public LDrawer{
	private:
		// Created for optimization
		Rect drawText(int x, int y, const char* text, int len);
		Rect drawTextRight(int x, int y, const char* text, int len);
		Rect drawTextCenter(int x, int y, const char* text, int len);
		//LTBuffer* buf;
		int foreground;
		int background;
	public:
		LTDrawer();
		virtual ~LTDrawer();

		virtual Rect draw(int x, int y, LImage* img);
		virtual Rect draw(int x, int y, LImage* img, const LColor& c);

		virtual Rect drawText(int x, int y, int text);
		virtual Rect drawText(int x, int y, const char* text);

		virtual Rect drawTextRight(int x, int y, int text);
		virtual Rect drawTextRight(int x, int y, const char* text);

		virtual Rect drawTextCenter(int x, int y, int text);
		virtual Rect drawTextCenter(int x, int y, const char* text);

		virtual void clear();
		virtual void present();

		virtual void color(LColor c);
		virtual void color();
};

