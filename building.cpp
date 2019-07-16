#include "building.h"

Building::Building(Point p, Field* currF, int lvl):FO(p, currF), level(lvl){
}
LColor Building::levelColor() const{
	return LColor((0x000000|((15*level)*0x00010000)), true);
}

