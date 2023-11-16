#pragma once
#ifndef _VIEW_
#define _VIEW_

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <fstream>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")

enum { BOARD_SIZE = 12 };
enum { COL = 2 };
enum { MAX_ROW = 7 };
enum { x_center_console = 70 };
enum { y_center_console = 17 };

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
#define cursor_char (char) 16

extern int X1;
extern int Y1;
extern int _COMMAND;
extern bool _TURN;
extern int _X, _Y;
extern int S1, S2;
extern int Color_X, Color_O;


struct _POINT { int x, y, c; };

struct Menu { int x = x_center_console, y = y_center_console; std::string c; }; //default coordinate of x and y

struct PLAYER
{
	std::string name;

	inline bool operator==(PLAYER& other) const //use this operator to check player's existence, if false return true, inline for not trigger linker error
	{
		if (this->name == other.name)
			return true;
		return false; //make comparation of this player name with other players' name in the File
	}

};

void hidecursor();
void showcursor();
void SET_COLOR(int color);
void CreateConsoleWindow();
void FixConsoleWindow();
void TextColor(int x);
void GotoXY(int x, int y);
void horizon(int column, int width, char middle, char out1, char out2);
void vertical(int row, int height, int x, int y);
void DrawBoard(int row, int column, int x, int y, int width, int height);
int Draw_txt(const char* file);
void Draw_txt_noeffect(const char* file);
void draw(int a, int k, int _y, int mau, int _x, int loop);
void Draw(int a, int mau);
int cl(int mau);
void title(int a);
void SoundWin();
void Sound2(int S2);

#endif