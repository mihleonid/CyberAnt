#include "resourceset.h"

ResourceSet::ResourceSet(){
}
ResourceSet::ResourceSet(ResourceType t, int a){
	add(t, a);
}
bool ResourceSet::empty() const{
	auto beg=contain.begin();
	auto end=contain.end();
	for(auto i=beg; i!=end;i++){
		if(!empty(i->first)){
			return false;
		}
	}
	return true;
}
bool ResourceSet::empty(ResourceType type) const{
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

void ResourceSet::add(const ResourceSet& rset){
	auto beg=rset.contain.begin();
	auto end=rset.contain.end();
	for(auto i=beg; i!=end;i++){
		add(i->first, i->second);
	}
}
ResourceSet ResourceSet::sub(const ResourceSet& rset){
	auto beg=rset.contain.begin();
	auto end=rset.contain.end();
	ResourceSet res;
	for(auto i=beg; i!=end;i++){
		res.add(i->first, sub(i->first, i->second));
	}
	return res;
}
int ResourceSet::get(ResourceType t) const{
	if(contain.count(t)){
		return contain.at(t);
	}
	return 0;
}
bool operator==(const ResourceSet& a, const ResourceSet& b){
	return a.contain==b.contain;
}
bool operator!=(const ResourceSet& a, const ResourceSet& b){
	return a.contain!=b.contain;
}

