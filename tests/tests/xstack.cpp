#include <set>

void xstack_test(){
	XStack<int> xs(100);
	std::set<int> cnt; // Контрольный

	assert(xs.empty()==true);

	xs.push(1);
	xs.push(10);
	cnt.insert(1);
	cnt.insert(10);


	assert(xs.empty()==false);
	assert(xs.size()==2);
	assert(xs[0]==1);
	assert(xs[1]==10);

	std::set<int> is;
	for(XStackIterator<int> a(&xs);!a.ended();a.next()){
		is.insert(a.current());
	}
	assert(cnt==is);

	is.clear();
	for(XStackIterator<int> a(&xs);!a.ended();a.next()){
		is.insert(a.current());
	}
	assert(cnt==is);
	is.clear();

	int i=0;
	cnt.erase(1);
	XStackIterator<int> a(&xs);
	while(!a.ended()){
		int cur=a.current();
		if(i==0){
			++i;
			xs.remove(0);
			continue;
		}
		is.insert(cur);
		a.next();
	}
	assert(cnt==is);

	is.clear();
	for(XStackIterator<int> a(&xs);!a.ended();a.next()){
		is.insert(a.current());
	}
	assert(cnt==is);
	assert(xs.size()==1);
	assert(xs.empty()==false);
	assert(xs[0]==10);

	xs.push(100);
	xs.push(1000);
	cnt.insert(100);
	cnt.insert(1000);

	assert(xs.size()==3);
	assert(xs.empty()==false);
	assert(xs[0]==10);
	assert(xs[1]==100);
	assert(xs[2]==1000);

	is.clear();
	for(XStackIterator<int> a(&xs);!a.ended();a.next()){
		is.insert(a.current());
	}
	assert(cnt==is);

	xs.remove(1);
	cnt.erase(100);

	assert(xs.size()==2);
	assert(xs[0]==10);
	assert(xs[1]==1000);

	is.clear();
	for(XStackIterator<int> a(&xs);!a.ended();a.next()){
		is.insert(a.current());
	}
	assert(cnt==is);
}

