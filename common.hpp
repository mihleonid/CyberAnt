#pragma once

#define mmin(x, y) (((x)<(y))?(x):(y))
#define mmax(x, y) (((x)>(y))?(x):(y))
#define clamp(x, a, b) {x=mmin(x, b);x=mmax(x, a);}

#define BlocksX 5
#define BlocksY 5
// must be more than 1

