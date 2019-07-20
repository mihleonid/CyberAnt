#pragma once
#include "model.h"
#include "view.h"
#include "eventqueue.h"

class Controller{
	private:
		Model* model;
		View* view;
	protected:
		void initialize(Model* m, View* v);
	public:
		Model* getModel();
		View* getView();

		const Model* getModel() const;
		const View* getView() const;

		void loop();
		EventQueue eventLoop();

		virtual ~Controller();
};

