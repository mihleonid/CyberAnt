#pragma once
#include <vector>
class Tubed;
#include "resourceset.h"
#include "point.h"
#include "putable.h"

class TO{
	public:
		ResourceSet have;
		TO(ResourceSet r);
		virtual Tubed* where(const std::vector<Tubed*>&);//принимает доступных строений. отдаёт куда направить. nullptr=удалить
		virtual bool whant(const Putable*);
		virtual ~TO();
};

