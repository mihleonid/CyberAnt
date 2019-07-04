#include "lmonocolor.h"

LMonoColor::LMonoColor():mr(0), mg(0), mb(0){
}
LMonoColor::LMonoColor(int c):mr(c), mg(c), mb(c){
}
LMonoColor::LMonoColor(int r, int g, int b):mr(r), mg(g), mb(b){
}
LMonoColor::LMonoColor(const LMonoColor& c):mr(c.r()), mg(c.g()), mb(c.b()){
}

int LMonoColor::r() const{
	return mr;
}
int LMonoColor::g() const{
	return mg;
}
int LMonoColor::b() const{
	return mb;
}
int LMonoColor::t(bool back) const{
	//TODO color recognize
	if((mr==139)&&(mg==0)&&(mb==139)){
		return ((back)?(B_MAGENTA):(F_MAGENTA));
	}
	if((mr==0)&&(mg==0)&&(mb==0)){
		return ((back)?(B_BLACK):(F_BLACK));
	}
	if((mr==255)&&(mg==255)&&(mb==255)){
		return ((back)?(B_WHITE):(F_WHITE));
	}
	if((mr==255)&&(mg==0)&&(mb==0)){
		return ((back)?(B_RED):(F_RED));
	}
	if((mr==0)&&(mg==255)&&(mb==0)){
		return ((back)?(B_GREEN):(F_GREEN));
	}
	if((mr==0)&&(mg==0)&&(mb==255)){
		return ((back)?(B_BLUE):(F_BLUE));
	}
	if(back){
		return B_BLACK;
	}
	return F_WHITE;
}

