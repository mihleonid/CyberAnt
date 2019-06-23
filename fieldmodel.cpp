#include "fieldmodel.h"
#include "resourced.h"
#include "resourcenode.h"
#include "storage.h"
#include "fieldevent.h"
#include "base.h"
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
					//field.set(new Iron(x, y, &field)); // TODO FO, Resource node
					break;
			}
		}
	}
}
FieldModel::~FieldModel(){
	field.removeAll();
}

void FieldModel::applyEvent(Event* ce){
	FieldEvent* c=(FieldEvent*)ce;
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
					field.set(new ResourceNode(c->getPos(), &field, Iron));
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
				switch(Random::rnd(80000)){
					case 1:
						//field.set(new Iron(x, y, &field));
						break;
				}
				continue;
			}
			if(c->getType()&FOResourced){
				if((dynamic_cast<Resourced*>(c))->empty()){
					field.remove(x, y);
					continue;
				}
			}
			c->update();
		}
	}
}

