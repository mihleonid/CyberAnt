#pragma once

class Model{
	public:
		virtual void loop();
		virtual void applyEvent(Event* event);
};

