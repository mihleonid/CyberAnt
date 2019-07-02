#include "eventqueue.h"

Event* EventQueue::pop(){
	Event* n=queue.front();
	queue.pop();
	return n;
}
void EventQueue::push(Event* e){
	queue.push(e);
}
bool EventQueue::empty() const{
	return queue.empty();
}

