#include "SetGame.h"

void StartGame(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	showcursor();
	system("cls");
	ResetData(A);
	TextColor(240);
	DrawBoard(BOARD_SIZE, BOARD_SIZE, 3, 1, 3, 2);
	DrawX_Turn();
	GotoXY(_X, _Y);
}
void SAVE_game(_POINT A[BOARD_SIZE][BOARD_SIZE], Menu menu[COL][MAX_ROW], PLAYER PLAYER1, PLAYER PLAYER2)
{
	showcursor();
	bool run = true;
	std::string file;
	int count = 1;
	//save game meaning save file with name & their data
	//save data just save the data, not with the name
	system("cls");
	do
	{
		system("cls");
		DrawBoard(1, 1, x_center_console - 35, y_center_console - 2, 78, 4);
		GotoXY(x_center_console - 18, y_center_console);
		std::cout << "You want to save file with name: ";
		std::getline(std::cin >> std::ws, file);
		//erase the whitespace between filename's characters(if existed)
		file.erase(std::remove_if(file.begin(), file.end(), [](char c) { return (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == '\f'); }), file.end());
	} while (file.length() < 1 || file.length() > 10);
	while (EXIST_file(file + ".txt"))
	{
		std::string str_count = std::to_string(count);
		if (EXIST_file(file + "(" + str_count + ")" + ".txt"))
			count++;
		else 
			file = file + "(" + str_count + ")";
	}

	file = file + ".txt";
	SAVE_data(A, PLAYER1, PLAYER2, file);

	std::fstream SAVE_file; // writing
	SAVE_file.open("ListGame.txt", std::ios::app);//app instead of out because std::ios::out will delete data we had saved
	SAVE_file << file << std::endl;
	SAVE_file.close();

}
void LOAD_game(_POINT A[BOARD_SIZE][BOARD_SIZE], PLAYER& PLAYER1, PLAYER& PLAYER2, std::string file)
{
	showcursor();
	system("cls");
	LOAD_data(A, PLAYER1, PLAYER2, file);
	DrawBoard(BOARD_SIZE, BOARD_SIZE, 3, 1, 3, 2);
	GotoXY(_X, _Y); //return default coordinate
}

std::string LOADMENU_run(int option)
{
	std::string NAME_file;
	std::vector<std::string> File;
	File = LOAD_file();
	NAME_file = File[option];
	return NAME_file;
}
int ESC_menu(_POINT A[BOARD_SIZE][BOARD_SIZE], Menu menu[COL][MAX_ROW], PLAYER PLAYER1, PLAYER PLAYER2)
{
	Draw(3, 0, 36);
	menu[0][0].c = "Continue";
	menu[0][1].c = "Save Game";
	menu[0][2].c = "Exit";
	bool running = true;
	int ret;
	DrawBoard(1, 1, x_center_console - 5, y_center_console - 1, 16, 7);
	for (int i = 0; i < 3; i++)
	{
		menu[0][i].y = 2 * i + menu[0][0].y; //set coord y for ech option in menu
		GotoXY(menu[0][i].x, menu[0][i].y);
		std::cout << menu[0][i].c << std::endl;
	}
	do
	{
		GotoXY(X1, Y1);
		_COMMAND = toupper(_getch());
		if (_COMMAND == 's' or _COMMAND == arrow_down)
			MoveDown1(menu, 3);
		else if (_COMMAND == 'w' or _COMMAND == arrow_up)
			MoveUp1(menu, 3);
		else if (_COMMAND == enter_char)
		{
			if (X1 == menu[0][0].x - 1 && Y1 == menu[0][0].y)
			{
				running = false;
				ret = 1;
			}
			else if (X1 == menu[0][1].x - 1 && Y1 == menu[0][1].y)
			{
				SAVE_game(A, menu, PLAYER1, PLAYER2);
				ret = 0;
				break;
			}
			else if (X1 == menu[0][2].x - 1 && Y1 == menu[0][2].y)
			{
				system("cls");
				ret = 0;
				break;
			}
		}
	} while (running);
	TextColor(255);
	DrawBoard(1, 1, x_center_console - 5, y_center_console - 1, 16, 7);
	for (int i = 0; i < 3; i++)
	{
		TextColor(255);
		menu[0][i].y = 2 * i + menu[0][0].y; //set coord y for ech option in menu
		GotoXY(menu[0][i].x, menu[0][i].y);
		std::cout << menu[0][i].c << std::endl;
	}
	GotoXY(_X, _Y);
	return ret;
}
int ESC_menuLoad(Menu menu[COL][MAX_ROW])
{
	Draw(3, 0, 36);
	DrawBoard(1, 1, x_center_console - 5, y_center_console - 1, 18, 5);
	menu[0][0].c = "Continue";
	menu[0][1].c = "Exit & Save";
	bool running = true;
	int ret;
	for (int i = 0; i < 2; i++)
	{
		menu[0][i].y = 2 * i + menu[0][0].y; //set coord y for ech option in menu
		GotoXY(menu[0][i].x, menu[0][i].y);
		std::cout << menu[0][i].c << std::endl;
	}
	do
	{
		GotoXY(X1, Y1);
		_COMMAND = toupper(_getch());
		if (_COMMAND == 's' or _COMMAND == arrow_down)
			MoveDown1(menu, 2);
		else if (_COMMAND == 'w' or _COMMAND == arrow_up)
			MoveUp1(menu, 2);
		else if (_COMMAND == enter_char)
		{
			if (X1 == menu[0][0].x - 1 && Y1 == menu[0][0].y)
			{
				running = false;
				ret = 1;
			}
			else if (X1 == menu[0][1].x - 1 && Y1 == menu[0][1].y)
			{
				system("cls");
				ret = 0;
				break;
			}
		}
	} while (running);
	TextColor(255);
	DrawBoard(1, 1, x_center_console - 5, y_center_console - 1, 18, 5);
	for (int i = 0; i < 2; i++)
	{
		TextColor(255);
		menu[0][i].y = 2 * i + menu[0][0].y; //set coord y for ech option in menu
		GotoXY(menu[0][i].x, menu[0][i].y);
		std::cout << menu[0][i].c << std::endl;
	}
	GotoXY(_X, _Y);
	return ret;
}

