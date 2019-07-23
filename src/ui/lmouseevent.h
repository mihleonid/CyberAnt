#pragma once
#include "leventtype.h"
#include "levent.h"
#include "../point.h"

enum LMouseEventType{
	MOUSE_Move,
	BUTTON_Up,
	BUTTON_Down,
};
class LMouseEvent:public LEvent{
	private:
		LMouseEventType mtype;
		Point pos;
	public:
		LMouseEvent(LMouseEventType, Point);
		LMouseEventType getMouseType() const;
		Point getPos() const;
};


