#include "SetGame.h"
#include "AI.h"

void StartGame(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	system("cls");
	ResetData(A);
	GotoXY(x_center_console - 8, 35);
	std::cout << "CARO PROJECT BY GROUP 6";
	TextColor(240);
	DrawBoard(BOARD_SIZE, BOARD_SIZE, 3, 1, 3, 2);
	DrawX_Turn();
	GotoXY(_X, _Y);
}

void SAVE_datafile(_POINT A[BOARD_SIZE][BOARD_SIZE], PLAYER PLAYER1, PLAYER PLAYER2, std::string file)
{
	std::fstream SAVE_file;
	SAVE_file.open(file, std::ios::out);

	SAVE_file << PLAYER1.name << std::endl;
	SAVE_file << PLAYER2.name << std::endl;

	SAVE_file << PLAYER1.win << std::endl;
	SAVE_file << PLAYER2.win << std::endl;

	SAVE_file << _TURN << std::endl;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
			SAVE_file << A[j][i].c << " ";
		SAVE_file << std::endl;
	}
	SAVE_file.close();
}

void SAVE_game(_POINT A[BOARD_SIZE][BOARD_SIZE], Menu menu[COL][MAX_ROW], PLAYER PLAYER1, PLAYER PLAYER2)
{
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
		file.erase(std::remove_if(file.begin(), file.end(), [](char c)
			{ return (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == '\f'); }), file.end());
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

	SAVE_datafile(A, PLAYER1, PLAYER2, file);

	std::fstream SAVE_file;
	SAVE_file.open("ListGame.txt", std::ios::app);
	SAVE_file << file << std::endl;
	SAVE_file.close();

}
void LOAD_game(_POINT A[BOARD_SIZE][BOARD_SIZE], PLAYER& PLAYER1, PLAYER& PLAYER2, std::string file)
{
	system("cls");
	LOAD_data(A, PLAYER1, PLAYER2, file);
	DrawBoard(BOARD_SIZE, BOARD_SIZE, 3, 1, 3, 2);
	GotoXY(_X, _Y);
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
	DrawBoard(1, 1, x_center_console - 5, y_center_console - 1, 16, 6);
	for (int i = 0; i < 3; i++)
	{
		menu[0][i].y = 2 * i + menu[0][0].y;
		GotoXY(menu[0][i].x, menu[0][i].y);
		std::cout << menu[0][i].c << std::endl;
	}
	X1 = x_center_console - 1;
	Y1 = y_center_console;
	GotoXY(X1, Y1);
	while (running)
	{
		init_cursor();
		_COMMAND = toupper(_getch());
		if (_COMMAND == arrow_down)
			MoveDown1(menu, 3);
		else if ( _COMMAND == arrow_up)
			MoveUp1(menu, 3);
		else if (_COMMAND == enter_char)
		{
			delete_cursor();
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
	};
	X1 = x_center_console - 1;
	Y1 = y_center_console;
	TextColor(255);
	DrawBoard(1, 1, x_center_console - 5, y_center_console - 1, 16, 6);
	for (int i = 0; i < 3; i++)
	{
		TextColor(255);
		menu[0][i].y = 2 * i + menu[0][0].y;
		GotoXY(menu[0][i].x, menu[0][i].y);
		std::cout << menu[0][i].c << std::endl;
	}
	GotoXY(_X, _Y);
	return ret;
}
int ESC_menuLoad(Menu menu[COL][MAX_ROW])
{
	Draw(3, 0, 36);
	DrawBoard(1, 1, x_center_console - 5, y_center_console - 1, 18, 4);
	menu[0][0].c = "Continue";
	menu[0][1].c = "Exit & Save";
	bool running = true;
	int ret;
	for (int i = 0; i < 2; i++)
	{
		menu[0][i].y = 2 * i + menu[0][0].y;
		GotoXY(menu[0][i].x, menu[0][i].y);
		std::cout << menu[0][i].c << std::endl;
	}
	X1 = x_center_console - 1;
	Y1 = y_center_console;
	GotoXY(X1, Y1);
	while (running)
	{
		init_cursor();
		_COMMAND = toupper(_getch());
		if (_COMMAND == arrow_down)
			MoveDown1(menu, 2);
		else if (_COMMAND == arrow_up)
			MoveUp1(menu, 2);
		else if (_COMMAND == enter_char)
		{
			delete_cursor();
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
	};
	TextColor(255);
	DrawBoard(1, 1, x_center_console - 5, y_center_console - 1, 18, 4);
	for (int i = 0; i < 2; i++)
	{
		TextColor(255);
		menu[0][i].y = 2 * i + menu[0][0].y;
		GotoXY(menu[0][i].x, menu[0][i].y);
		std::cout << menu[0][i].c << std::endl;
	}
	GotoXY(_X, _Y);
	return ret;
}

int ESC_menuBot(Menu menu[COL][MAX_ROW])
{
	Draw(3, 0, 36);
	DrawBoard(1, 1, x_center_console - 5, y_center_console - 1, 18, 4);
	menu[0][0].c = "Continue";
	menu[0][1].c = "Exit";
	bool running = true;
	int ret;
	for (int i = 0; i < 2; i++)
	{
		menu[0][i].y = 2 * i + menu[0][0].y;
		GotoXY(menu[0][i].x, menu[0][i].y);
		std::cout << menu[0][i].c << std::endl;
	}
	X1 = x_center_console - 1;
	Y1 = y_center_console;
	GotoXY(X1, Y1);
	while (running)
	{
		init_cursor();
		_COMMAND = toupper(_getch());
		if (_COMMAND == arrow_down)
			MoveDown1(menu, 2);
		else if (_COMMAND == arrow_up)
			MoveUp1(menu, 2);
		else if (_COMMAND == enter_char)
		{
			delete_cursor();
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
	};
	TextColor(255);
	DrawBoard(1, 1, x_center_console - 5, y_center_console - 1, 18, 4);
	for (int i = 0; i < 2; i++)
	{
		TextColor(255);
		menu[0][i].y = 2 * i + menu[0][0].y;
		GotoXY(menu[0][i].x, menu[0][i].y);
		std::cout << menu[0][i].c << std::endl;
	}
	GotoXY(_X, _Y);
	return ret;
}

void SETNAME_player(PLAYER& PLAYER1, PLAYER& PLAYER2)
{
	do {
		system("cls");
		Draw_txt("des1.txt", Color_O);
		Draw_txt("des2.txt", Color_X);
		DrawBoard(1, 1, x_center_console - 30, y_center_console - 3, 70, 8);
		GotoXY(x_center_console - 20, y_center_console);
		TextColor(Color_X);
		std::cout << "Enter First PLayer's name: ";
		GotoXY(x_center_console - 20, y_center_console + 2);
		TextColor(Color_O);
		std::cout << "Enter Second PLayer's name: ";
		GotoXY(x_center_console + 10, y_center_console);
		TextColor(Color_X);
		std::getline(std::cin >> std::ws, PLAYER1.name);
		TextColor(240);
	} while (PLAYER1.name.length() < 2 || PLAYER1.name.length() > 10);

	do {
		system("cls");
		Draw_txt("des1.txt", Color_O);
		Draw_txt("des2.txt", Color_X);
		DrawBoard(1, 1, x_center_console - 30, y_center_console - 3, 70, 8);
		GotoXY(x_center_console - 20, y_center_console);
		TextColor(Color_X);
		std::cout << "Enter First PLayer's name: ";
		GotoXY(x_center_console - 20, y_center_console + 2);
		TextColor(Color_O);
		std::cout << "Enter Second PLayer's name: ";
		GotoXY(x_center_console + 10, y_center_console);
		TextColor(Color_X);
		std::cout << PLAYER1.name;
		GotoXY(x_center_console + 10, y_center_console + 2);
		TextColor(Color_O);
		std::getline(std::cin >> std::ws, PLAYER2.name);
		TextColor(240);
	} while (PLAYER1.name.length() < 2 || PLAYER1.name.length() > 10);

}

void ShowPlayerInfo(PLAYER& PLAYER1, PLAYER& PLAYER2)
{
	TextColor(240);
	DrawBoard(1, 1, x_center_console + 24, y_center_console - 7, 47, 24);
	using std::setw;
	GotoXY(x_center_console + 43, 14);
	TextColor(244); //red
	std::cout << "PLAYER INFO";
	TextColor(240);
	GotoXY(x_center_console + 30, 19);
	std::cout << setw(7) << "NAME" << setw(16) << "COUNT MOVE" << setw(13) << "WIN";
	GotoXY(x_center_console + 30, 23);
	TextColor(Color_X);
	std::cout << setw(7) << PLAYER1.name << setw(16) << CountMoveP1 << setw(13) << PLAYER1.win;
	GotoXY(x_center_console + 30, 27);
	TextColor(Color_O);
	std::cout << setw(7) << PLAYER2.name << setw(16) << CountMoveP2 << setw(13) << PLAYER2.win;
	TextColor(240);
	GotoXY(_X, _Y);
}

int Settings(Menu menu[COL][MAX_ROW]) {
	system("cls");
	Draw_txt("SETTINGS.txt", Color_X);
	DrawBoard(1, 1, x_center_console - 40, y_center_console - 3, 90, 8);
	GotoXY(x_center_console - 25, y_center_console + 1);
	TextColor(Color_O);
	std::cout << "SETTINGS";
	TextColor(240);
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
		init_cursor();
		_COMMAND = toupper(_getch());
		if (_COMMAND == esc_char)
		{
			delete_cursor();
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
					menu[1][1].c = " <  Disable  >";
					PlaySound(0, 0, 0);
					S2 = 0;
					GotoXY(menu[1][1].x, menu[1][1].y);
					std::cout << menu[1][1].c;
					GotoXY(menu[0][1].x - 1, menu[0][1].y);
				}
				else {
					menu[1][1].c = " <  Enable   >";
					S2 = 1;
					Sound2(S2);
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
		LoadData(A);
		init_cursor_board(A);
		DrawX();
		DrawO();
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
					TextColor(Color_X);
					std::cout << "x"; break;

				case 1:
					TextColor(Color_O);
					std::cout << "o"; break;
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
						Sound2(S2);
						Draw_txt("des1.txt", Color_O);
						Draw_txt("des2.txt", Color_X);
						TextColor(240);
						GotoXY(menu[0][0].x - 11, menu[0][0].y - 3);
						std::cout << "DO YOU WANT TO PLAY AGAIN?";
						if (YESNO_CHOOSE(menu) == 1)
						{
							Sound2(S2);
							StartGame(A);
							DrawX_Turn();
							break;
						}
						else
						{
							system("cls");
							Draw_txt("des1.txt", Color_O);
							Draw_txt("des2.txt", Color_X);
							TextColor(240);
							GotoXY(menu[0][0].x - 11, menu[0][0].y - 3);
							std::cout << "DO YOU WANT TO SAVE GAME?";
							if (YESNO_CHOOSE(menu) == 1)
							{
								SAVE_game(A, menu, PLAYER1, PLAYER2);
								running = false;
							}
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
		DrawX();
		DrawO();
		ShowGuide();
		LoadData(A);
		ShowPlayerInfo(PLAYER1, PLAYER2);
		if (TestBoard(A) != 2 && count == 0)
		{
			GotoXY(x_center_console + 30, y_center_console - 12);
			TextColor(270);
			std::cout << "THIS GAME IS OVER IN THE LAST TIME!";
			int option = ESC_menuLoad(menu);
			if (option == 1)
			{
				StartGame(A);
				DrawX();
				DrawO();
				ShowGuide();
				ShowPlayerInfo(PLAYER1, PLAYER2);
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
		init_cursor_board(A);
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
					CountMoveP1++;
					std::cout << "x"; break;

				case 1:
					TextColor(Color_O);
					CountMoveP1++;
					std::cout << "o"; break;
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
						Sound2(S2);
						Draw_txt("des1.txt", Color_O);
						Draw_txt("des2.txt", Color_X);
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

int Playwithcomputer(_POINT A[BOARD_SIZE][BOARD_SIZE], _POINT B[25][25], Menu menu[COL][MAX_ROW], PLAYER& PLAYER1, PLAYER& PLAYER2)
{

	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 25; j++)
			B[i][j].c = -2;
	int count = 0;
	PLAYER1.name = "YOU";
	PLAYER2.name = "BOT";
	bool running = true;
	GotoXY(_X, _Y);
	while (running == 1)
	{
		LoadData(A);
		DrawX();
		DrawO();
		ShowGuide();
		ShowPlayerInfo(PLAYER1, PLAYER2);
		if (count % 2 == 0)
		{
			DrawX_Turn();
			while (true)
			{
				LoadData(A);
				init_cursor_board(A);
				_COMMAND = toupper(_getch());
				if (_COMMAND == esc_char)
				{
					if (ESC_menuBot(menu) == 0)
					{
						running = false;
						break;
					}
				}
				else
				{
					if (_COMMAND == arrow_left) MoveLeft(A);
					else if (_COMMAND == arrow_up) MoveUp(A);
					else if (_COMMAND == arrow_down) MoveDown(A);
					else if (_COMMAND == arrow_right) MoveRight(A);
					else if (_COMMAND == enter_char)
					{
						if (CheckBoard(A, _X, _Y) == -1)
						{
							CountMoveP1++;
							TextColor(Color_X);
							GotoXY(_X, _Y);
							std::cout << "x";
							break;
						}
						LoadData(A);
					}
				}
			}
		}
		else
		{
			LoadData(A);
			DrawO_Turn();
			for (int i = 5; i < SIZE + 5; i++)
				for (int j = 5; j < SIZE + 5; j++)
					B[i][j].c = A[i - 5][j - 5].c;

			Move bestMove = findfirstBestmove(B);
			A[bestMove.x - 5][bestMove.y - 5].c = 1;
			GotoXY(A[bestMove.x - 5][bestMove.y - 5].x, A[bestMove.x - 5][bestMove.y - 5].y);
			Sleep(500);
			CountMoveP2++;
			TextColor(Color_O);
			std::cout << "o";
		}
		LoadData(A);
		count++;
		switch (ProcessFinish(A, TestBoard(A), PLAYER1, PLAYER2))
		{
		case -1: case 1: case 0:
			system("cls");
			Sound2(S2);
			Draw_txt("des1.txt", Color_O);
			Draw_txt("des2.txt", Color_X);
			TextColor(240);
			GotoXY(menu[0][0].x - 11, menu[0][0].y - 3);
			std::cout << "DO YOU WANT TO PLAY AGAIN?";
			if (YESNO_CHOOSE(menu) == 1)
			{
				count = 0;
				StartGame(A);
				running = true;
				break;
			}
			else
			{
				running = false;
			}
		}
	}
	TextColor(240);
	return 1;
}

int MAINMENU_run(_POINT A[BOARD_SIZE][BOARD_SIZE], _POINT B[25][25], Menu menu[COL][MAX_ROW], PLAYER& PLAYER1, PLAYER& PLAYER2, int option)
{
	int ret = 1;
	std::string file_chosen;
	hidecursor();
	switch (option)
	{
	case 1:
		SETNAME_player(PLAYER1, PLAYER2);
		StartGame(A);
		NewGame(A, menu, PLAYER1, PLAYER2);
		break;
	case 2:
		system("cls");
		StartGame(A);
		Playwithcomputer(A, B, menu, PLAYER1, PLAYER2);
		break;
	case 3:
		system("cls");
		file_chosen = LOADMENU_run(LOAD_menu(menu));
		LOAD_game(A, PLAYER1, PLAYER2, file_chosen);
		NewGameLoad(A, menu, PLAYER1, PLAYER2);
		SAVE_data(A, PLAYER1, PLAYER2, file_chosen);
		break;
	case 4:
		system("cls");
		Draw_txt_noeffect("AboutUs.txt");
		break;
	case 5:
		Settings(menu);
		break;
	case 6:
		loading();
		system("cls");
		ret = 0;
		break;
	}
	return ret;
}
