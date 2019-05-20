#pragma once

class View{
	public:
		virtual void loop(const Model* m);
		virtual void applyEvent(void* event);//TODO events
};

