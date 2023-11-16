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

void SoundWin() {
	PlaySound(TEXT("Win.wav"), NULL, SND_FILENAME);
}

int ProcessFinish(_POINT A[BOARD_SIZE][BOARD_SIZE], int pWhoWin)
{
	GotoXY(0, A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);
	switch (pWhoWin)
	{
		GotoXY(5, 5);
	case -1:
		PlaySound(0, 0, 0);
		Draw(3, 0);
		Draw_txt("WinX.txt");
		SoundWin();
		break;
	case 1:
		PlaySound(0, 0, 0);
		Draw(3, 0);
		Draw_txt("WinO.txt");
		SoundWin();
		break;
	case 0:
		PlaySound(0, 0, 0);
		Draw(3, 0);
		Draw_txt("Draw.txt");
		SoundWin();
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

int cl(int mau) {
	if (mau == 1)
		return 256;
	else if (mau == 2)
		return 68;
	else
		return 187;
}

void draw(int a, int k, int _y, int mau, int _x, int loop) {
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	int P, n = 10;
	switch (a) {
	case 1:
		P = mau;
		SetConsoleTextAttribute(console_color, P);
		for (int i = 0; i <= 4; i++) {
			GotoXY(x_center_console + 2 + _y + 4 * k, y_center_console - n - i);
			printf(" ");
		}
		break;
	case 2:
		P = mau;
		SetConsoleTextAttribute(console_color, P);
		GotoXY(x_center_console + 2 + 4 * k, y_center_console - n - 3 + _y);
		printf("   ");
		break;
	case 4:
		P = cl(mau);
		SetConsoleTextAttribute(console_color, P);
		for (int j = 0; j < loop; j++) {
			for (int i = 0; i < 2; i++) {
				GotoXY(x_center_console - 17 + 11 * (k - 1) + _x, y_center_console - 5 - _y - i - 2 * j);
				printf(" ");
			}
		}
		break;
	case 5:
		P = cl(mau);
		SetConsoleTextAttribute(console_color, P);
		for (int j = 0; j < loop; j++) {
			for (int i = 0; i < 3; i++) {
				GotoXY(x_center_console - 17 + 11 * (k - 1) + _x, y_center_console - 5 - _y - i - 3 * j);
				printf(" ");
			}
		}
		break;
	case 6:
		P = cl(mau);
		SetConsoleTextAttribute(console_color, P);
		GotoXY(x_center_console - 17 + 11 * (k - 1) + _x, y_center_console - 5 - _y);
		printf(" ");
		break;
	case 7:
		P = mau;
		SetConsoleTextAttribute(console_color, P);
		int b = 0;
		if (_y == -1)
			b = 1;
		GotoXY(x_center_console + 2 + 4 * k + b, y_center_console - n - 3 + _y);
		printf("  ");
		break;
	}
}
void Draw(int a, int mau) {
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	int P, n = 10, h = 0;
	GotoXY(x_center_console, y_center_console - n);
	if (Color_X == 241)
	{
		if (mau == 1)
			P = 68;
		else if (mau == 2)
			P = 17;
	}
	else if (Color_X == 245)
	{
		if (mau == 1)
			P = 102;
		else if (mau == 2)
			P = 221;
	}
	else
	{
		if (mau == 1)
			P = 34;
		else if (mau == 2)
			P = 204;
	}
	switch (a) {
	case 0:
		GotoXY(x_center_console + 2, y_center_console - n - 5);
		for (int i = 0; i <= 6; i++) {
			switch (i) {
			case 0:
				SetConsoleTextAttribute(console_color, P);
				printf("  ");
				GotoXY(x_center_console + 3, y_center_console - 4 - n);
				printf(" ");
				break;
			case 1:
				draw(7, i, -1, P, 0, 0);
				draw(7, i, 3, P, 0, 0);
				GotoXY(x_center_console + 6, y_center_console - 13);
				printf(" ");
				GotoXY(x_center_console + 7, y_center_console - 12);
				printf(" ");
				GotoXY(x_center_console + 8, y_center_console - 11);
				printf(" ");
				break;
			case 3:
				draw(1, i, 1, P, 0, 0);
				draw(2, i, -1, P, 0, 0);
				break;
			case 4:
				draw(1, i, 0, P, 0, 0);
				draw(2, i, 3, P, 0, 0);
				draw(1, i, 2, P, 0, 0);
				break;
			case 5:
				draw(1, i, 0, P, 0, 0);
				draw(2, i, -1, P, 0, 0);
				GotoXY(x_center_console + 24, y_center_console - 13);
				printf(" ");
				break;
			case 6:
				draw(1, i, 0, P, 0, 0);
				draw(2, i, -1, P, 0, 0);
				draw(1, i, 2, P, 0, 0);
				break;
			case 7:

				break;
			}
		}
		break;
	case 1:
		if (mau == 3)
			P = 255;
		for (int i = 0; i <= 1; i++) {
			int t = 1;
			GotoXY(x_center_console + h - 4, y_center_console - n);
			for (int j = 1; j <= 6; j++) {
				int k = j;
				if (j >= 3) {
					k = j - t;
					t += 2;
				}
				SetConsoleTextAttribute(console_color, P);
				printf("  ");
				GotoXY(x_center_console - pow(-1, i) * k + h - 4, y_center_console - j - n);
			}
			h = 2;
		}
		break;
	case 2:
		if (mau == 3)
			P = 255;
		for (int i = 0; i <= 1; i++) {
			GotoXY(x_center_console + h - 1, y_center_console - n);
			for (int j = 1; j <= 6; j++) {
				SetConsoleTextAttribute(console_color, P);
				printf("  ");
				GotoXY(x_center_console - pow(-1, i) * j + h - 1, y_center_console - j - n);
			}
			h = -5;
		}
		break;
	case 3:
		P = 240;
		SetConsoleTextAttribute(console_color, P);
	}
}

void title(int a) {
	switch (a) {
	case 1:
		draw(5, a, 2, 3, -1, 1);
		draw(4, a, 5, 3, -1, 1);
		draw(6, a, 1, 3, 0, 1);
		draw(6, a, 7, 3, 0, 1);
		draw(5, a, 2, 1, 0, 1);
		draw(4, a, 5, 1, 0, 1);
		draw(6, a, 0, 3, 1, 1);
		draw(6, a, 8, 3, 1, 1);
		draw(5, a, 1, 1, 1, 1);
		draw(4, a, 4, 1, 1, 2);
		draw(5, a, 0, 1, 2, 1);
		draw(5, a, 6, 1, 2, 1);
		draw(5, a, 3, 2, 2, 1);
		for (int i = 3; i < 6; i++) {
			draw(4, a, 0, 1, i, 1);
			draw(4, a, 7, 1, i, 1);
		}
		draw(6, a, 2, 2, 3, 1);
		draw(6, a, 6, 2, 3, 1);
		draw(6, a, 2, 2, 4, 1);
		draw(6, a, 6, 2, 4, 1);
		draw(6, a, 2, 3, 5, 1);
		draw(6, a, 6, 3, 5, 1);
		draw(4, a, 0, 1, 6, 1);
		draw(5, a, 6, 1, 6, 1);
		draw(6, a, 2, 3, 6, 1);
		draw(6, a, 5, 3, 6, 1);
		draw(4, a, 1, 1, 7, 1);
		draw(5, a, 5, 1, 7, 1);
		draw(6, a, 0, 2, 7, 1);
		draw(6, a, 8, 2, 7, 1);
		draw(4, a, 1, 2, 8, 1);
		draw(5, a, 5, 2, 8, 1);
		break;
	case 2:
		for (int i = 0; i <= 1; i++) {
			draw(4, a, 0, 1, pow(-1, i) * 0 + 6 * i, 1);
			draw(4, a, 0, 1, pow(-1, i) * 1 + 6 * i, 3);
			draw(4, a, 2, 1, pow(-1, i) * 2 + 6 * i, 3);
			draw(4, a, 0, 3 - i * 1, pow(-1, i) * (-1) + 6 * i, 1);
			draw(4, a, 2, 3 - i * 1, pow(-1, i) * 0 + 6 * i, 2);
			draw(4, a, 6, 3 - i * 1, pow(-1, i) * 1 + 6 * i, 1);
			draw(6, a, 8, 3 - i * 1, pow(-1, i) * 2 + 6 * i, 1);
			draw(4, a, 0, 2 + i * 1, pow(-1, i) * 2 + 6 * i, 1);
		}
		draw(4, a, 7, 1, 3, 1);
		draw(6, a, 3, 1, 3, 1);
		break;
	case 3:
		draw(6, a, 0, 3, -1, 1);
		draw(6, a, 0, 1, 0, 1);
		draw(4, a, 1, 3, 0, 4);
		for (int i = 1; i <= 2; i++) {
			draw(4, a, 0, 1, i, 4);
			draw(5, a, 6, 1, i, 1);
		}
		for (int i = 3; i <= 4; i++) {
			draw(6, a, 3, 1, i, 1);
			draw(6, a, 8, 1, i, 1);
		}
		draw(5, a, 0, 2, 3, 1);
		draw(4, a, 4, 2, 3, 2);
		draw(6, a, 2, 3, 4, 1);
		draw(6, a, 7, 3, 4, 1);
		draw(5, a, 2, 1, 5, 1);
		draw(4, a, 7, 1, 5, 1);
		draw(4, a, 0, 3, 5, 1);
		draw(4, a, 5, 3, 5, 1);
		draw(5, a, 0, 1, 6, 1);
		draw(4, a, 4, 1, 6, 2);
		draw(6, a, 3, 2, 6, 1);
		draw(6, a, 8, 2, 6, 1);
		draw(6, a, 0, 1, 7, 1);
		draw(4, a, 1, 2, 7, 1);
		draw(4, a, 4, 2, 7, 2);
		draw(6, a, 0, 2, 8, 1);
		break;
	case 4:
		for (int i = 0; i <= 1; i++) {
			draw(5, a, 2, 1, pow(-1, i) * 0 + 7 * i, 1);
			draw(4, a, 5, 1, pow(-1, i) * 0 + 7 * i, 1);
			draw(4, a, 1, 1, pow(-1, i) * 1 + 7 * i, 2);
			draw(5, a, 5, 1, pow(-1, i) * 1 + 7 * i, 1);
			draw(5, a, 0, 1, pow(-1, i) * 2 + 7 * i, 1);
			draw(5, a, 6, 1, pow(-1, i) * 2 + 7 * i, 1);
			draw(4, a, 0, 1, pow(-1, i) * 3 + 7 * i, 1);
			draw(4, a, 7, 1, pow(-1, i) * 3 + 7 * i, 1);

			draw(5, a, 2, 3 - 1 * i, pow(-1, i) * (-1) + 7 * i, 1);
			draw(4, a, 5, 3 - 1 * i, pow(-1, i) * (-1) + 7 * i, 1);
			draw(6, a, 1, 3 - 1 * i, pow(-1, i) * 0 + 7 * i, 1);
			draw(6, a, 7, 3 - 1 * i, pow(-1, i) * 0 + 7 * i, 1);
			draw(6, a, 0, 3 - 1 * i, pow(-1, i) * 1 + 7 * i, 1);
			draw(6, a, 8, 3 - 1 * i, pow(-1, i) * 2 + 7 * i, 1);
			draw(5, a, 3, 3 - 1 * i, pow(-1, i) * 2 + 7 * i, 1);
			draw(6, a, 2, 3 - 1 * i, pow(-1, i) * 3 + 7 * i, 1);
			draw(6, a, 6, 3 - 1 * i, pow(-1, i) * 3 + 7 * i, 1);
		}
		break;
	}
}