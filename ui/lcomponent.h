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
		virtual ~LComponent();

		virtual void draw(LDrawer*);
		virtual std::pair<Event*, bool> applyEvent(LEvent*); // Stop event
};

