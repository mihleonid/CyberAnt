#pragma once

class View{
	public:
		virtual void loop();
		virtual void applyEvent(void* event);//TODO events
};

