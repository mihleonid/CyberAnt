#include "fieldcontroller.h"
#include "fieldmodel.h"
#include "fieldview.h"

FieldController::FieldController(){
	initialize(new FieldModel, new FieldView);
}
