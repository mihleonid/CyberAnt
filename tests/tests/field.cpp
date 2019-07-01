void field_test(){
	Field* tfield=new Field();
	Base* b=new Base(Point(2, 3), tfield, 1);
	Base* b2=new Base(Point(3, 3), tfield, 1);

	assert(b->empty()==false);//change TODO
	tfield->set(b);
	b->put(ResourceSet(Iron, 3));

	assert(b->empty()==false);
	assert(tfield->get(2, 3)->getPos()==Point(2, 3));
	assert(tfield->get(2, 3)->getField()==tfield);
	assert(tfield->get(2, 3)->getWhat()==BBase);

	tfield->set(b2);
	assert(tfield->get(3, 3)->getPos()==Point(3, 3));
	assert(tfield->get(3, 3)->getField()==tfield);
	assert(tfield->get(3, 3)->getWhat()==BBase);

	delete (tfield->remove(2, 3));
	assert(tfield->get(2, 3)==nullptr);
	assert(tfield->get(3, 3)!=nullptr);
	assert(tfield->get(3, 3)->getPos()==Point(3, 3));
	assert(tfield->get(3, 3)->getField()==tfield);
	assert(tfield->get(3, 3)->getWhat()==BBase);

	tfield->removeAll();
	assert(tfield->get(2, 3)==nullptr);
	assert(tfield->get(3, 3)==nullptr);
	assert(tfield->get(8, 3)==nullptr);
}

