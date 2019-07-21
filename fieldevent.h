#pragma once
#include "event.h"
#include "foenum.h"
#include "point.h"

enum FieldEventType{EBuild, ERemove, EUpgrade, EPrefab};

class FieldEvent:public Event{
	private:
		Point pos;
		FieldEventType type;
		FOWhat what;//ROxygen or BBase etc.
	public:
		Point getPos() const;
		FOWhat getWhat() const;
		FieldEventType getType() const;
		FieldEvent(FieldEventType t, Point p, FOWhat wh);
};

