#pragma once
#include "event.h"
#include "foenum.h"
#include "point.h"

enum FieldEventType{EBuild, ERemove, EUpgrade};

class FieldEvent:public Event{
	private:
		Point pos;
		FieldEventType type;
		FOWhat what;//ROxygen or BBase etc.
	public:
		Point getPos();
		FOWhat getWhat();
		FieldEventType getType();
		Event(EventType t, Point p, FOWhat wh);
		virtual bool forGameController();
};

