#pragma once

class LComponent;

class LTalk{ // Class for communicating with LComponents
	public:
		virtual void talk(LComponent*)=0;
		virtual ~LTalk();
};
