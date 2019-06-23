#pragma once
#include <vector>
class TO;
#include "resourceset.h"
#include "point.h"
#include "tubed.h"

class TO{
	public:
		ResourceSet have;
		TO(ResourceSet r);
		virtual const Tubed* where(std::vector<std::pair<const Tubed*, const Point&>>);//принимает доступных строений. отдаёт куда направить. nullptr=удалить
};

