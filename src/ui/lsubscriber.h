#pragma once
#include <vector>
#include "leventtype.h"

class LEvent;
class Event;

class LSubscriber{
	public:
		virtual Event* applyEvent(LEvent*);
		virtual std::vector<LEventType> acceptedTypes();
};

