#include "View.h"
#define _CRT_SECURE_NO_WARNINGS

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void init_cursor()
{
	hidecursor();
	TextColor(240);
	GotoXY(X1 - 2, Y1); std::cout << cursor_char_l;
}

void delete_cursor()
{
	hidecursor();
	TextColor(255);
	GotoXY(X1 - 2, Y1); std::cout << cursor_char_l;
	TextColor(240);
}

void SET_COLOR(int color)
{
	WORD wColor;


	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

void CreateConsoleWindow(int a)
{
	HWND consoleWindow = GetConsoleWindow();
	RECT r;
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, a);
	GetWindowRect(consoleWindow, &r);
	MoveWindow(consoleWindow, 0, 0, 1320, 700, 1);
	ShowScrollBar(consoleWindow, SB_BOTH, FALSE);
}
void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void TextColor(int x)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}
void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void horizon(int column, int width, char middle, char out1, char out2)
{
	for (int i = 0; i < column; i++)
	{
		if (i == 0)
			std::cout << out1;
		else
			std::cout << middle;
		for (int j = 1; j <= width; j++)
			std::cout << HORIZONTAL_LINE;
	}
	std::cout << out2;
}
void vertical(int row, int height, int x, int y)
{
	int max = row * height;
	for (int i = 1; i < max; i++)
	{
		GotoXY(x, y + i);
		std::cout << VERTICAL_LINE;
	}
}
void DrawBoard(int row, int column, int x, int y, int width, int height)
{
	for (int i = 0; i <= column; i++)
	{
		vertical(row, height, x + i * (width + 1), y);
		Sleep(2);
	}
	for (int i = 0; i <= row; i++)
	{
		GotoXY(x, y + i * height);
		if (i == 0)
			horizon(column, width, TOP_CROSS, TOP_LEFT, TOP_RIGHT);
		else if (i == row)
			horizon(column, width, BOTTOM_CROSS, BOTTOM_LEFT, BOTTOM_RIGHT);
		else
			horizon(column, width, CROSS, LEFT_CROSS, RIGHT_CROSS);
		Sleep(2);
	}
}
void ShowGuide()
{
	hidecursor();
	TextColor(240);
	DrawBoard(1, 1, 3, 27, 47, 7);
	using std::setw;
	GotoXY(5, 29);
	std::cout << setw(7) << "[KEY]" << setw(15) << "ARROW KEY" << setw(10) << "ENTER" << setw(10) << "ESC";
	GotoXY(5, 32);
	std::cout << setw(7) << "[FUNCTION]" << setw(10) << "MOVE" << setw(13) << "CHOOSE" << setw(10) << "PAUSE";
	GotoXY(_X, _Y);
}

