#pragma once
#include <queue>
#include "event.h"

class EventQueue{
	private:
		std::queue<Event*> queue;
	public:
		Event* pop();
		void push(Event* e);
		void pipeM(EventQueue& eq); // Modificate
		void pipe(EventQueue eq);
		bool empty() const;
};

