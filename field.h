#pragma once
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
		FO* get(int x, int y);
		FO* get(Point p);

		void remove(int x, int y);
		void remove(Point p);

		void set(FO* f);

		Path getnb(int x, int y);
		Path getnb(Point p);

		Path findPath(int x, int y, int tx, int ty);
		Path findPath(Point start, Point end);

		XStackIterator<FO*> begin();
};

