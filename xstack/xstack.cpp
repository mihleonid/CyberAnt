#pragma once
#include <stdlib.h>
#include "xstack.h"

template<class T> XStack<T>::XStack(int size){
	arr=(T*)malloc(size*sizeof(T));
	dels=(int*)malloc(size*sizeof(int));
	maxs=size;
	top=0;
	delc=0;
}
template<class T> XStack<T>::~XStack(){
	free(arr);
	free(dels);
}
template<class T> int XStack<T>::push(T el){
	arr[top]=el;
	++top;
	return top-1;
}
template<class T> T XStack<T>::pop(){
	--top;
	return arr[top];
}
template<class T> T XStack<T>::operator[](int pos){
	return get(pos);
}
template<class T> T XStack<T>::get(int pos){
	return arr[pos];
}
template<class T> int XStack<T>::remove(int pos){
	--top;
	arr[pos]=arr[top];
	if(delc<maxs){
		dels[delc]=pos;
		delc++;
	}
	return pos;
}
template<class T> T XStack<T>::get(){
	return arr[top-1];
}
template<class T> int XStack<T>::size(){
	return top;
}
template<class T> bool XStack<T>::empty(){
	return size()==0;
}

