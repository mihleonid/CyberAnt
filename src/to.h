#pragma once
#include <vector>
class Tubed;
class FO;
#include "resourceset.h"
#include "point.h"
#include "putable.h"

class TO{
	public:
		ResourceSet have;
		TO(ResourceSet r);
		virtual bool sended(Tubed* me); // Вызывает тот, кто принял.
		virtual Tubed* where(const std::vector<Tubed*>&); // принимает доступных строений. отдаёт куда направить. nullptr=удалить
		virtual bool whant(const Putable*);
		virtual void proccessFO(FO*);
		virtual ~TO();
};

