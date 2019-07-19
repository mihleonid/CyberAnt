#pragma once
#include "leventtype.h"

class LEvent{
	private:
		LEventType type;
	public:
		LEvent(LEventType);
		LEventType getType() const;
		virtual ~LEvent();
};

