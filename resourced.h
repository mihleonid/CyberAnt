#pragma once
#include "resourceset.h"

class Resourced{//добывательно
	public:
		virtual bool empty();
		virtual Resourceset mine(Resourceset need);//добыть(сколько нужно)
};

