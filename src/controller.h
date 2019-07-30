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
		EventQueue eventQueue; // Понадобиться при многопоточности (пока можно обойтись и без неё).
	protected:
		LWindow* win;
		void initialize(Model* m, View* v, LWindow* win); // А это вызывает реализация Controller a
		virtual LScene* generateUIScene();
	public:
		virtual void init(LWindow* win); // Этот метод будет вызывать GameController

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

