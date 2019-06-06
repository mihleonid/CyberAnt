#include "resourcenode.h"
#include "resource.h"
#include "configurator.h"

ResourceNode::ResourceNode(int xx, int yy, Field* f, ResourceType type):FO(xx, yy, f){
	rtype=type;
	this->type=(FOResourced|FOStorage);
	int startVal;
	Configurator::configureResourceNode(rtype, add, addPossible, taxMin, taxMax, startVal);
	have.add(rtype, startVal);
}
virtual void ResourceNode::update(){
	if(Random::rnd(addPossible)==1){
		have.add(rtype, add);
	}
}
virtual bool ResourceNode::empty(){
	return have.isEmpty(rtype);
}
virtual ResourceSet ResourceNode::mine(ResourceSet need){
	ResourceSet rest=have.sub(need);
	need.sub(rest);
	have.sub(Random.rnd(taxMin, taxMax));
	return need;
}
virtual SDL_Texture* ResourceNode::getTexture(Assets ass*, SDL_Renderer* ren){
	return ass->rtex(ass->getNode(Resource::typeToString(rtype)), ren, have.get(rtype));
}

