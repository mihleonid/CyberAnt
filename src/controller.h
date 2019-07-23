#pragma once
#include "model.h"
#include "view.h"
#include "eventqueue.h"

class LWindow;
class LScene;

class Controller{
	private:
		Model* model;
		View* view;
		LScene* scn;
	protected:
		LWindow* win;
		void initialize(Model* m, View* v, LWindow* win);
		virtual LScene* generateUIScene();
	public:
		Model* getModel();
		View* getView();
		LScene* getLScene();

		const Model* getModel() const;
		const View* getView() const;
		const LScene* getLScene() const;

		void loop();
		EventQueue eventLoop();

		virtual ~Controller();
};

