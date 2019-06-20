#include <random>
#include "random.h"

void Random::init(){
	srand(time(0));
	current=0;
	cyclesdone=CYCLES+1;
}
void Random::recycle(){
	if(cyclesdone>CYCLES){
		current=0;
		cyclesdone=0;
		for(int i=0;i<SIZE;++i){
			rands[i]=rand();
		}
	}else{
		++current;
		if(current>=SIZE){
			current=0;
			++cyclesdone;
		}
	}
}
int Random::rnd(){
	recycle();
	return rands[current];
}
int Random::rnd(int max){
	return rnd(1, max);
}
int Random::rnd(int min, int max){
	return ((rnd()%(max-min+1))+min);
}

