#pragma once
#include "Handle.h"


int demnuocbot(_POINT B[25][25]);
struct Move {
    int x, y;
};
int evaluate(_POINT B[25][25]);
Move findfirstBestmove(_POINT B[25][25]);