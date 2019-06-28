#pragma once
#include "../ldrawer.h"
#include "../../point.h"

class LTDrawer:public LDrawer{
	private:
		// Created for optimization
		Rect drawText(int x, int y, const char* text, int len);
		Rect drawTextRight(int x, int y, const char* text, int len);
		Rect drawTextCenter(int x, int y, const char* text, int len);
	public:
		virtual Rect drawText(int x, int y, int text);
		virtual Rect drawText(int x, int y, const char* text);

		virtual Rect drawTextRight(int x, int y, int text);
		virtual Rect drawTextRight(int x, int y, const char* text);

		virtual Rect drawTextCenter(int x, int y, int text);
		virtual Rect drawTextCenter(int x, int y, const char* text);
};
