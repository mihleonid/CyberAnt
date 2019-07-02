#pragma once
#include <queue>
#include "event.h"

class EventQueue{
	private:
		std::queue<Event*> queue;
	public:
		Event* pop();
		void push(Event* e);
		bool empty() const;
};

