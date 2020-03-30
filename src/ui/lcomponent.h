#pragma once
#include <queue>
#include "lsubscriber.h"

class LEvent;
class LDrawer;
class LTalk;

class LComponent:public LSubscriber{
	private:
		std::queue<LTalk*> lts;
	public:
		virtual ~LComponent();

		virtual void draw(LDrawer*)=0;

		void applyTalk();
		void addTalk(LTalk* t);
};

