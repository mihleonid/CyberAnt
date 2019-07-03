void fo_test(){
	Point p(2, 3);
	FO* f=new FO(p, nullptr);

	assert(f->getPos()==p);
	assert(f->getField()==nullptr);
}

