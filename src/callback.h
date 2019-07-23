#pragma once

template<class T> class Callback{
	public:
		virtual T call();
};

//especialy for cmake
#include "callback.cpp"

