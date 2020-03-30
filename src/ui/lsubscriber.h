#pragma once
#include <vector>
#include "leventtype.h"
#include "../eventqueue.h"

class LEvent;

class LSubscriber{
	public:
		virtual EventQueue applyEvent(LEvent*)=0;
		virtual std::vector<LEventType> acceptedTypes();
};
