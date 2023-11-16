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
int ProcessFinish(_POINT A[BOARD_SIZE][BOARD_SIZE], int pWhoWin);

void MoveRight(_POINT A[BOARD_SIZE][BOARD_SIZE]);
void MoveLeft(_POINT A[BOARD_SIZE][BOARD_SIZE]);
void MoveDown(_POINT A[BOARD_SIZE][BOARD_SIZE]);
void MoveUp(_POINT A[BOARD_SIZE][BOARD_SIZE]);
void draw(int a, int k, int _y, int mau, int _x, int loop);
void Draw(int a, int mau);
int cl(int mau);
void title(int a);

#endif

