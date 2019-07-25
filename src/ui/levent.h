#pragma once
#include <vector>
#include "leventtype.h"

class LEvent{
	private:
		LEventType type;
		bool prevented=false;
	public:
		LEvent(LEventType);
		LEventType getType() const;
		virtual ~LEvent();

		void prevent();
		bool getPrevented();

		static std::vector<LEventType> getAllTypes();
};

