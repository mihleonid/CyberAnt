#pragma once
class LEvent;

class Subscriber{
	public:
		virtual void applyEvent(LEvent*);
};

