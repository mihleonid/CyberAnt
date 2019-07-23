#pragma once
#include "resourceset.h"

class Resourced{//добывательно
	public:
		virtual bool empty() const;
		virtual ResourceSet mine(ResourceSet need);//добыть(сколько нужно)
};

