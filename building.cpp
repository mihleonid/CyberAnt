#include "building.h"

Building::Building(Point p, Field* currF, int lvl):FO(p, currF), level(lvl){
}
LColor Building::levelColor() const{
	if(level>51){
		return LColor((0x000000|((15*(level-51))*0x00010001)), true);
	}
	if(level>34){
		return LColor((0x000000|((15*(level-34))*0x00010100)), true);
	}
	if(level>17){
		return LColor((0x000000|((15*(level-17))*0x00000100)), true);
	}
	return LColor((0x000000|((15*level)*0x00010000)), true);
}
void Building::upgrade(){
	++level;
}
int Building::getLevel() const{
	return level;
}