void SETNAME_player(PLAYER& PLAYER1, PLAYER& PLAYER2) //CREATE NAME'S PLAYER FOR GAME
{
	system("cls");
	DrawBoard(1, 1, x_center_console - 30, y_center_console - 3, 80, 8);
	do {
		GotoXY(x_center_console - 10, y_center_console);
		TextColor(Color_X);
		std::cout << "Enter First PLayer's name: ";
		std::getline(std::cin >> std::ws, PLAYER1.name);
	} while (PLAYER1.name.length() < 2 || PLAYER1.name.length() > 10);

	do {
		GotoXY(x_center_console - 10, y_center_console + 2);
		TextColor(Color_O);
		std::cout << "Enter Second PLayer's name: ";
		std::getline(std::cin >> std::ws, PLAYER2.name);
	} while (PLAYER1.name.length() < 2 || PLAYER1.name.length() > 10);

}

void ShowPlayerInfo(PLAYER& PLAYER1, PLAYER& PLAYER2)
{
	hidecursor();
	TextColor(240);
	DrawBoard(1, 1, x_center_console + 24, y_center_console - 7, 47, 24);
	using std::setw;
	GotoXY(113, 14);
	std::cout << "PLAYER INFO";
	GotoXY(100, 19);
	std::cout << setw(7) << "NAME" << setw(16) << "COUNT MOVE" << setw(13) << "WIN";
	GotoXY(100, 23);
	TextColor(Color_X);
	std::cout << setw(7) << PLAYER1.name << setw(16) << CountMoveP1 << setw(13) << PLAYER1.win;
	GotoXY(100, 27);
	TextColor(Color_O);
	std::cout << setw(7) << PLAYER2.name << setw(16) << CountMoveP2 << setw(13) << PLAYER2.win;
	TextColor(240);
	GotoXY(_X, _Y);
	showcursor();
}

