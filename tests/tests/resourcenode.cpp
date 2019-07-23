void resourcenode_test(){
	Field* f=new Field;
	ResourceNode* rn=new ResourceNode(Point(3, 2), f, Iron);

	f->set(rn);
	assert(rn->getPos()==Point(3, 2));
	assert(f->get(rn->getPos())==((FO*)rn));

	rn->update();
	rn->setPos(Point(3, 4));

	assert(rn->getPos()==Point(3, 4));
	assert(f->get(3, 2)==nullptr);
	assert(f->get(3, 4)==rn);

	f->removeAll();
	delete f;
}

