#include "Handle.h"

int CheckBoard(_POINT A[BOARD_SIZE][BOARD_SIZE], int pX, int pY) 
{
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++) 
			if (A[i][j].x == pX && A[i][j].y == pY && A[i][j].c == 0) 
			{ // x toa do, y toa do. c trang thai
				if (_TURN == true) { A[i][j].c = -1; }
				else { A[i][j].c = 1; }
				return A[i][j].c;
			}
	return 0;
}

int row(_POINT A[BOARD_SIZE][BOARD_SIZE]) 
{
	int t = 1;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			switch (A[i][j].c)
			{
			case 1: if (A[i][j].c == 1 && A[i + 1][j].c == 1 && A[i + 2][j].c == 1 && A[i + 3][j].c == 1 && A[i + 4][j].c == 1) { t = 1; }
				  else { t = 0; };
				  break;
			case -1:  if (A[i][j].c == -1 && A[i + 1][j].c == -1 && A[i + 2][j].c == -1 && A[i + 3][j].c == -1 && A[i + 4][j].c == -1) { t = 1; }
				   else { t = 0; };
				   break;
			case 0: t = 0;  break;
			}
			if (t != 0) break;
		}
		if (t != 0) break;
	}
	return t;
}
int pole(_POINT A[BOARD_SIZE][BOARD_SIZE]) 
{
	int t = 1;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			switch (A[i][j].c) {
			case 1: if (A[i][j].c == 1 && A[i][j + 1].c == 1 && A[i][j + 2].c == 1 && A[i][j + 3].c == 1 && A[i][j + 4].c == 1) { t = 1; }
				  else { t = 0; };
				  break;
			case -1:  if (A[i][j].c == -1 && A[i][j + 1].c == -1 && A[i][j + 2].c == -1 && A[i][j + 3].c == -1 && A[i][j + 4].c == -1) { t = 1; }
				   else { t = 0; };
				   break;
			case 0: t = 0;  break;
			}
			if (t != 0) break;
		}
		if (t != 0) break;
	}
	return t;
}
int diag1(_POINT A[BOARD_SIZE][BOARD_SIZE]) 
{
	int t = 1;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			switch (A[i][j].c) {
			case 1: if (A[i][j].c == 1 && A[i + 1][j + 1].c == 1 && A[i + 2][j + 2].c == 1 && A[i + 3][j + 3].c == 1 && A[i + 4][j + 4].c == 1) { t = 1; }
				  else { t = 0; };
				  break;
			case -1:  if (A[i][j].c == -1 && A[i + 1][j + 1].c == -1 && A[i + 2][j + 2].c == -1 && A[i + 3][j + 3].c == -1 && A[i + 4][j + 4].c == -1) { t = 1; }
				   else { t = 0; };
				   break;
			case 0: t = 0;  break;
			}
			if (t != 0) break;
		}
		if (t != 0) break;
	}
	return t;
}
int diag2(_POINT A[BOARD_SIZE][BOARD_SIZE]) 
{
	int t = 1;
	for (int i = 0; i < BOARD_SIZE; i++) 
	{
		for (int j = 0; j < BOARD_SIZE; j++) 
		{
			switch (A[i][j].c) 
			{
			case 1: if (A[i][j].c == 1 && A[i - 1][j + 1].c == 1 && A[i - 2][j + 2].c == 1 && A[i - 3][j + 3].c == 1 && A[i - 4][j + 4].c == 1) { t = 1; }
				  else { t = 0; };
				  break;
			case -1:  if (A[i][j].c == -1 && A[i - 1][j + 1].c == -1 && A[i - 2][j + 2].c == -1 && A[i - 3][j + 3].c == -1 && A[i - 4][j + 4].c == -1) { t = 1; }
				   else { t = 0; };
				   break;
			case 0: t = 0;  break;
			}
			if (t != 0) break;
		}
		if (t != 0) break;
	}
	return t;
}

int wingame(_POINT A[BOARD_SIZE][BOARD_SIZE]) 
{
	if (row(A) == 1 || pole(A) == 1 || diag1(A) == 1 || diag2(A) == 1) return 1;
	else return 0;
}
int matrixfull(_POINT A[BOARD_SIZE][BOARD_SIZE]) 
{
	int t = 1;
	for (int i = 0; i < BOARD_SIZE; i++) 
	{
		for (int j = 0; j < BOARD_SIZE; j++) 
		{
			if (A[i][j].c == 0) t = 0;
			if (t == 0) break;
		}
		if (t == 0) break;
	}
	return t;
}
int TestBoard(_POINT A[BOARD_SIZE][BOARD_SIZE]) 
{
	if (matrixfull(A) == 1 && wingame(A) != 1) return 0; // ma tran day
	else if (wingame(A) == 1)
		return (_TURN == true ? -1 : 1);
	else
		return 2;
}

int ProcessFinish(_POINT A[BOARD_SIZE][BOARD_SIZE], int pWhoWin)
{
	GotoXY(0, A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);
	switch (pWhoWin) 
	{
	case -1:
		Draw_txt("WinX.txt");
		break;
	case 1:
		Draw_txt("WinO.txt");
		break;
	case 0:
		Draw_txt("Draw.txt");
		break;
	case 2:
		_TURN = !_TURN;
	}
	GotoXY(_X, _Y);
	return pWhoWin;
}

void MoveRight(_POINT A[BOARD_SIZE][BOARD_SIZE]) 
{
	if (_X < A[BOARD_SIZE - 1][BOARD_SIZE - 1].x)
	{
		_X += 4;
		GotoXY(_X, _Y);
	}
}
void MoveLeft(_POINT A[BOARD_SIZE][BOARD_SIZE]) 
{
	if (_X > A[0][0].x) 
	{
		_X -= 4;
		GotoXY(_X, _Y);
	}
}
void MoveDown(_POINT A[BOARD_SIZE][BOARD_SIZE]) 
{
	if (_Y < A[BOARD_SIZE - 1][BOARD_SIZE - 1].y)
	{
		_Y += 2;
		GotoXY(_X, _Y);
	}
}
void MoveUp(_POINT A[BOARD_SIZE][BOARD_SIZE]) 
{
	if (_Y > A[0][0].y) 
	{
		_Y -= 2;
		GotoXY(_X, _Y);

	}
}