void SoundWin()
{
	PlaySound(TEXT("Win.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void Sound2(int S2)
{
	if (S2 == 1)
		PlaySound(TEXT("Sound2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void Draw_txt_noeffect(const char* file)
{
	FILE* h;
	int c;
	errno_t err;
	int printing = true;
	int running = true;
	GotoXY(0, 5);
	while (running)
	{
		err = fopen_s(&h, file, "r");
		hidecursor();
		while (printing)
		{
			SET_COLOR(240);
			c = fgetc(h);
			std::cout << (char)c;
			if (feof(h))
				printing = false;
		}
		fclose(h);
		_COMMAND = toupper(_getch());
		if (_COMMAND == esc_char)
		{
			running = false;
		}
	}
}

void Draw_txt(const char* filename, int color)
{
	TextColor(color);
	FILE* h;
	int c;
	errno_t err;
	err = fopen_s(&h, filename, "r");
	int printing = true;
	while (printing)
	{
		c = fgetc(h);
		std::cout << (char)c;
		if (feof(h))
			printing = false;
	}
	fclose(h);
	TextColor(240);
}

int cl(int mau) {
	if (mau == 1)
		return 256;
	else if (mau == 2)
		return 68;
	else if (mau == 3)
		return 187;
	else
		return mau;
}

void draw(int a, int k, int _y, int mau, int _x, int loop, int K) {
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	int P, n = 10;
	switch (a) {
	case 1:
		P = mau;
		SetConsoleTextAttribute(console_color, P);
		for (int i = 0; i <= 4; i++) {
			GotoXY(x_center_console + 2 + _y + 4 * k + K, y_center_console - n - i);
			printf(" ");
		}
		break;
	case 2:
		P = cl(mau);
		SetConsoleTextAttribute(console_color, P);
		GotoXY(x_center_console + 2 + 4 * k + K + _x, y_center_console - n - 3 + _y);
		printf("   ");
		break;
	case 4:
		P = cl(mau);
		SetConsoleTextAttribute(console_color, P);
		for (int j = 0; j < loop; j++) {
			for (int i = 0; i < 2; i++) {
				GotoXY(x_center_console - 17 + 11 * (k - 1) + _x + K, y_center_console - 5 - _y - i - 2 * j);
				printf(" ");
			}
		}
		break;
	case 5:
		P = cl(mau);
		SetConsoleTextAttribute(console_color, P);
		for (int j = 0; j < loop; j++) {
			for (int i = 0; i < 3; i++) {
				GotoXY(x_center_console - 17 + 11 * (k - 1) + _x + K, y_center_console - 5 - _y - i - 3 * j);
				printf(" ");
			}
		}
		break;
	case 6:
		P = cl(mau);
		SetConsoleTextAttribute(console_color, P);
		GotoXY(x_center_console - 17 + 11 * (k - 1) + _x + K, y_center_console - 5 - _y);
		printf(" ");
		break;
	case 7:
		P = mau;
		SetConsoleTextAttribute(console_color, P);
		int b = 0;
		if (_y == -1)
			b = 1;
		GotoXY(x_center_console + 2 + 4 * k + b + K, y_center_console - n - 3 + _y);
		printf("  ");
		break;
	}
}
void Draw(int a, int mau, int K) {
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	int P, n = 10, h = 0;
	GotoXY(x_center_console + K, y_center_console - n);
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
		GotoXY(x_center_console + 2 + K, y_center_console - n - 5);
		for (int i = 0; i <= 6; i++) {
			switch (i) {
			case 0:
				SetConsoleTextAttribute(console_color, P);
				printf("  ");
				GotoXY(x_center_console + 3 + K, y_center_console - 4 - n);
				printf(" ");
				break;
			case 1:
				draw(7, i, -1, P, 0, 0, K);
				draw(7, i, 3, P, 0, 0, K);
				GotoXY(x_center_console + 6 + K, y_center_console - 13);
				printf(" ");
				GotoXY(x_center_console + 7 + K, y_center_console - 12);
				printf(" ");
				GotoXY(x_center_console + 8 + K, y_center_console - 11);
				printf(" ");
				break;
			case 3:
				draw(1, i, 1, P, 0, 0, K);
				draw(2, i, -1, P, 0, 0, K);
				break;
			case 4:
				draw(1, i, 0, P, 0, 0, K);
				draw(2, i, 3, P, 0, 0, K);
				draw(1, i, 2, P, 0, 0, K);
				break;
			case 5:
				draw(1, i, 0, P, 0, 0, K);
				draw(2, i, -1, P, 0, 0, K);
				GotoXY(x_center_console + 24 + K, y_center_console - 13);
				printf(" ");
				break;
			case 6:
				draw(1, i, 0, P, 0, 0, K);
				draw(2, i, -1, P, 0, 0, K);
				draw(1, i, 2, P, 0, 0, K);
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
			GotoXY(x_center_console + h - 4 + K, y_center_console - n);
			for (int j = 1; j <= 6; j++) {
				int k = j;
				if (j >= 3) {
					k = j - t;
					t += 2;
				}
				SetConsoleTextAttribute(console_color, P);
				printf("  ");
				GotoXY(x_center_console - pow(-1, i) * k + h - 4 + K, y_center_console - j - n);
			}
			h = 2;
		}
		break;
	case 2:
		if (mau == 3)
			P = 255;
		for (int i = 0; i <= 1; i++) {
			GotoXY(x_center_console + h - 1 + K, y_center_console - n);
			for (int j = 1; j <= 6; j++) {
				SetConsoleTextAttribute(console_color, P);
				printf("  ");
				GotoXY(x_center_console - pow(-1, i) * j + h - 1 + K, y_center_console - j - n);
			}
			h = -5;
		}
		break;
	case 3:
		P = 240;
		SetConsoleTextAttribute(console_color, P);
	}
}
void DrawX_Turn()
{
	hidecursor();
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	Draw(1, 3, 36);
	Draw(2, 2, 36);
	Draw(0, 2, 36);
	GotoXY(_X, _Y);
}
void DrawO_Turn()
{
	hidecursor();
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	Draw(2, 3, 36);
	Draw(1, 1, 36);
	Draw(0, 1, 36);
	GotoXY(_X, _Y);
}

void DrawX()
{
	hidecursor();
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	Draw(1, 3, 2);
	Draw(2, 2, 2);
}

void DrawO()
{
	hidecursor();
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	Draw(2, 3, 10);
	Draw(1, 1, 10);
}

void title(int a) {
	switch (a) {
	case 1:
		draw(5, a, 2, 3, -1, 1, 0);
		draw(4, a, 5, 3, -1, 1, 0);
		draw(6, a, 1, 3, 0, 1, 0);
		draw(6, a, 7, 3, 0, 1, 0);
		draw(5, a, 2, 1, 0, 1, 0);
		draw(4, a, 5, 1, 0, 1, 0);
		draw(6, a, 0, 3, 1, 1, 0);
		draw(6, a, 8, 3, 1, 1, 0);
		draw(5, a, 1, 1, 1, 1, 0);
		draw(4, a, 4, 1, 1, 2, 0);
		draw(5, a, 0, 1, 2, 1, 0);
		draw(5, a, 6, 1, 2, 1, 0);
		draw(5, a, 3, 2, 2, 1, 0);
		for (int i = 3; i < 6; i++) {
			draw(4, a, 0, 1, i, 1, 0);
			draw(4, a, 7, 1, i, 1, 0);
		}
		draw(6, a, 2, 2, 3, 1, 0);
		draw(6, a, 6, 2, 3, 1, 0);
		draw(6, a, 2, 2, 4, 1, 0);
		draw(6, a, 6, 2, 4, 1, 0);
		draw(6, a, 2, 3, 5, 1, 0);
		draw(6, a, 6, 3, 5, 1, 0);
		draw(4, a, 0, 1, 6, 1, 0);
		draw(5, a, 6, 1, 6, 1, 0);
		draw(6, a, 2, 3, 6, 1, 0);
		draw(6, a, 5, 3, 6, 1, 0);
		draw(4, a, 1, 1, 7, 1, 0);
		draw(5, a, 5, 1, 7, 1, 0);
		draw(6, a, 0, 2, 7, 1, 0);
		draw(6, a, 8, 2, 7, 1, 0);
		draw(4, a, 1, 2, 8, 1, 0);
		draw(5, a, 5, 2, 8, 1, 0);
		break;
	case 2:
		for (int i = 0; i <= 1; i++) {
			draw(4, a, 0, 1, pow(-1, i) * 0 + 6 * i, 1, 0);
			draw(4, a, 0, 1, pow(-1, i) * 1 + 6 * i, 3, 0);
			draw(4, a, 2, 1, pow(-1, i) * 2 + 6 * i, 3, 0);
			draw(4, a, 0, 3 - i * 1, pow(-1, i) * (-1) + 6 * i, 1, 0);
			draw(4, a, 2, 3 - i * 1, pow(-1, i) * 0 + 6 * i, 2, 0);
			draw(4, a, 6, 3 - i * 1, pow(-1, i) * 1 + 6 * i, 1, 0);
			draw(6, a, 8, 3 - i * 1, pow(-1, i) * 2 + 6 * i, 1, 0);
			draw(4, a, 0, 2 + i * 1, pow(-1, i) * 2 + 6 * i, 1, 0);
		}
		draw(4, a, 7, 1, 3, 1, 0);
		draw(6, a, 3, 1, 3, 1, 0);
		break;
	case 3:
		draw(6, a, 0, 3, -1, 1, 0);
		draw(6, a, 0, 1, 0, 1, 0);
		draw(4, a, 1, 3, 0, 4, 0);
		for (int i = 1; i <= 2; i++) {
			draw(4, a, 0, 1, i, 4, 0);
			draw(5, a, 6, 1, i, 1, 0);
		}
		for (int i = 3; i <= 4; i++) {
			draw(6, a, 3, 1, i, 1, 0);
			draw(6, a, 8, 1, i, 1, 0);
		}
		draw(5, a, 0, 2, 3, 1, 0);
		draw(4, a, 4, 2, 3, 2, 0);
		draw(6, a, 2, 3, 4, 1, 0);
		draw(6, a, 7, 3, 4, 1, 0);
		draw(5, a, 2, 1, 5, 1, 0);
		draw(4, a, 7, 1, 5, 1, 0);
		draw(4, a, 0, 3, 5, 1, 0);
		draw(4, a, 5, 3, 5, 1, 0);
		draw(5, a, 0, 1, 6, 1, 0);
		draw(4, a, 4, 1, 6, 2, 0);
		draw(6, a, 3, 2, 6, 1, 0);
		draw(6, a, 8, 2, 6, 1, 0);
		draw(6, a, 0, 1, 7, 1, 0);
		draw(4, a, 1, 2, 7, 1, 0);
		draw(4, a, 4, 2, 7, 2, 0);
		draw(6, a, 0, 2, 8, 1, 0);
		break;
	case 4:
		for (int i = 0; i <= 1; i++) {
			draw(5, a, 2, 1, pow(-1, i) * 0 + 7 * i, 1, 0);
			draw(4, a, 5, 1, pow(-1, i) * 0 + 7 * i, 1, 0);
			draw(4, a, 1, 1, pow(-1, i) * 1 + 7 * i, 2, 0);
			draw(5, a, 5, 1, pow(-1, i) * 1 + 7 * i, 1, 0);
			draw(5, a, 0, 1, pow(-1, i) * 2 + 7 * i, 1, 0);
			draw(5, a, 6, 1, pow(-1, i) * 2 + 7 * i, 1, 0);
			draw(4, a, 0, 1, pow(-1, i) * 3 + 7 * i, 1, 0);
			draw(4, a, 7, 1, pow(-1, i) * 3 + 7 * i, 1, 0);

			draw(5, a, 2, 3 - 1 * i, pow(-1, i) * (-1) + 7 * i, 1, 0);
			draw(4, a, 5, 3 - 1 * i, pow(-1, i) * (-1) + 7 * i, 1, 0);
			draw(6, a, 1, 3 - 1 * i, pow(-1, i) * 0 + 7 * i, 1, 0);
			draw(6, a, 7, 3 - 1 * i, pow(-1, i) * 0 + 7 * i, 1, 0);
			draw(6, a, 0, 3 - 1 * i, pow(-1, i) * 1 + 7 * i, 1, 0);
			draw(6, a, 8, 3 - 1 * i, pow(-1, i) * 2 + 7 * i, 1, 0);
			draw(5, a, 3, 3 - 1 * i, pow(-1, i) * 2 + 7 * i, 1, 0);
			draw(6, a, 2, 3 - 1 * i, pow(-1, i) * 3 + 7 * i, 1, 0);
			draw(6, a, 6, 3 - 1 * i, pow(-1, i) * 3 + 7 * i, 1, 0);
		}
		break;
	}
}

void DrawWin(int P)
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, P);
	GotoXY(x_center_console - 14, y_center_console - 8);
	printf(" ");
	GotoXY(x_center_console - 9, y_center_console - 8);
	printf(" ");
	GotoXY(x_center_console + 26, y_center_console - 8);
	printf(" ");
	GotoXY(x_center_console + 30, y_center_console - 8);
	printf(" ");
	GotoXY(x_center_console + 23, y_center_console - 5);
	printf(" ");

	for (int j = 0; j < 6; j++)
		for (int i = 0; i < 4; i++)
			draw(4, 1, 2 - 2 * j, P, i + j, 1, 4);

	for (int j = 0; j < 5; j++)
		for (int i = 0; i < 4; i++)
			draw(5, 1, 0 - 2 * j, P, i + j, 1, 11);
	draw(7, 1, 5, P, 0, 1, -10);

	for (int j = 0; j < 3; j++)
		draw(4, 1, 0 - j, P, -j, 2, 20);

	for (int j = 0; j < 5; j++)
		for (int i = 0; i < 4; i++)
			draw(4, 1, 1 - 2 * j, P, -i - j, 1, 30);

	for (int j = 0; j < 2; j++)
		for (int i = 0; i < 6; i++)
		{
			GotoXY(x_center_console + 9 + i - 4 * j, y_center_console - 8 + 11 * j);
			printf(" ");
		}

	for (int j = 0; j < 2; j++)
		for (int i = 0; i < 2; i++)
			draw(4, 1, -3 - j, P, -i - j, 1, 36);

	for (int j = 0; j < 2; j++)
		for (int i = 0; i < 3; i++)
			draw(4, 1, -6 - 2 * j, P, -i - j, 1, 35);

	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 3; i++)
			draw(5, 1, -3 * j, P, i + j, 1, 37);

	for (int j = 0; j < 2; j++)
		for (int i = 0; i < 4; i++)
			draw(4, 1, 2 - 10 * j, P, i + 3 * j, 1, 36);

	for (int j = 0; j < 2; j++)
		for (int i = 0; i < 2; i++)
			draw(5, 1, 1 - 2 * j, P, -i - j, 1, 45);

	for (int j = 0; j < 2; j++)
		for (int i = 0; i < 2; i++)
			draw(4, 1, 2 - 4 * j, P, -i - 3 * j, 1, 46);

	SetConsoleTextAttribute(console_color, 255);
	GotoXY(x_center_console - 8, y_center_console + 3);
	printf(" ");
	GotoXY(x_center_console - 2, y_center_console + 3);
	printf(" ");
	GotoXY(x_center_console + 3, y_center_console - 5);
	printf(" ");
	GotoXY(x_center_console - 1, y_center_console + 3);
	printf(" ");
	GotoXY(x_center_console + 22, y_center_console + 3);
	printf(" ");
}
int DrawXwin()
{
	system("cls");
	int P = 4;
	SoundWin();
	GotoXY(60, 35);
	std::cout << "Press any key to continue";
	while (1) {
		hidecursor();
		if (_kbhit())
		{
			int h = _getch();
			if (h == 13)
				return 0;
			return 0;
			break;
		}
		if (P >= 300)
			P = 4;
		P += 16;
		HANDLE console_color;
		console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console_color, P);
		DrawWin(P);
		for (int j = 0; j < 14; j++)
			for (int i = 0; i < 7; i++)
				draw(4, 1, 3 - j, P, i + j, 1, -29);
		for (int j = 0; j < 2; j++)
			for (int i = 0; i < 11; i++)
				draw(4, 1, 4 - j * 16, P, i + j * 13, 1, -31);

		for (int j = 0; j < 5; j++)
			for (int i = 0; i < 2; i++)
				draw(4, 1, 3 - j, P, -i - j, 1, -11);
		for (int j = 0; j < 2; j++)
			for (int i = 0; i < 7; i++)
				draw(4, 1, 4 - 16 * j, P, -i - 16 * j, 1, -9);
		for (int j = 0; j < 2; j++)
			for (int i = 0; i < 2; i++)
				draw(4, 1, -6 - j, P, -i - j, 1, -23);
		for (int j = 0; j < 3; j++)
			for (int i = 0; i < 3; i++)
				draw(4, 1, -8 - j, P, -i - j, 1, -25);

		SetConsoleTextAttribute(console_color, 255);
		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i < 2; i++)
			{
				GotoXY(x_center_console - 48 + 10 * i + 13 * j, y_center_console - 9 + 15 * j);
				printf(" ");
				GotoXY(x_center_console - 32 + 6 * i - 16 * j, y_center_console - 9 + 15 * j);
				printf(" ");
			}
		}
		Sleep(100);
	}
}