int Settings(Menu menu[COL][MAX_ROW]) {
	system("cls");
	DrawBoard(1, 1, x_center_console - 40, y_center_console - 3, 90, 8);
	GotoXY(x_center_console - 25, y_center_console + 1);
	std::cout << "SETTINGS";
	menu[0][0].c = "Color   X   _   O  :";
	menu[0][1].c = "Background Music   :";

	menu[1][0].c = " Blue  _  Red";
	menu[1][1].c = " <  Enable  >";
	bool running = true;
	X1 = menu[0][0].x - 1;
	Y1 = menu[0][0].y;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			menu[j][i].x = 25 * j + menu[0][0].x;
			menu[j][i].y = 2 * i + menu[0][0].y;
			GotoXY(menu[j][i].x, menu[j][i].y);
			std::cout << menu[j][i].c << std::endl;
		}
	}
	GotoXY(menu[0][0].x - 1, menu[0][0].y);
	do
	{
		_COMMAND = toupper(_getch());
		if (_COMMAND == esc_char)
		{
			running = false;
		}
		else if (_COMMAND == 's' or _COMMAND == arrow_down)
			MoveDown1(menu, 2);
		else if (_COMMAND == 'w' or _COMMAND == arrow_up)
			MoveUp1(menu, 2);
		else if (_COMMAND == enter_char)
		{
			if (X1 == menu[0][0].x - 1 && Y1 == menu[0][0].y)
			{
				S1++;
				if (S1 % 3 == 2)
				{
					Color_X = 245;
					Color_O = 246;
					menu[1][0].c = "Purple  _  Yellow";
					GotoXY(menu[1][0].x, menu[1][0].y);
					std::cout << menu[1][0].c;
					GotoXY(menu[0][0].x - 1, menu[0][0].y);
				}
				else if (S1 % 3 == 0)
				{
					Color_X = 252;
					Color_O = 242;
					menu[1][0].c = "Orange  _  Green ";
					GotoXY(menu[1][0].x, menu[1][0].y);
					std::cout << menu[1][0].c;
					GotoXY(menu[0][0].x - 1, menu[0][0].y);
				}
				else
				{
					Color_X = 241;
					Color_O = 244;
					menu[1][0].c = "Blue  _   Red    ";
					GotoXY(menu[1][0].x, menu[1][0].y);
					std::cout << menu[1][0].c;
					GotoXY(menu[0][0].x - 1, menu[0][0].y);
				}
			}
			else if (X1 == menu[0][1].x - 1 && Y1 == menu[0][1].y)
			{
				S2++;
				if (S2 % 2 == 0) {
					menu[1][1].c = " <  Disable >";
					PlaySound(0, 0, 0);
					GotoXY(menu[1][1].x, menu[1][1].y);
					std::cout << menu[1][1].c;
					GotoXY(menu[0][1].x - 1, menu[0][1].y);
				}
				else {
					menu[1][1].c = " <  Enable  >";
					Sound2(1);
					GotoXY(menu[1][1].x, menu[1][1].y);
					std::cout << menu[1][1].c;
					GotoXY(menu[0][1].x - 1, menu[0][1].y);
				}
			}
		}
	} while (running);
	GotoXY(menu[0][0].x - 1, menu[0][0].y);
	return 0;
}

int NewGame(_POINT A[BOARD_SIZE][BOARD_SIZE], Menu menu[COL][MAX_ROW], PLAYER& PLAYER1, PLAYER& PLAYER2)
{
	bool validEnter = true;
	bool running = true;
	GotoXY(_X, _Y);
	while (running)
	{
		ShowGuide();
		ShowPlayerInfo(PLAYER1, PLAYER2);
		_COMMAND = toupper(_getch());
		if (_COMMAND == esc_char)
		{
			running = ESC_menu(A, menu, PLAYER1, PLAYER2);
		}
		else
		{
			if (_COMMAND == arrow_left) MoveLeft(A);
			else if (_COMMAND == arrow_up) MoveUp(A);
			else if (_COMMAND == arrow_down) MoveDown(A);
			else if (_COMMAND == arrow_right) MoveRight(A);
			else if (_COMMAND == enter_char)
			{
				switch (CheckBoard(A, _X, _Y))
				{
				case -1:
					CountMoveP1++;
					TextColor(Color_X);// 4 to 241
					std::cout << "X"; break;

				case 1:
					CountMoveP2++;
					TextColor(Color_O);// 9 to 244
					std::cout << "O"; break;
				case 0: validEnter = false;
				}
				if (validEnter == true)
				{
					if (_TURN == 1)
						DrawO_Turn();
					else
						DrawX_Turn();
					switch (ProcessFinish(A, TestBoard(A), PLAYER1, PLAYER2))
					{
					case -1: case 1: case 0:
						system("cls");
						TextColor(240);
						GotoXY(menu[0][0].x - 11, menu[0][0].y - 3);
						std::cout << "DO YOU WANT TO PLAY AGAIN?";
						if (YESNO_CHOOSE(menu) == 1)
						{
							Sound2(1);
							StartGame(A);
							DrawX_Turn();
							break;
						}
						else
						{
							system("cls");
							TextColor(241);
							GotoXY(menu[0][0].x - 11, menu[0][0].y - 3);
							std::cout << "DO YOU WANT TO SAVE GAME?";
							if (YESNO_CHOOSE(menu) == 1)
								SAVE_game(A, menu, PLAYER1, PLAYER2);
							else
								running = false;
						}
					}
				}
				validEnter = true;
			}
		}
	}
	return 1;
}

