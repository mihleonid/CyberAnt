#pragma once
#include <utility>

class Event;
class LEvent;
class LDrawer;

class LComponent{
	public:
		virtual ~LComponent();

		virtual void draw(LDrawer*);
		virtual std::pair<Event*, bool> applyEvent(LEvent*); // Stop event
};

