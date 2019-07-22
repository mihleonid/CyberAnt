#pragma once
#include "../point.h"
#include "lcolor.h"
#include "limage.h"

class LDrawer{
	public:
		virtual void drawRect(const Rect& r, const LColor& c);
		virtual void drawRect(const Rect& r);

		virtual Rect draw(int x, int y, LImage* img);
		virtual Rect draw(int x, int y, LImage* img, const LColor& c);
		Rect draw(Point p, LImage* img);
		Rect draw(Point p, LImage* img, const LColor& c);

		virtual Rect drawText(int x, int y, int text);
		virtual Rect drawText(int x, int y, const char* text);
		Rect drawText(Point p, int text);
		Rect drawText(Point p, const char* text);

		virtual Rect drawTextRight(int x, int y, int text);
		virtual Rect drawTextRight(int x, int y, const char* text);
		Rect drawTextRight(Point p, int text);
		Rect drawTextRight(Point p, const char* text);

		virtual Rect drawTextCenter(int x, int y, int text);
		virtual Rect drawTextCenter(int x, int y, const char* text);
		Rect drawTextCenter(Point p, int text);
		Rect drawTextCenter(Point p, const char* text);

		virtual void clear();
		virtual void present();

		virtual void color(); // Restore default
		virtual void color(LColor c);

		virtual ~LDrawer();
};

