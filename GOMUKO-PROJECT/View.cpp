#include "View.h"


void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
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

void showcursor()
{
	SET_COLOR(16);
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 5;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void CreateConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	RECT r;
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240); //240 for the white background (wowww)
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
	//width = 3; height = 2;
	for (int i = 0; i <= column; i++)
		vertical(row, height, x + i * (width + 1), y);
	for (int i = 0; i <= row; i++)
	{
		GotoXY(x, y + i * height);
		if (i == 0)
			horizon(column, width, TOP_CROSS, TOP_LEFT, TOP_RIGHT);
		else if (i == row)
			horizon(column, width, BOTTOM_CROSS, BOTTOM_LEFT, BOTTOM_RIGHT);
		else
			horizon(column, width, CROSS, LEFT_CROSS, RIGHT_CROSS);
	}
}
void ShowGuide()
{
	hidecursor();
	TextColor(240);
	DrawBoard(1, 1, 3, 27, 47, 7);
	using std::setw;
	GotoXY(5, 29);
	std::cout << setw(7) << "[KEY]" << setw(10) << char(27) << char(24) << char(25) << char(26) << setw(10) << "ENTER" << setw(10) << "ESC";
	GotoXY(5, 32);
	std::cout << setw(7) << "[FUNCTION]" << setw(10) << "MOVE" << setw(10) << "CHOOSE" << setw(10) << "PAUSE";
	GotoXY(_X, _Y);
	showcursor();
}
int Draw_txt(const char* file)
{
	FILE* f;
	int c, hex = 1;
	errno_t err;
	system("cls");
	while (1)
	{
		hidecursor();
		if (_kbhit())
		{
			int h = _getch();
			if (h == 13)
				return 0;
			return 0;
			break;
		}
		SET_COLOR(0);
		GotoXY(0, 5);
		err = fopen_s(&f, file, "r");
		for (int i = 1; i <= 17; i++)
			for (int j = 1; j <= 121; j++)
			{
				c = getc(f);
				if (c == '.')
					SET_COLOR(0);
				else if (hex % 2 == 1)
					SET_COLOR(7);
				else
					SET_COLOR(hex);
				std::cout << (char)c;
			}
		hex++;
		fclose(f);
	}
}
void Draw_txt_noeffect(const char* file)
{
	FILE* h;
	int c;
	errno_t err;
	int printting = true;
	GotoXY(0, 5);
	err = fopen_s(&h, file, "r");
	while (printting)
	{
		hidecursor();
		SET_COLOR(240);
		c = fgetc(h);
		std::cout << (char)c;
		if (feof(h))
			printting = false;
	}
	fclose(h);
}

int cl(int mau) {
	if (mau == 1)
		return 256;
	else if (mau == 2)
		return 68;
	else
		return 187;
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
		P = mau;
		SetConsoleTextAttribute(console_color, P);
		GotoXY(x_center_console + 2 + 4 * k + K, y_center_console - n - 3 + _y);
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
	showcursor();
}
void DrawO_Turn()
{
	hidecursor();
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	Draw(2, 3, 36);
	Draw(1, 1, 36);
	Draw(0, 1, 36);
	showcursor();
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

void SoundWin()
{
	PlaySound(TEXT("Win.wav"), NULL, SND_FILENAME);
}
void Sound2(int S2)
{
	if (S2 == 1)
		PlaySound(TEXT("Sound2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