int DrawOwin()
{
	system("cls");
	int P = 4;
	SoundWin();
	GotoXY(60, 35);
	std::cout << "Press any key to continue";
	while (1) {
		hidecursor();
		if (_kbhit())
		{
			int h = _getch();
			if (h == 13)
				return 0;
			return 0;
			break;
		}
		if (P >= 300)
			P = 4;
		P += 16;
		HANDLE console_color;
		console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console_color, P);
		DrawWin(P);
		for (int t = 0; t < 2; t++)
		{
			for (int h = 0; h < 2; h++)
				for (int j = 0; j < 3; j++)
					for (int i = 0; i < 3; i++)
						draw(4, 1, 5 - j * (-2 * h + 1) - 15 * h, P, (-i - j) * pow(-1, t), 1, -25 + 9 * t);
			for (int i = 0; i < 3; i++)
				draw(5, 1, -6, P, i, 3, -30 + 17 * t);
			draw(5, 1, -3, P, 0, 1, -31 + 21 * t);
			for (int j = 0; j < 2; j++)
				for (int i = 0; i < 2; i++)
					draw(7, 1, 2 + 16 * i, P, 0, 1, -47 + 2 * j * (1 - 2 * t) + 6 * t);
		}
		SetConsoleTextAttribute(console_color, 255);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				GotoXY(x_center_console - 44 + 13 * j, y_center_console - 11 + i * 16);
				printf(" ");
			}
		}
		Sleep(100);
	}
}

