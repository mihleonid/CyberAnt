#include <list>
#include <math.h>
#include <cmath>
#include <algorithm>
#include "field.h"

Field::Field(){
	for(int i=0;i<BlocksX*BlocksY;i++){
		field[i]=nullptr;
	}
}

const FO* Field::get(int x, int y) const{
	return (const FO*)(field[y*BlocksX+x]);
}
const FO* Field::get(const Point& p) const{
	return (const FO*)get(p.getX(), p.getY());
}

FO* Field::get(int x, int y){
	return field[y*BlocksX+x];
}
FO* Field::get(const Point& p){
	return get(p.getX(), p.getY());
}

FO* Field::remove(const Point& p){
	return remove(p.getX(), p.getY());
}
FO* Field::remove(int x, int y){
	int i=y*BlocksX+x;
	FO* cur=field[i];
	field[i]=nullptr;
	return cur;
}
void Field::removeAll(){
	for(int x=0;x<BlocksX;++x){
		for(int y=0;y<BlocksY;++y){
			delete remove(x, y);
		}
	}
}

void Field::set(FO* f) {
	int i=(f->getPos().getY())*BlocksX+(f->getPos().getX());
	field[i]=f;
}

Path Field::getnb(const Point& p) const{
	return getnb(p.getX(), p.getY());
}
Path Field::getnb(int x, int y) const{
	Path result;
	if(x==0){
		//((x|x+1), **)
		if(y==0){
			//((x|x+1), (y|y+1))
			result.push_back(Point(0, 1));//x, y+1
			result.push_back(Point(1, 0));//x+1, y
			result.push_back(Point(1, 1));//x+1, y+1
		}else{
			//(x|x+1, y-1|y|(y+1 ?))
			if(y==BlocksY-1){
				//(x|x+1, y-1|y)
				result.push_back(Point(0, y-1));//x, y-1
				result.push_back(Point(1, y-1));//x+1, y-1
				result.push_back(Point(1, y));//x+1, y
			}else{
				//(x|x+1, y-1|y|y+1)
				result.push_back(Point(0, y-1));//x, y-1
				result.push_back(Point(0, y+1));//x, y+1
				result.push_back(Point(1, y-1));//x+1, y-1
				result.push_back(Point(1, y));//x+1, y
				result.push_back(Point(1, y+1));//x+1, y+1
			}
		}
	}else{
		//(x-1|x|(x+1 ?), **)
		if(x==BlocksX-1){
			//(x-1|x, **)
			if(y==0){
				//(x-1|x, y|y+1)
				result.push_back(Point(x-1, 0));//x-1, y
				result.push_back(Point(x, 1));//x, y+1
				result.push_back(Point(x-1, 1));//x-1, y+1
			}else{
				//(x-1|x, y-1|y|(y+1 ?))
				if(y==BlocksY-1){
					//(x-1|x, y-1|y)
					result.push_back(Point(x-1, y-1));
					result.push_back(Point(x, y-1));
					result.push_back(Point(x-1, y));
				}else{
					//(x-1|x, y-1|y|y+1)
					result.push_back(Point(x-1, y-1));
					result.push_back(Point(x, y-1));
					result.push_back(Point(x-1, y));
					result.push_back(Point(x-1, y+1));
					result.push_back(Point(x, y+1));
				}
			}
		}else{
			//(x-1|x|x+1, **)
			if(y==0){
				//((x-1|x|x+1), (y|y+1))
				result.push_back(Point(x-1, 0));//x-1, y
				result.push_back(Point(x-1, 1));//x-1, y+1
				result.push_back(Point(x, 1));//x, y+1
				result.push_back(Point(x+1, y));//x+1, y
				result.push_back(Point(x+1, 1));//x+1, y+1
			}else{
				//(x-1|x|x+1, y-1|y|(y+1 ?))
				if(y==BlocksY-1){
					//(x-1|x|x+1, y-1|y)
					result.push_back(Point(x-1, y-1));
					result.push_back(Point(x, y-1));
					result.push_back(Point(x+1, y-1));
					result.push_back(Point(x-1, y));
					result.push_back(Point(x+1, y));
				}else{
					//(x-1|x|x+1, y-1|y|y+1)
					result.push_back(Point(x, y-1));
					result.push_back(Point(x+1, y-1));
					result.push_back(Point(x+1, y));
					result.push_back(Point(x+1, y+1));
					result.push_back(Point(x, y+1));
					result.push_back(Point(x-1, y+1));
					result.push_back(Point(x-1, y));
					result.push_back(Point(x-1, y-1));
				}
			}
		}
	}
	return result;
}

