#pragma once
#include "Handle.h"

//int min_count = INT_MAX;

struct MOVE { int x; int y; };
void set_game(_POINT board[][BOARD_SIZE + 2]);
void make_move(_POINT board[][BOARD_SIZE + 2], int x, int y, bool turn);
int win_check(_POINT board[][BOARD_SIZE + 2]);
int evaluation(_POINT board[][BOARD_SIZE + 2]);
bool on_border_check(_POINT board[][BOARD_SIZE + 2], int x, int y);
int minimax(_POINT board[][BOARD_SIZE + 2], bool turn, int depth, int alpha, int beta, int& count);
MOVE next_move(_POINT board[][BOARD_SIZE + 2], bool turn, int& min_count);