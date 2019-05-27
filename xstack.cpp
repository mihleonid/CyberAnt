#include "xstack.h"

template<class T> XStack::XStack(int size){
	arr=new T[size];
	dels=new int[size];
	maxs=size;
	top=0;
	delc=0;
}
template<class T> int XStack::push(T el){
	arr[top]=el;
	++top;
	return top-1;
}
template<class T> T XStack::pop(){
	--top;
	return arr[top];
}
template<class T> T XStack::operator[](int pos){
	return get(pos);
}
template<class T> T XStack::get(int pos){
	return arr[pos];
}
template<class T> int XStack::remove(int pos){
	--top;
	arr[pos]=arr[top];
	if(delc<maxs){
		dels[delc]=pos;
		delc++;
	}
	return pos;
}
template<class T> T XStack::get(){
	return arr[top-1];
}
template<class T> int XStack::size(){
	return top;
}

