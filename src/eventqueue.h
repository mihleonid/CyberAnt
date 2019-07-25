#pragma once
#include <queue>
class Event;

class EventQueue{
	private:
		std::queue<Event*> queue;
	public:
		EventQueue();
		EventQueue(Event* e);
		Event* pop();
		void push(Event* e);
		void pipeM(EventQueue& eq); // Modificate
		void pipe(EventQueue eq);
		bool empty() const;
};

