void point_test(){
	Point p;
	assert(p.getX()==0);
	assert(p.getY()==0);

	Point a(p);
	assert(a==p);

	Point b(2, 3);
	assert(b.getX()==2);
	assert(b.getY()==3);
	assert(b.setX(4)==Point(4, 3));
	assert(b.setY(5)==Point(2, 5));

	assert(b.setDY(5)==Point(2, 8));
	assert(b.setDX(5)==Point(7, 3));

	b.setDXM(-2);
	b.setDYM(-200);
	assert(b==Point(0, -197));

	b.setXM(-2);
	b.setYM(-200);
	assert(b==Point(-2, -200));

	Point c(b);
	assert(b==c);
	assert(a!=c);
}

