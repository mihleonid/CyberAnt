void resourcenode_test(){
	Field* f=new Field;
	ResourceNode* rn=new ResourceNode(Point(3, 2), f, Iron);

	f->set(rn);
	assert(rn->getPos()==Point(3, 2));
	assert(f->get(rn->getPos())==((FO*)rn));

	rn->update();

	f->removeAll();
	delete f;
}

