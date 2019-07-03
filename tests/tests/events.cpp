void events_test(){
	EventQueue eq;
	assert(eq.empty());

	Event* e=new Event;
	assert(e->forGameController()==false);

	Event* ee=new GameControllerEvent(0);
	assert(ee->forGameController()==true);

	eq.push(e);
	eq.push(ee);
	assert(eq.pop()==e);
	assert(eq.pop()==ee);

	delete e;
	delete ee;
}

