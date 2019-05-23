#pragma once

class View{
	public:
		virtual void loop(const Model* m);
		virtual EventQueue getEvents();
};