int DrawDraw()
{
	system("cls");
	int P = 4;
	SoundWin();
	GotoXY(60, 35);
	std::cout << "Press any key to continue";
	while (1) {
		hidecursor();
		if (_kbhit())
		{
			int h = _getch();
			if (h == 13)
				return 0;
			return 0;
			break;
		}
		if (P >= 300)
			P = 4;
		P += 16;
		HANDLE console_color;
		console_color = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console_color, P);
		for (int j = 0; j < 7; j++)
			for (int i = 0; i < 7; i++)
				draw(4, 1, 2 - 2 * j, P, -i - j, 2, -30);
		for (int j = 0; j < 2; j++)
			for (int i = 0; i < 11; i++)
				draw(4, 1, 4 - j * 16, P, i - j * 6, 1, -39);

		for (int j = 0; j < 3; j++)
			for (int i = 0; i < 8; i++)
				draw(4, 1, -9 - j, P, i - j * 6, 1, -24);

		for (int j = 0; j < 4; j++)
			for (int i = 0; i < 3; i++)
				draw(4, 1, -6 - j, P, i - 2 * j, 1, -13);

		for (int j = 0; j < 2; j++)
			for (int i = 0; i < 8; i++)
				draw(4, 1, 4 - j, P, i + j * 6, 1, -29);

		for (int j = 0; j < 5; j++)
			for (int i = 0; i < 2; i++)
				draw(4, 1, 3 - j, P, i + j, 1, -16);

		for (int i = 0; i < 2; i++)
			draw(4, 1, -5, P, i, 3, -12);

		for (int j = 0; j < 5; j++)
			for (int i = 0; i < 2; i++)
				draw(4, 1, -3 - j * 2, P, i - j, 2, -1);

		for (int j = 0; j < 2; j++)
			for (int i = 0; i < 5; i++)
				draw(4, 1, -1 - j * 10, P, i - 3 * j, 1, -3);

		for (int j = 0; j < 2; j++)
			for (int i = 0; i < 3; i++)
				draw(4, 1, -1 - i, P, -i + 2 * i * j, 1, 3 + j);

		for (int h = 0; h < 2; h++)
			for (int j = 0; j < 4; j++)
				for (int i = 0; i < 2; i++)
				{
					draw(4, 1, -1 - j * (1 - 2 * h) - 10 * h, P, -i - j, 1, 14);
					draw(4, 1, -1 - j * (1 - 2 * h) - 10 * h, P, i + j, 1, 18);
					draw(4, 1, -1 - 10 * h, P, i + j, 1, 15);
					draw(4, 1, -6, P, i + h * 11, 1, 10);
				}

		for (int j = 0; j < 2; j++)
			for (int i = 0; i < 2; i++)
				draw(4, 1, -5 - 6 * j, P, i + j, 3, 21);

		for (int j = 0; j < 6; j++)
			for (int i = 0; i < 4; i++)
				draw(4, 1, -1 - 2 * j, P, i + j, 1, 28);

		for (int j = 0; j < 5; j++)
			for (int i = 0; i < 4; i++)
				draw(5, 1, -3 - 2 * j, P, i + j, 1, 35);
		draw(7, 1, 8, P, 0, 1, 14);

		for (int j = 0; j < 3; j++)
			draw(4, 1, -3 - j, P, -j, 2, 44);

		SetConsoleTextAttribute(console_color, 255);
		GotoXY(x_center_console + 16, y_center_console + 6);
		printf(" ");
		GotoXY(x_center_console + 22, y_center_console + 6);
		printf(" ");
		GotoXY(x_center_console + 27, y_center_console - 2);
		printf(" ");
		GotoXY(x_center_console + 23, y_center_console + 6);
		printf(" ");
		Sleep(100);
	}
}

