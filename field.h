#pragma once
class Field;
#include "common.hpp"
#include "xstack/xstack.h"
#include "xstack/xstackiterator.h"
#include "fo.h"
#include "point.h"

class Field{
	private:
		FO** field=new FO*[BlocksX*BlocksY];
		XStack<FO*> all=XStack<FO*>(BlocksX*BlocksY);
	public:
		Field();
		~Field();

		FO* get(int x, int y);
		FO* get(const Point& p);

		const FO* get(int x, int y) const;
		const FO* get(const Point& p) const;

		FO* remove(int x, int y);
		FO* remove(const Point& p);
		void removeAll();

		void set(FO* f);
		void set(FO* f, const Point& prevPos);
		void set(FO* f, int px, int py);

		Path getnb(int x, int y) const;
		Path getnb(const Point& p) const;

		/*
		Path findPath(int x, int y, int tx, int ty);
		Path findPath(const Point& start, const Point& end);
		*/

		XStackIterator<FO*> begin();
};

