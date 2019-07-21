#include "mine.h"
#include "fieldmodel.h"
#include "resourced.h"
#include "resourcenode.h"
#include "storage.h"
#include "fieldevent.h"
#include "base.h"
#include "building.h"
#include "random.h"
#include "foenum.h"
#include "resource.h"

FieldModel::FieldModel(){
	rset=new ResourceSet();
	rset->add(Oxygen, 100);
	rset->add(Iron, 20);
	rset->add(Cristall, 10);
	for(int x=0;x<BlocksX;x++){
		for(int y=0;y<BlocksY;y++){
			switch(Random::rnd(20)){
				case 1:
					field.set(new ResourceNode(Point(x, y), &field, Iron));
					break;
			}
		}
	}
}
FieldModel::~FieldModel(){
	field.removeAll();
	if(!baseBuilded){
		delete rset;
	}
}

void FieldModel::applyEvent(Event* ce){
	FieldEvent* c=(FieldEvent*)ce;
	if(c->getType()==EUpgrade){
		if(field.get(c->getPos())!=nullptr){
			FO* f=field.get(c->getPos());
			if(f->getType()&FOBuilding){
				((Building*)f)->upgrade();
			}
		}
	}
	if(c->getType()==EBuild){
		if(field.get(c->getPos())==nullptr){
			switch(c->getWhat()){
				case BBase:
					if(!baseBuilded){
						Base* b=new Base(c->getPos(), &field, 0);
						field.set((FO*)b);
						((Storage*)b)->have=*rset;
						delete rset;
						rset=&(dynamic_cast<Storage*>(b)->have);
						baseBuilded=true;
					}
					break;
				case BIMine:
					field.set(new Mine(c->getPos(), &field, 0, Iron));
					break;
			}
		}
	}
}

void FieldModel::loop(){
	for(int x=0;x<BlocksX;x++){ // Вот тут надо проходить через все (чтобы создавать новые случайные).
		for(int y=0;y<BlocksY;y++){
			FO* c=field.get(x, y);
			if(c==nullptr){
				switch(Random::rnd(8000)){
					case 1:
						field.set(new ResourceNode(Point(x, y), &field, Iron));
						break;
				}
				continue;
			}
			if(c->getType()&FOResourced){
				if((dynamic_cast<Resourced*>(c))->empty()){
					field.remove(x, y);
					delete c;
					continue;
				}
			}
			c->update();
		}
	}
}

