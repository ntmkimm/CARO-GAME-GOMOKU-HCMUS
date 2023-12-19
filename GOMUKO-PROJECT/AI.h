#pragma once
#include "Handle.h"


int demnuocbot(_POINT B[25][25]);
struct Move {
    int x, y;
};
int evaluate(_POINT B[25][25]);
Move findfirstBestmove(_POINT B[25][25]);
int Playwithcomputer(_POINT A[BOARD_SIZE][BOARD_SIZE], _POINT B[22][22], Menu menu[COL][MAX_ROW], PLAYER& PLAYER1, PLAYER& PLAYER2);