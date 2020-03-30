#pragma once
#include "../point.h"
#include "lcolor.h"

class LImage;

class LDrawer{
	public:
		virtual void drawRect(const Rect& r, const LColor& c)=0;
		virtual void drawRect(const Rect& r)=0;

		virtual Rect draw(int x, int y, LImage* img)=0;
		virtual Rect draw(int x, int y, LImage* img, const LColor& c)=0;
		Rect draw(Point p, LImage* img);
		Rect draw(Point p, LImage* img, const LColor& c);

		virtual Rect drawText(int x, int y, int text)=0;
		virtual Rect drawText(int x, int y, const char* text)=0;
		Rect drawText(Point p, int text);
		Rect drawText(Point p, const char* text);

		virtual Rect drawTextRight(int x, int y, int text)=0;
		virtual Rect drawTextRight(int x, int y, const char* text)=0;
		Rect drawTextRight(Point p, int text);
		Rect drawTextRight(Point p, const char* text);

		virtual Rect drawTextCenter(int x, int y, int text)=0;
		virtual Rect drawTextCenter(int x, int y, const char* text)=0;
		Rect drawTextCenter(Point p, int text);
		Rect drawTextCenter(Point p, const char* text);

		virtual void clear()=0;
		virtual void clear(const LColor& c)=0;
		virtual void present()=0;

		virtual void color()=0; // Restore default
		virtual void color(const LColor& c)=0;

		virtual ~LDrawer();
};

