void rect_test(){
	Point p(5, 6);
	Rect r(p);
	Rect r2(p, p);

	assert(r==r2);
	assert(r.getA().getX()==5);
}

