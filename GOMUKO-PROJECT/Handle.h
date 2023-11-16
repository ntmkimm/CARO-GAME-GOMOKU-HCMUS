#pragma once
#ifndef _HANDLE_
#define _HANDLE_
#include "View.h"

int CheckBoard(_POINT A[BOARD_SIZE][BOARD_SIZE], int pX, int pY);

int row(_POINT A[BOARD_SIZE][BOARD_SIZE]);
int pole(_POINT A[BOARD_SIZE][BOARD_SIZE]);
int diag1(_POINT A[BOARD_SIZE][BOARD_SIZE]);
int diag2(_POINT A[BOARD_SIZE][BOARD_SIZE]);
int wingame(_POINT A[BOARD_SIZE][BOARD_SIZE]);
int matrixfull(_POINT A[BOARD_SIZE][BOARD_SIZE]);
int TestBoard(_POINT A[BOARD_SIZE][BOARD_SIZE]);
int ProcessFinish(_POINT A[BOARD_SIZE][BOARD_SIZE], int pWhoWin, PLAYER& PLAYER1, PLAYER& PLAYER2);
void MoveRight(_POINT A[BOARD_SIZE][BOARD_SIZE]);
void MoveLeft(_POINT A[BOARD_SIZE][BOARD_SIZE]);
void MoveDown(_POINT A[BOARD_SIZE][BOARD_SIZE]);
void MoveUp(_POINT A[BOARD_SIZE][BOARD_SIZE]);

#endif

