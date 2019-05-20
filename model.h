#pragma once

class Model{
	public:
		virtual void loop();
		virtual void applyEvent(void* event);//TODO events
};

