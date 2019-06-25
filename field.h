#pragma once
class Field;
#include "common.hpp"
#include "fo.h"
#include "point.h"

class Field{
	private:
		FO** field=new FO*[BlocksX*BlocksY];
	public:
		Field();

		FO* get(int x, int y);
		FO* get(const Point& p);

		const FO* get(int x, int y) const;
		const FO* get(const Point& p) const;

		FO* remove(int x, int y);
		FO* remove(const Point& p);
		void removeAll(); // deletes

		void set(FO* f);

		Path getnb(int x, int y) const;
		Path getnb(const Point& p) const;
};

