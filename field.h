#pragma once
class Field;
#include "common.hpp"
#include "xstack.h"
#include "xstackiterator.h"
#include "fo.h"
#include "point.h"

class Field{
	private:
		FO** field=new FO*[BlocksX*BlocksY];
		XStack<FO*> all=XStack<FO*>(BlocksX*BlocksY);
	public:
		Field();

		FO* get(int x, int y);
		FO* get(const Point& p);

		void remove(int x, int y);
		void remove(const Point& p);
		void removeAll();

		void set(FO* f);

		Path getnb(int x, int y);
		Path getnb(const Point& p);

		/*
		Path findPath(int x, int y, int tx, int ty);
		Path findPath(const Point& start, const Point& end);
		*/

		XStackIterator<FO*> begin();
};

