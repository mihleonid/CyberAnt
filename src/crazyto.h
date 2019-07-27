#pragma once
#include <set>
#include "to.h"

class CrazyTO:public TO{
	private:
		std::set<const Tubed*> was;
	public:
		CrazyTO(ResourceSet);
		virtual Tubed* where(const std::vector<Tubed*>&);
		virtual bool whant(const Putable*);
};

