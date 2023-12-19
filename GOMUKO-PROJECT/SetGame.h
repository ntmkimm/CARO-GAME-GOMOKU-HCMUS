#pragma once
#ifndef _SETGAME_
#define _SETGAME_

#include "View.h"
#include "Handle.h"
#include "Menu.h"

void StartGame(_POINT A[BOARD_SIZE][BOARD_SIZE]);
void SAVE_game(_POINT A[BOARD_SIZE][BOARD_SIZE], Menu menu[COL][MAX_ROW], PLAYER PLAYER1, PLAYER PLAYER2); void LOAD_game(_POINT A[BOARD_SIZE][BOARD_SIZE], PLAYER& PLAYER1, PLAYER& PLAYER2, std::string file);
void LOAD_game(_POINT A[BOARD_SIZE][BOARD_SIZE], PLAYER& PLAYER1, PLAYER& PLAYER2, std::string file);

std::string LOADMENU_run(int option);
int ESC_menu(_POINT A[BOARD_SIZE][BOARD_SIZE], Menu menu[COL][MAX_ROW], PLAYER PLAYER1, PLAYER PLAYER2);
int ESC_menuLoad(Menu menu[COL][MAX_ROW]);
//INIT GAME
void SETNAME_player(PLAYER& PLAYER1, PLAYER& PLAYER2); //CREATE NAME'S PLAYER FOR GAME
int NewGame(_POINT A[BOARD_SIZE][BOARD_SIZE], Menu menu[COL][MAX_ROW], PLAYER& PLAYER1, PLAYER& PLAYER2); int MAIN_menu(Menu menu[COL][MAX_ROW]);
int NewGameLoad(_POINT A[BOARD_SIZE][BOARD_SIZE], Menu menu[COL][MAX_ROW], PLAYER& PLAYER1, PLAYER& PLAYER2);
int MAINMENU_run(_POINT A[BOARD_SIZE][BOARD_SIZE], _POINT B[25][25], Menu menu[COL][MAX_ROW], PLAYER& PLAYER1, PLAYER& PLAYER2, int option);
int Settings(Menu menu[COL][MAX_ROW]);

#endif