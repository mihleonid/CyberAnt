#pragma once
#include "resourceset.h"

class Resourced{//добывательно
	public:
		virtual bool empty();
		virtual ResourceSet mine(ResourceSet need);//добыть(сколько нужно)
};

