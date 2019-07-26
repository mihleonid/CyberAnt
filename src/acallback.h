#pragma once

template<class T, class A> class ACallback{
	public:
		virtual T call(A);
		virtual ~ACallback();
};

//especialy for cmake
#include "acallback.cpp"

