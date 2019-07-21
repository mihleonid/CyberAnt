void rect_test(){
	Point p(5, 6);
	Rect r(p);
	Rect r2(p, p);

	assert(r==r2);
	assert(r.getA().getX()==5);
	assert(Rect(2, 4)==Rect(Point(2, 4), Point(2, 4)));
}