void SoundTink()
{
	PlaySound(TEXT("mario_03.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void nhapnhay(_POINT A[BOARD_SIZE][BOARD_SIZE], int a, int i, int j, int m)
{
	int t = 0, g = 0, k = 0, P = 240;
	SoundTink();
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, P);
	GotoXY(60, 35);
	std::cout << "Press any key to continue";
	while (1)
	{
		hidecursor();
		if (_kbhit())
		{
			int h = _getch();
			if (h == 13)
				break;
			break;
		}
		for (int h = 0; h < 5; h++)
		{
			if (m == 1)
				t = h;
			else if (m == 2)
				g = h;
			else if (m == 3)
			{
				t = h;
				g = h;
			}
			else
			{
				t = -h;
				g = h;
			}
			P++;
			if (P == 252)
				P = 240;
			GotoXY(A[i + t][j + g].x, A[i + t][j + g].y);
			SetConsoleTextAttribute(console_color, P);
			if (a == -1)
				std::cout << "x";
			if (a == 1)
				std::cout << "o";
			k++;
			Sleep(100);
		}
	}
}

void loading2()
{
	hidecursor();
	system("cls");
	HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 240);
	GotoXY(x_center_console - 2, y_center_console + 3);
	printf("LOADING ");
	DrawBoard(1, 1, 65, 16, 20, 3);
	for (int i = 0; i < 9; i++)
	{
		SetConsoleTextAttribute(console_color, 240);
		GotoXY(x_center_console + 7, y_center_console + 3);
		printf("      ");
		for (int j = 0; j < 3; j++)
		{
			GotoXY(x_center_console + 7 + j, y_center_console + 3);
			printf(". ");
			Sleep(100);
		}
		SetConsoleTextAttribute(console_color, 0);
		for (int j = 0; j < 2; j++)
		{
			GotoXY(x_center_console - 3 + 2 * i, y_center_console + j);
			printf("  ");
		}
	}
	SetConsoleTextAttribute(console_color, 240);
	Sleep(200);
}

void loading()
{
	HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	int a = 1;
	while (a)
	{
		int h = -1;
		for (int i = -13; i < 13; i++)
		{
			hidecursor();
			if (_kbhit())
			{
				int k = _getch();
				if (k == 0)
					break;
				SetConsoleTextAttribute(console_color, 240);
				break;
			}
			if (i == 0)
				h++;
			if (i < 0)
			{
				SetConsoleTextAttribute(console_color, 0);
				h++;
			}
			else
			{
				SetConsoleTextAttribute(console_color, 240);
				h--;
			}
			for (int j = 0; j < 19; j++)
			{
				GotoXY(x_center_console + 2 + h * 6, y_center_console + 1 + j);
				printf("      ");
				GotoXY(x_center_console + 2 - h * 6, y_center_console + 1 + j);
				printf("      ");
				GotoXY(x_center_console + 2 + h * 6, y_center_console + 1 - j);
				printf("      ");
				GotoXY(x_center_console + 2 - h * 6, y_center_console + 1 - j);
				printf("      ");
				Sleep(1);
			}
			Sleep(1);
		}
		a = 0;
	}
}