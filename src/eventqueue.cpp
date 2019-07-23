#include "eventqueue.h"

Event* EventQueue::pop(){
	Event* n=queue.front();
	queue.pop();
	return n;
}
void EventQueue::push(Event* e){
	if(e!=nullptr){
		queue.push(e);
	}
}
void EventQueue::pipeM(EventQueue& eq){
	while(!(eq.empty())){
		push(eq.pop());
	}
}
void EventQueue::pipe(EventQueue eq){
	while(!(eq.empty())){
		push(eq.pop());
	}
}
bool EventQueue::empty() const{
	return queue.empty();
}

