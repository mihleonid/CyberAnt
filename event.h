#pragma once

class Event{
	public:
		virtual bool forGameController() const;
		virtual ~Event();
};

