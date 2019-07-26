#pragma once
#include "callback.h"

template<class T> T Callback<T>::call(){
	return T();
}
template<class T> Callback<T>::~Callback(){
}

