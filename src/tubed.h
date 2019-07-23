#pragma once
#include "resourceset.h"
#include "to.h"

//класс нужный, но пока не готовый, сначала TO (TubeObject)
class Tubed{//можно давать и ничего ресурсу не будет
	public:
		void send(ResourceSet give);//отправить ресурссет
		virtual void send(TO* give);//отправить TO
};

