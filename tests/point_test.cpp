void point_test(){
	Point p;
	assert(p.getX()==0);
	assert(p.getY()==0);

	Point a(p);
	assert(a==p);

	Point b(2, 3);
	assert(b.getX()==2);
	assert(b.getY()==3);

	Point c(b);
	assert(b==c);
	assert(a!=c);
}

