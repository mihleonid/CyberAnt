#include "random.h"
#include "resourcenode.h"
#include "resource.h"
#include "configurator.h"

ResourceNode::ResourceNode(Point pos, Field* f, ResourceType type):FO(pos, f){
	rtype=type;
	this->type=(FOResourced|FOStorage);
	int startVal;
	Configurator::configureResourceNode(rtype, add, addPossible, taxMin, taxMax, startVal);
	have.add(rtype, startVal);
}
void ResourceNode::update(){
	if(Random::rnd(addPossible)==1){
		have.add(rtype, add);
	}
	if(empty()){
		getField()->remove(getPos());
	}
}
bool ResourceNode::empty() const{
	return have.empty(rtype);
}
ResourceSet ResourceNode::mine(ResourceSet need){
	ResourceSet rest=have.sub(need);
	have.sub(rtype, Random::rnd(taxMin, taxMax));
	return rest;
}
LImage* ResourceNode::getImage(Assets* ass) const{
	return ass->getNode(Resource::typeToString(rtype))->applyColors(0xFFFFFF&((have.get(rtype)/4)*0x00000102));
}