int NewGameLoad(_POINT A[BOARD_SIZE][BOARD_SIZE], Menu menu[COL][MAX_ROW], PLAYER& PLAYER1, PLAYER& PLAYER2)
{
	bool validEnter = true;
	bool running = true;
	int count = 0;
	while (running)
	{
		ShowGuide();
		ShowPlayerInfo(PLAYER1, PLAYER2);
		if (TestBoard(A) != 2 && count == 0)
		{
			GotoXY(x_center_console - 5, y_center_console - 12);
			TextColor(207); // white text with background red
			std::cout << "THIS GAME IS OVER, PRESS 'CONTINUE' TO PLAY AGAIN, OR 'EXIT AND SAVE'";
			int option = ESC_menuLoad(menu);
			if (option == 1)
			{
				system("cls");
				StartGame(A);
			}
			else
				break;
			++count;
		}
		else
		{
			if (_TURN == 1)
				DrawX_Turn();
			else
				DrawO_Turn();
		}
		GotoXY(_X, _Y);
		_COMMAND = toupper(_getch());
		if (_COMMAND == esc_char)
		{
			running = ESC_menuLoad(menu);
		}
		else
		{
			if (_COMMAND == arrow_left) MoveLeft(A);
			else if (_COMMAND == arrow_up) MoveUp(A);
			else if (_COMMAND == arrow_down) MoveDown(A);
			else if (_COMMAND == arrow_right) MoveRight(A);
			else if (_COMMAND == enter_char)
			{
				switch (CheckBoard(A, _X, _Y))
				{
				case -1:
					TextColor(Color_X);
					std::cout << "X"; break;
				case 1:
					TextColor(Color_O);
					std::cout << "O"; break;
				case 0: validEnter = false;
				}
				if (validEnter == true)
				{
					if (_TURN == 1)
						DrawX_Turn();
					else
						DrawO_Turn();
					switch (ProcessFinish(A, TestBoard(A), PLAYER1, PLAYER2))
					{
					case -1: case 1: case 0:
						system("cls");
						TextColor(240);
						GotoXY(menu[0][0].x - 11, menu[0][0].y - 3);
						std::cout << "DO YOU WANT TO PLAY AGAIN?";
						if (YESNO_CHOOSE(menu) == 1)
						{
							StartGame(A);
							break;
						}
						else
						{
							running = false;
						}
					}
				}
				validEnter = true;
			}
		}
	}
	return 1;
}

int MAINMENU_run(_POINT A[BOARD_SIZE][BOARD_SIZE], Menu menu[COL][MAX_ROW], PLAYER& PLAYER1, PLAYER& PLAYER2, int option)
{
	int ret = 1;
	std::string file_chosen;
	switch (option)
	{
	case 1:
		SETNAME_player(PLAYER1, PLAYER2);
		StartGame(A);
		NewGame(A, menu, PLAYER1, PLAYER2);
		break;
	case 2:
		system("cls");
		file_chosen = LOADMENU_run(LOAD_menu(menu));
		LOAD_game(A, PLAYER1, PLAYER2, file_chosen);
		NewGameLoad(A, menu, PLAYER1, PLAYER2);
		SAVE_data(A, PLAYER1, PLAYER2, file_chosen);
		break;
	case 3:
		system("cls");
		while (true)
		{
			Draw_txt_noeffect("AboutUs.txt");
			if (_kbhit())
			{
				int h = _getch();
				if (h == 27)
				{
					MAINMENU_run(A, menu, PLAYER1, PLAYER2, MAIN_menu(menu));
					break;
				}
			}
		}
		break;
	case 4:
		system("cls");
		ret = 0;
		break;
	case 5:
		Settings(menu);
		GotoXY(0, 0);
		break;
	}
	return ret;
}



