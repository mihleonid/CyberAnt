#pragma once
#include <stdlib.h>
#include "xstackiterator.h"

template<class T> XStackIterator<T>::XStackIterator(XStack<T>* current){
	cur=current;
	deleted=(int*)malloc((cur->maxs)*sizeof(int));
	deletedTop=0;
	pos=0;
	checkRemove();
}
template<class T> void XStackIterator<T>::next(){
	checkRemove();
	if(deletedTop>0){
		--deletedTop;
	}else{
		++pos;
	}
}
template<class T> bool XStackIterator<T>::ended(){
	checkRemove();
	if(deletedTop>0){
		return false;
	}
	return (pos==cur->top);
}
template<class T> T XStackIterator<T>::current(){
	if(deletedTop>0){
		return cur->arr[deleted[deletedTop-1]];
	}
	return cur->arr[pos];
}
template<class T> void XStackIterator<T>::checkRemove(){
	int delc=cur->delc;
	for(int i=0;i<delc;++i){
		if(cur->dels[i]<pos){
			deleted[deletedTop]=cur->dels[i];
			++deletedTop;
		}
	}
	cur->delc=0;
}
template<class T> XStackIterator<T>::~XStackIterator(){
	free(deleted);
}

