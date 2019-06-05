#include "xstackiterator.h"

template<class T> XStackIterator::XStackIterator(XStack* current){
	cur=current;
	deleted=new int[cur->maxs];
	deletedTop=0;
	pos=0;
	checkRemove();
}
template<class T> void XStackIterator::next(){
	checkRemove();
	if(deletedTop>0){
		--deletedTop;
	}else{
		++pos;
	}
}
template<class T> bool XStackIterator::ended(){
	checkRemove();
	if(deletedTop>0){
		return false;
	}
	return (pos==cur->top);
}
template<class T> T XStackIterator::current(){
	if(deletedTop>0){
		return cur->arr[deleted[deletedTop-1]];
	}
	return cur->arr[pos];
}
template<class T> void XStackIterator::checkRemove(){
	int delc=cur->delc;
	for(int i=0;i<delc;++i){
		if(cur->dels[i]<pos){
			deleted[deletedTop]=cur->dels[i];
			++deletedTop;
		}
	}
	cur->delc=0;
}
template<class T> void XStackIterator::~XStackIterator(){
	delete deleted;
}

