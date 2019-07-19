#pragma once
#include "../point.h"

class Event;
class LEvent;
class LDrawer;

class LComponent{
	protected:
		Rect rect;
	public:
		LComponent(Rect p);
		Rect getRect() const;

		virtual void draw(LDrawer*);
		virtual Event* applyEvent(LEvent*);
};

