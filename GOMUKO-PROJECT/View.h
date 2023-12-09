#pragma once
#ifndef _VIEW_
#define _VIEW_

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <fstream>
#include <mmsystem.h>
#include <iomanip>
#include <vector>

#pragma comment(lib,"winmm.lib")

enum { BOARD_SIZE = 12 };
enum { COL = 2 };
enum { MAX_ROW = 7 };
enum { x_center_console = 70 };
enum { y_center_console = 17 };

#define SIZE 12
#define LEFT 3
#define TOP 1
#define TOP_LEFT (char)201
#define BOTTOM_LEFT (char)200
#define TOP_RIGHT (char)187
#define BOTTOM_RIGHT (char)188
#define TOP_CROSS (char)203
#define BOTTOM_CROSS (char)202
#define CROSS (char)206
#define	LEFT_CROSS (char)204
#define RIGHT_CROSS (char)185
#define HORIZONTAL_LINE (char)205
#define VERTICAL_LINE (char) 186

#define arrow_up (char) 72
#define arrow_down (char) 80
#define arrow_left (char) 75
#define arrow_right (char) 77
#define enter_char (char) 13
#define esc_char (char) 27
#define cursor_char_l ">>"
#define cursor_char "-"


extern int X1;
extern int Y1;
extern int _COMMAND;
extern bool _TURN;
extern int _X, _Y;
extern int S1, S2;
extern int Color_X, Color_O;
extern int CountMoveP1, CountMoveP2;

struct _POINT { int x, y, c; };

struct Menu { int x = x_center_console, y = y_center_console; std::string c; }; //default coordinate of x and y

struct PLAYER
{
	std::string name;
	int countmove = 0;
	int win = 0;
};

void hidecursor();
void init_cursor();
void delete_cursor();
void SET_COLOR(int color);
void CreateConsoleWindow(int a);
void FixConsoleWindow();
void TextColor(int x);
void GotoXY(int x, int y);
void horizon(int column, int width, char middle, char out1, char out2);
void vertical(int row, int height, int x, int y);
void DrawBoard(int row, int column, int x, int y, int width, int height);
void ShowGuide();
void Draw_txt_noeffect(const char* file);
void draw(int a, int k, int _y, int mau, int _x, int loop, int K);
void Draw(int a, int mau, int K);
int cl(int mau);
void title(int a);
void DrawX_Turn();
void DrawO_Turn();
void DrawX();
void DrawO();
void SoundWin();
void Sound2(int S2);
int DrawXwin();
int DrawOwin();
int DrawDraw();
void nhapnhay(_POINT A[BOARD_SIZE][BOARD_SIZE], int a, int i, int j, int t);
void loading();
void loading2();
#endif