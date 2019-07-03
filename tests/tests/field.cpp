#include <set>
#include <map>

struct TMP_POINT_CMP{
	bool operator()(const Point& a, const Point& b){
		if(a.getY()<b.getY()){
			return true;
		}
		if(a.getY()==b.getY()){
			if(a.getX()<b.getX()){
				return true;
			}
		}
		return false;
	}
};
void field_test(){
	Field* tfield=new Field();

	// Test 1
	Base* b=new Base(Point(2, 3), tfield, 1);
	Base* b2=new Base(Point(3, 3), tfield, 1);

	assert(b->empty()==true);
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

	//Test 2
	Point o=Point(4, 5);
	Point n=Point(14, 15);
	Base* mb=new Base(o, tfield, 2);

	mb->setPos(n);
	assert(tfield->get(o)==nullptr);
	assert(tfield->get(n)==mb);

	std::set<Point, TMP_POINT_CMP> cnt; // Контрольный
	cnt.insert(Point(13, 15));
	cnt.insert(Point(15, 15));
	cnt.insert(Point(13, 16));
	cnt.insert(Point(14, 16));
	cnt.insert(Point(15, 16));
	cnt.insert(Point(13, 14));
	cnt.insert(Point(14, 14));
	cnt.insert(Point(15, 14));

	std::set<Point, TMP_POINT_CMP> ps;
	for(Point p:tfield->getnb(n)){
		ps.insert(p);
	}
	assert(ps==cnt);

	std::map<FO*, int> cnt2; // Контрольный
	cnt2[mb]=1;

	std::map<FO*, int> fs;
	int i=0;

	auto beg=tfield->begin();
	while(!beg.ended()){
		++i;
		++fs[beg.current()];
		beg.next();
	}
	assert(i==1);
	assert(fs==cnt2);
}

