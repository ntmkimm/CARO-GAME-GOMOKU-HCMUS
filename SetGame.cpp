#include "SetGame.h"

void StartGame(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	system("cls");
	ResetData(A);
	TextColor(240);
	DrawBoard(BOARD_SIZE, BOARD_SIZE, 3, 1);
	GotoXY(_X, _Y);
}
void SAVE_game(_POINT A[BOARD_SIZE][BOARD_SIZE], PLAYER PLAYER1, PLAYER PLAYER2)
{
	bool run = true;
	std::string file;
	int count = 1;
	//save game meaning save file with name & their data
	//save data just save the data, not with the name

	system("cls");
	GotoXY(x_center_console + 10, y_center_console);
	std::cout << "You want to save file with name: ";
	std::getline(std::cin, file);
	while (EXIST_file(file + ".txt"))
	{
		std::string str_count = std::to_string(count);
		file = file + "(" + str_count + ")";
		count++;
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
	system("cls");
	LOAD_data(A, PLAYER1, PLAYER2, file);
	DrawBoard(BOARD_SIZE, BOARD_SIZE, 3, 1);
	GotoXY(_X, _Y); //return default coordinate
}

std::string LOADMENU_run(int option)
{
	std::string NAME_file;
	std::vector<std::string> File;
	File = LOAD_file();
	int OPTION = option;
	NAME_file = File[OPTION];

	return NAME_file;
}
void ESCMENU_run(_POINT A[BOARD_SIZE][BOARD_SIZE], PLAYER PLAYER1, PLAYER PLAYER2, int option)
{
	switch (option)
	{
	case 1:
		system("cls");
		DrawBoard(BOARD_SIZE, BOARD_SIZE, 3, 1);
		break;
	case 2:
		SAVE_game(A, PLAYER1, PLAYER2);
		break;
	case 3:
		break;
	}
}

void SETNAME_player(PLAYER& PLAYER1, PLAYER& PLAYER2) //CREATE NAME'S PLAYER FOR GAME
{
	system("cls");
	do {
		GotoXY(x_center_console - 5, y_center_console);
		std::cout << "Enter First PLayer's name: ";
		std::getline(std::cin >> std::ws, PLAYER1.name);
	} while (PLAYER1.name.length() < 2 || PLAYER1.name.length() > 15);

	do {
		GotoXY(x_center_console - 5, y_center_console + 2);
		std::cout << "Enter Second PLayer's name: ";
		std::getline(std::cin >> std::ws, PLAYER2.name);
	} while (PLAYER1.name.length() < 2 || PLAYER1.name.length() > 15);

}
int NewGame(_POINT A[BOARD_SIZE][BOARD_SIZE], Menu menu[COL][MAX_ROW], PLAYER& PLAYER1, PLAYER& PLAYER2)
{
	bool validEnter = true;
	bool running = true;
	GotoXY(_X, _Y);
	while (running)
	{
		//GotoXY(_X, _Y);//add: set pointer to A[0][0]
		_COMMAND = toupper(_getch());
		if (_COMMAND == esc_char)
		{
			ESCMENU_run(A, PLAYER1, PLAYER2, ESC_menu(menu));
			system("cls");
			return 0;
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
					TextColor(241);// 4 to 241
					std::cout << "X"; break;

				case 1:
					TextColor(244);// 9 to 244
					std::cout << "O"; break;
				case 0: validEnter = false;
				}
				if (validEnter == true)
				{
					GotoXY(menu[0][0].x - 5, menu[0][0].y - 5);
					if (_TURN == 1)
					{
						TextColor(244);
						std::cout << "O's TURN";
					}
					else
					{
						TextColor(241);
						std::cout << "X's TURN";
					}
					switch (ProcessFinish(A, TestBoard(A)))
					{
					case -1: case 1: case 0:
						TextColor(240);
						GotoXY(menu[0][0].x - 5, menu[0][0].y - 5);
						std::cout << "DO YOU WANT TO PLAY AGAIN?";
						if (YESNO_CHOOSE(menu) == 1)
							StartGame(A);
						else
							running = false;
					}
				}
				validEnter = true;
			}
		}
	}
}
int MAINMENU_run(_POINT A[BOARD_SIZE][BOARD_SIZE], Menu menu[COL][MAX_ROW], PLAYER& PLAYER1, PLAYER& PLAYER2, int option)
{
	switch (option)
	{
	case 1:
		SETNAME_player(PLAYER1, PLAYER2);
		StartGame(A);
		NewGame(A, menu, PLAYER1, PLAYER2);
		break;
	case 2:
		system("cls");
		if (LOAD_menu(menu) == -1) break;
		else
		{
			system("cls");
			LOAD_game(A, PLAYER1, PLAYER2, LOADMENU_run(LOAD_menu(menu)));
			NewGame(A, menu, PLAYER1, PLAYER2);
			break;
		}
	case 3:
		Draw_txt_("AboutUs.txt");
		break;
	case 4: case -1:
		system("cls");
		return 0;
		break;
	}
}


