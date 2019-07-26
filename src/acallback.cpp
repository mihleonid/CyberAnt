#pragma once
#include "acallback.h"

template<class T, class A> T ACallback<T, A>::call(A a){
	return T();
}
template<class T, class A> ACallback<T, A>::~ACallback(){
}

