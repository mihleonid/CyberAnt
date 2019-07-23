#include "leventsender.h"
#include "levent.h"
#include "lsubscriber.h"

EventQueue LEventSender::send(LEvent* e){
	EventQueue q;
	for(int i=0;i<subs[e->getType()].size();++i){
		q.push(subs[e->getType()][i]->applyEvent(e));
		if(e->getPrevented()){
			break;
		}
	}
	return q;
}
void LEventSender::subscribe(LSubscriber* s, LEventType t){
	subs[t].push_back(s);
}
void LEventSender::unsubscribe(LSubscriber* s, LEventType t){
	std::vector<LSubscriber*> v;
	for(int i=0;i<subs[t].size();++i){
		if(subs[t][i]!=s){
			v.push_back(s);
		}
	}
	subs[t]=v;
}
void LEventSender::subscribe(LSubscriber* s){
	std::vector<LEventType> accepted=s->acceptedTypes();
	for(int i=0;i<accepted.size();++i){
		subscribe(s, accepted[i]);
	}
}
void LEventSender::unsubscribe(LSubscriber* s){
	for(auto i=subs.begin();i!=subs.end();++i){
		unsubscribe(s, i->first);
	}
}

