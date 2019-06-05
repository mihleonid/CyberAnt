#pragma once
#include "xstack.h"

template<class T> class XStackIterator{
	private:
		XStack<T>* cur;
		int pos;
		int* deleted;
		int deletedTop;

		void checkRemove();
	public:
		XStackIterator(XStack<T>* current);
		void next();
		bool ended();
		T current();
		~XStackIterator();
};

