#pragma once
enum FOType{FOBuilding=1, FOResource=2, FOPutable=4, FOStoraged=8, FOTubed=16};//флаги, что можно с ним делать
enum FOWhat{BBase, BIMine, BCanal, BRadio, RIron, ROxygen, RCristall};//radio = vishka
inline FOType operator|(FOType a, FOType b);

