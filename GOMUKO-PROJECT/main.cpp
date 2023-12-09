#include "SetGame.h"
#include <iostream>
#include <Windows.h>

int X1;
int Y1;
int _COMMAND;
bool _TURN;
int _X, _Y;
int S1, S2;
int Color_X, Color_O;
int CountMoveP1, CountMoveP2;
int main()
{
	_POINT A[BOARD_SIZE][BOARD_SIZE];
	_POINT B[22][22];
	Menu menu[COL][MAX_ROW];
	PLAYER PLAYER1;
	PLAYER PLAYER2;
	X1 = x_center_console - 1;
	Y1 = y_center_console;
	_COMMAND = -1;
	_TURN = 1;
	_X = 0;
	_Y = 0;
	S1 = 1;
	S2 = 1;
	Color_X = 241;
	Color_O = 244;
	CountMoveP1 = 0;
	CountMoveP2 = 0;
	Sound2(S2);
	int running = 1;
	while (running)
	{
		running = MAINMENU_run(A, B, menu, PLAYER1, PLAYER2, MAIN_menu(menu));
		if (running == 0)
			break;
	}
}


