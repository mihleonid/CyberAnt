#include "terminal.h"
#include "fieldtview.h"

void FieldTView::init(){
	T_CLEAR();
}
void FieldTView::loop(const Model* m){
	T_HOME();
	T_OPT(F_MAGENTA);
	T_OPT(B_GREEN);
	T_GOTO(50, 1);
	std::cout<<"CyberAnt v1.0 (Terminal graphics)";
	T_NL();
}
EventQueue FieldTView::getEvents(){
	return EventQueue();
}

