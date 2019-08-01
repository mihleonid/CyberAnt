#pragma once
#include <vector>
#include "to.h"

class Ask:public TO{
	private:
		std::vector<Tubed*> was;
		const Putable* target;
		ResourceSet ideal;
		bool asking;
		int life;
	public:
		Ask(const Putable* target, ResourceSet);
		Ask(Ask*);
		virtual void sended(Tubed*);
		virtual Tubed* where(const std::vector<Tubed*>&);
		virtual bool whant(const Putable*);
		virtual void proccessFO(FO*);
};

