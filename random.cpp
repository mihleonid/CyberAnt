#include <random>
#include "random.h"

void Random::init(){
	srand(2);
}
int Random::rnd(){
	return rand();
}
int Random::rnd(int max){
	return rnd(1, max);
}
int Random::rnd(int min, int max){
	return ((rnd()%(max-min+1))+min);
}

