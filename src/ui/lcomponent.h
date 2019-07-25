#pragma once
#include "lsubscriber.h"
#include "../eventqueue.h"

class LEvent;
class LDrawer;

class LComponent:public LSubscriber{
	public:
		virtual ~LComponent();

		virtual void draw(LDrawer*);
		virtual EventQueue applyEvent(LEvent*);
};

