#include "fieldcontroller.h"
#include "fieldmodel.h"
#include "fieldview.h"

FieldController::FieldController(LWindow* win){
	initialize(new FieldModel, new FieldView, win);
}

