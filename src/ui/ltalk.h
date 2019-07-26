#pragma once

class LComponent;

class LTalk{ // Class for communicating with LComponents
	public:
		virtual void talk(LComponent*);
};

