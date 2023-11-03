#pragma once
#ifndef _SETGAME_
#define _SETGAME_

#include "View.h"
#include "Handle.h"
#include "Menu.h"

void StartGame(_POINT A[BOARD_SIZE][BOARD_SIZE]);
void SAVE_game(_POINT A[BOARD_SIZE][BOARD_SIZE], PLAYER PLAYER1, PLAYER PLAYER2);
void LOAD_game(_POINT A[BOARD_SIZE][BOARD_SIZE], PLAYER& PLAYER1, PLAYER& PLAYER2, std::string file);

std::string LOADMENU_run(int option);
void ESCMENU_run(_POINT A[BOARD_SIZE][BOARD_SIZE], PLAYER PLAYER1, PLAYER PLAYER2, int option);

//INIT GAME
void SETNAME_player(PLAYER& PLAYER1, PLAYER& PLAYER2); //CREATE NAME'S PLAYER FOR GAME
int NewGame(_POINT A[BOARD_SIZE][BOARD_SIZE], Menu menu[COL][MAX_ROW], PLAYER& PLAYER1, PLAYER& PLAYER2); int MAIN_menu(Menu menu[COL][MAX_ROW]);
int MAINMENU_run(_POINT A[BOARD_SIZE][BOARD_SIZE], Menu menu[COL][MAX_ROW], PLAYER& PLAYER1, PLAYER& PLAYER2, int option);

#endif