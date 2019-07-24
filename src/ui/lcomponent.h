#pragma once
#include "lsubscriber.h"

class Event;
class LEvent;
class LDrawer;

class LComponent:public LSubscriber{
	public:
		virtual ~LComponent();

		virtual void draw(LDrawer*);
		virtual Event* applyEvent(LEvent*);
};

