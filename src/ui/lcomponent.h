#pragma once
#include "lsubscriber.h"
#include "../eventqueue.h"

class LEvent;
class LDrawer;
class LTalk;

class LComponent:public LSubscriber{
	private:
		std::queue<LTalk*> lts;
	public:
		virtual ~LComponent();

		virtual void draw(LDrawer*);
		virtual EventQueue applyEvent(LEvent*);

		void applyTalk();
		void addTalk(LTalk* t);
};

