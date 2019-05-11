#pragma once

class Model{
	public:
		virtual void start();
		virtual void stop();

		virtual void loop();

		virtual void pause(); // Остановка с сохранением состояния
		virtual void resume();
};

