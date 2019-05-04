#pragma once
class Event;
#include "foenum.h"
#include "point.h"

enum EventType{EBuild, ERemove, EUpgrade};

class Event{ // Нужно быдет изменить потом.
	private:
		Point pos;
		EventType type;
		FOWhat what;//ROxygen or BBase etc.
	public:
		Point getPos();
		FOWhat getWhat();
		EventType getType();
		Event(EventType t, Point p, FOWhat wh);
};

