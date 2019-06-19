#pragma once
enum FOType{FOBuilding=1, FOResourced=2, FOPutable=4, FOStorage=8, FOTubed=16, FOAresource=42};//флаги, что можно с ним делать
// Building - можно строить, имеет уровень.
// Resourced - можно добыть ресурс.
// AResource - Resource с опцией автодобычи.
// Putable - можно давать что-либо.
// Storage - хранит. Можно безнаказно брать.
// Tubed - можно давать, но он не съест, пустит куда-либо.
enum FOWhat{BBase, BIMine, BCanal, BRadio, RIron, ROxygen, RCristall};//radio = vishka
inline FOType operator|(FOType a, FOType b);

