#pragma once
#include "Handle.h"


int demnuocbot(_POINT B[22][22]);
struct Move {
    int x, y;
};
int evaluate(_POINT B[22][22]);
//int evaluate1(_POINT A[BOARD_SIZE][BOARD_SIZE]);
Move findfirstBestmove(_POINT B[22][22]);
int Playwithcomputer(_POINT A[BOARD_SIZE][BOARD_SIZE], _POINT B[22][22], Menu menu[COL][MAX_ROW], PLAYER& PLAYER1, PLAYER& PLAYER2);