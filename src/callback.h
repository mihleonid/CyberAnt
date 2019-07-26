#pragma once

template<class T> class Callback{
	public:
		virtual T call();
		virtual ~Callback();
};

//especialy for cmake
#include "callback.cpp"

