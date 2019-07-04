#pragma once
#include "../point.h"
#include "lcolor.h"

class LDrawer{
	public:
		virtual Rect drawText(int x, int y, int text);
		virtual Rect drawText(int x, int y, const char* text);

		virtual Rect drawTextRight(int x, int y, int text);
		virtual Rect drawTextRight(int x, int y, const char* text);

		virtual Rect drawTextCenter(int x, int y, int text);
		virtual Rect drawTextCenter(int x, int y, const char* text);
		virtual void clear();
		virtual void present();

		virtual void color(); // Restore default
		virtual void color(LColor c);
};

