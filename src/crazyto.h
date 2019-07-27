#pragma once
#include <set>
#include "to.h"

class CrazyTO:public TO{
	private:
		std::set<const Tubed*> was;
	public:
		CrazyTO(ResourceSet);
		virtual const Tubed* where(const std::vector<std::pair<const Tubed*, const Point&>>&);//принимает доступных строений. отдаёт куда направить. nullptr=удалить
};

