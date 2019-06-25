#include "fieldcontroller.h"
#include "fieldmodel.h"
#include "fieldview.h"
#include "fieldtview.h"

FieldController::FieldController(bool sdl):Controller::Controller(sdl){
	initialize(new FieldModel, new FieldView, new FieldTView);
}
