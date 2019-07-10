#include "lmonocolor.h"

LMonoColor::LMonoColor():mr(0), mg(0), mb(0){
}
LMonoColor::LMonoColor(int c):mr(c), mg(c), mb(c){
}
LMonoColor::LMonoColor(int c, bool hex){
	mb=c&0xFF;
	mg=(c&0xFF00)/0x100;
	mr=(c&0xFF0000)/0x10000;
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
int LMonoColor::hex() const{
	return mb+mg*0x100+mr*0x10000;
}
bool LMonoColor::eq(int a, int b, int eps) const{
	int d=a-b;
	if(d<0){
		d=-d;
	}
	if(d<eps){
		return true;
	}
	return false;
}
int LMonoColor::t(bool back, int eps) const{
	if(eps<1){
		eps=1;
	}
	if(eq(mr, 139, eps)&&eq(mg, 0, eps)&&eq(mb, 139, eps)){
		return ((back)?(B_MAGENTA):(F_MAGENTA));
	}
	if(eq(mr, 0, eps)&&eq(mg, 0, eps)&&eq(mb, 0, eps)){
		return ((back)?(B_BLACK):(F_BLACK));
	}
	if(eq(mr, 255, eps)&&eq(mg, 255, eps)&&eq(mb, 255, eps)){
		return ((back)?(B_WHITE):(F_WHITE));
	}
	if(eq(mr, 255, eps)&&eq(mg, 0, eps)&&eq(mb, 0, eps)){
		return ((back)?(B_RED):(F_RED));
	}
	if(eq(mr, 0, eps)&&eq(mg, 255, eps)&&eq(mb, 0, eps)){
		return ((back)?(B_GREEN):(F_GREEN));
	}
	if(eq(mr, 0, eps)&&eq(mg, 0, eps)&&eq(mb, 255, eps)){
		return ((back)?(B_BLUE):(F_BLUE));
	}
	if(back){
		return B_BLACK;
	}
	return F_WHITE;
}

