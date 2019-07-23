#pragma once
#include <vector>
class Tubed;
#include "resourceset.h"
#include "point.h"

class TO{
	public:
		ResourceSet have;
		TO(ResourceSet r);
		virtual const Tubed* where(std::vector<std::pair<const Tubed*, const Point&>>);//принимает доступных строений. отдаёт куда направить. nullptr=удалить
};
//TODO tubes

