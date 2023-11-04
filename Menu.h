#pragma once
#ifndef _MENU_
#define _MENU_

#include <vector>
#include <string>
#include <fstream>
#include "View.h"
#include "Handle.h"

void ResetData(_POINT A[BOARD_SIZE][BOARD_SIZE]);
void LOAD_data(_POINT A[BOARD_SIZE][BOARD_SIZE], PLAYER& PLAYER1, PLAYER& PLAYER2, std::string file);
void SAVE_data(_POINT A[BOARD_SIZE][BOARD_SIZE], PLAYER PLAYER1, PLAYER PLAYER2, std::string file);

std::vector<std::string> LOAD_file();
bool EXIST_file(std::string file);

void MoveDown1(Menu menu[COL][MAX_ROW], int option);
void MoveUp1(Menu menu[COL][MAX_ROW], int option);

int SaveOption_CHOOSE(Menu menu[COL][MAX_ROW]);
int YESNO_CHOOSE(Menu menu[COL][MAX_ROW]);
int LOAD_menu(Menu menu[COL][MAX_ROW]);
int ESC_menu(Menu menu[COL][MAX_ROW]);
int MAIN_menu(Menu menu[COL][MAX_ROW]);



#endif