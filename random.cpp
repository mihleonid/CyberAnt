#include <random>
#include "random.h"

static void Random::init(){
	srand();
}
static int Random::rnd(){
	return rand();
}
static int Random::rnd(int max){
	return rnd(1, max);
}
static int Random::rnd(int min, int max){
	return ((rnd()%(max-min+1))+min);
}

