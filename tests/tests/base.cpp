void base_test(){
	Field* f=new Field;
	Base* b=new Base(Point(2, 3), f, 3);
	f->set(b);

	ResourceSet add(Iron, 3);
	ResourceSet need(Iron, 4);

	b->put(add);
	assert(b->empty()==false);

	need=b->mine(need);
	assert(need==ResourceSet(Iron, 1));
	assert(b->empty()==true);
	assert(b->getLevel()==3);

	f->removeAll();
	delete f;
}

