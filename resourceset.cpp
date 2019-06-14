#include "resourceset.h"

ResourceSet::ResourceSet(){
}
bool ResourceSet::isEmpty(ResourceType type){
	return (get(type)==0);
}
void ResourceSet::add(ResourceType t, int a){
	contain[t]+=a;
}
int ResourceSet::sub(ResourceType t, int a){
	if(contain[t]>a){
		contain[t]-=a;
		return 0;
	}else{
		int res=a-contain[t];
		contain[t]=0;
		return res;
	}
}
void ResourceSet::add(ResourceSet& rset){
	auto beg=rset.contain.begin();
	auto end=rset.contain.end();
	for(auto i=beg; i!=end;i++){
		add(i->first, i->second);
	}
}
ResourceSet ResourceSet::sub(ResourceSet& rset){
	auto beg=rset.contain.begin();
	auto end=rset.contain.end();
	ResourceSet res;
	for(auto i=beg; i!=end;i++){
		res.add(i->first, sub(i->first, i->second));
	}
	return res;
}
int ResourceSet::get(ResourceType t){
	return contain[t];
}

