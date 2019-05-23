#pragma once
#include <queue>

class EventQueue{
	private:
		std::queue<Event*> queue;
	public:
		Event* pop();
		void push(Event* e);
		bool empty();
};

