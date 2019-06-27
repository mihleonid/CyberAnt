#include "fieldcontroller.h"
#include "fieldmodel.h"
#include "fieldview.h"
#include "fieldtview.h"

FieldController::FieldController(){
	initialize(new FieldModel, new FieldView);
}
