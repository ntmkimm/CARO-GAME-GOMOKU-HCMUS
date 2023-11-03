#include "View.h"

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
void CreateConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	RECT r;
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240); //240 for the white background (wowww)
	GetWindowRect(consoleWindow, &r);
	MoveWindow(consoleWindow, 0, 0, 1320, 700, 1);
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
void DrawBoard(int row, int column, int x, int y)
{
	int width = 3, height = 2;
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

void Draw_txt(const char* file)
{
	FILE* f;
	int c, hex = 1;
	errno_t err;
	system("cls");
	while (1)
	{
		int h = 0;
		if (_kbhit())
		{
			break;
		}
		SET_COLOR(7);
		GotoXY(0, 5);
		err = fopen_s(&f, file, "r");
		for (int i = 1; i <= 17; i++)
			for (int j = 1; j <= 121; j++)
			{
				c = fgetc(f);
				if (c == '.')
					SET_COLOR(0);
				else if (hex % 2 == 1)
					SET_COLOR(7);
				else
					SET_COLOR(hex);
				printf("%c", c);
			}
		hex++;
		Sleep(10);
		system("cls");
		fclose(f);
	}
}
void Draw_txt_(std::string file)
{
	std::string str;
	std::fstream File;

	File.open(file, std::ios::in);

	std::getline(File, str);

	File.close();
}


