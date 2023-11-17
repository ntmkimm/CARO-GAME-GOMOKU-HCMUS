#pragma once
#include "Handle.h"

int demnuocbot(_POINT A[BOARD_SIZE][BOARD_SIZE]);
struct Move {
    int x, y;
};
int evaluate(_POINT A[BOARD_SIZE][BOARD_SIZE]);
int evaluate1(_POINT A[BOARD_SIZE][BOARD_SIZE]);
Move findfirstBestmove(_POINT A[BOARD_SIZE][BOARD_SIZE]);
int Playwithcomputer(_POINT A[BOARD_SIZE][BOARD_SIZE], Menu menu[COL][MAX_ROW], PLAYER& PLAYER1, PLAYER& PLAYER2);