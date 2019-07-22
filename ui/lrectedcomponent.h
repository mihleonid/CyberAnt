#pragma once
#include "../point.h"
#include "lcomponent.h"

class Event;
class LEvent;
class LDrawer;

class LRectedComponent:public LComponent{
	protected:
		Rect rect;
	public:
		LRectedComponent(const Rect& p);
		Rect getRect() const;
};

