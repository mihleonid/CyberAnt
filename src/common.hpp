#pragma once

#define mmin(x, y) (((x)<(y))?(x):(y))
#define mmax(x, y) (((x)>(y))?(x):(y))
#define clamp(x, a, b) {x=mmin(x, b);x=mmax(x, a);}

#define BlocksX 30
#define BlocksY 30

// must be more than 1

#define ASSETS_DIR "./assets/"

