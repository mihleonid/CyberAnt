void resourceset_test(){
	// Test 1
	ResourceSet myset;

	assert(myset.empty()==true);
	myset.add(Iron, 3);


	assert(myset.get(Iron)==3);
	assert(myset.empty(Iron)==false);
	assert(myset.empty()==false);

	int rrs=myset.sub(Iron, 1);
	assert(rrs==0);
	assert(myset.get(Iron)==2);

	ResourceSet tosub(Iron, 4);

	assert(tosub.empty()==false);
	assert(tosub.get(Iron)==4);

	ResourceSet rest=myset.sub(tosub);

	assert(myset.empty()==true);
	assert(tosub.get(Iron)==4);
	assert(rest.get(Iron)==2);

	// Test 2
	ResourceSet a(Iron, 2);
	ResourceSet b(Iron, 3);

	assert(a!=b);
	b.sub(Iron, 1);
	assert(a==b);
}

