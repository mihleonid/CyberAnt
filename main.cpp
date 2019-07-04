#include <iostream>
#include "gamecontroller.h"

int main(int argc, char* argv[]){
#ifdef DEBUG
	std::cout<<"Starting..."<<std::endl;
#endif
	GameController ctl;
#ifdef DEBUG
	std::cout<<"Exiting..."<<std::endl;
#endif
	return 0;
}

