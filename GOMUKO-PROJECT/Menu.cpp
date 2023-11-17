#include "Menu.h"

//handle file=====================================================

void ResetData(_POINT A[BOARD_SIZE][BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			A[i][j].x = 4 * i + LEFT + 2;
			A[i][j].y = 2 * j + TOP + 1;
			A[i][j].c = 0;
		}

	_TURN = true; _COMMAND = -1;
	_X = A[0][0].x; _Y = A[0][0].y;
}
void LOAD_data(_POINT A[BOARD_SIZE][BOARD_SIZE], PLAYER& PLAYER1, PLAYER& PLAYER2, std::string file)
{
	std::ifstream LOAD_file;
	LOAD_file.open(file, std::ios::in);

	std::getline(LOAD_file, PLAYER1.name);
	std::getline(LOAD_file, PLAYER2.name);

	LOAD_file >> PLAYER1.win;
	LOAD_file >> PLAYER2.win;

	LOAD_file >> PLAYER1.win;
	LOAD_file >> PLAYER2.win;

	LOAD_file >> _TURN; //pass _turn of loadfile to _turn variable
	std::string line;
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			A[i][j].x = 4 * j + LEFT + 2; //COORD X
			A[i][j].y = 2 * i + TOP + 1; //COORD Y
			LOAD_file >> A[i][j].c;
		}
	LOAD_file.close();
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			GotoXY(A[i][j].x, A[i][j].y);
			switch (A[i][j].c)
			{
			case 0: break;
			case -1:
				TextColor(241);
				std::cout << "X";
				TextColor(240);
				break;
			case 1:
				TextColor(244);
				std::cout << "O";
				TextColor(240);
				break;
			}
		}
	_COMMAND = -1;
	//Thiet lap lai toa do ban dau
	_X = A[0][0].x;
	_Y = A[0][0].y;
}
void SAVE_data(_POINT A[BOARD_SIZE][BOARD_SIZE], PLAYER PLAYER1, PLAYER PLAYER2, std::string file)
{
	std::fstream SAVE_file;
	SAVE_file.open(file, std::ios::out); // writing 

	SAVE_file << PLAYER1.name << std::endl;
	SAVE_file << PLAYER2.name << std::endl;

	SAVE_file << PLAYER1.win << std::endl;
	SAVE_file << PLAYER2.win << std::endl;

	SAVE_file << PLAYER1.draw << std::endl;
	SAVE_file << PLAYER2.draw << std::endl;

	SAVE_file << _TURN << std::endl;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
			SAVE_file << A[i][j].c << " ";

		SAVE_file << std::endl;
	}
	SAVE_file.close();
}

std::vector<std::string> LOAD_file()
{
	std::vector<std::string> File;
	std::string NAME_file;
	std::fstream LIST_game;
	LIST_game.open("ListGame.txt", std::ios::in); //read
	while (LIST_game >> NAME_file)
		File.push_back(NAME_file);
	LIST_game.close();
	return File;
}
bool EXIST_file(std::string file)
{
	std::string name; // filename cua cac file da luu trong ListGame.txt
	std::fstream SAVE_file;
	SAVE_file.open("ListGame.txt", std::ios::in); //read only

	while (SAVE_file >> name)
		if (name == file)
		{
			SAVE_file.close();
			return true;
		}

	SAVE_file.close();
	return false;
}

void MoveDown1(Menu menu[COL][MAX_ROW], int option)
{
	showcursor();
	if (Y1 < menu[0][option - 1].y)
	{
		Y1 += 2;
		GotoXY(X1, Y1);
	}
}
void MoveUp1(Menu menu[COL][MAX_ROW], int option)
{
	showcursor();
	if (Y1 > menu[0][0].y) 
	{
		Y1 -= 2;
		GotoXY(X1, Y1);
	}
}

int YESNO_CHOOSE(Menu menu[COL][MAX_ROW])
{
	DrawBoard(1, 1, x_center_console - 14, y_center_console - 5, 29, 9);
	menu[0][0].c = "YES";
	menu[0][1].c = "NO";
	for (int i = 0; i < 2; i++)
	{
		menu[0][i].y = 2 * i + menu[0][0].y; //set coord y for ech option in menu
		GotoXY(menu[0][i].x, menu[0][i].y);
		std::cout << menu[0][i].c << std::endl;
	}
	GotoXY(menu[0][0].x - 1, menu[0][0].y);
	while (1)
	{
		_COMMAND = toupper(_getch());
		if (_COMMAND == 'w' or _COMMAND == arrow_up)
			MoveUp1(menu, 2);
		else if (_COMMAND == 's' or _COMMAND == arrow_down)
			MoveDown1(menu, 2);
		if (_COMMAND == enter_char)
		{
			if (X1 == menu[0][0].x - 1 && Y1 == menu[0][0].y)
				return 1;
			else if (X1 == menu[0][1].x - 1 && Y1 == menu[0][1].y)
				return 0;
		}
	}
}
int LOAD_menu(Menu menu[COL][MAX_ROW])
{
	std::string NAME_file;
	std::vector<std::string> LOAD_files = LOAD_file();
	GotoXY(x_center_console - 1, y_center_console - 4);
	std::cout << "SAVED GAMES";
	DrawBoard(1, 1, x_center_console - 30, y_center_console - 2, 68, 16);
//////////////////////////////////////////////////////////////////////////	
	int size = LOAD_files.size();
	if (size > MAX_ROW) size = MAX_ROW;
	for (int i = 0; i < size; i++)
	{
		menu[0][i].y = 2 * i + menu[0][0].y; //set coord y for ech option in menu
		GotoXY(menu[0][i].x, menu[0][i].y);
		menu[0][i].c = LOAD_files[i];
		std::cout << menu[0][i].c << std::endl;
	}
	GotoXY(X1, Y1);
	while (true)
	{
		_COMMAND = toupper(_getch());
		if (_COMMAND == 's' || _COMMAND == arrow_down)
			MoveDown1(menu, (int)size);
		else if (_COMMAND == 'w' || _COMMAND == arrow_up)
			MoveUp1(menu, (int)size);
		else if (_COMMAND == enter_char)
		{
			for (int i = 0; i < (int)size; i++)
				if (X1 == menu[0][i].x - 1 && Y1 == menu[0][i].y)
					return i;
		}
	}
}
int MAIN_menu(Menu menu[COL][MAX_ROW])
{
	CreateConsoleWindow();
	FixConsoleWindow();
	system("cls");


	title(1);
	title(2);
	title(3);
	title(4);
	Draw(3, 0);

	DrawBoard(1, 1, x_center_console - 10, y_center_console - 1, 25, 10);
	menu[0][0].c = "New game";
	menu[0][1].c = "Load game";
	menu[0][2].c = "About Us";
	menu[0][3].c = "Exit";
	menu[0][4].c = "Settings";

	for (int i = 0; i < 5; i++)
	{
		menu[0][i].y = 2 * i + menu[0][0].y; //set coord y for ech option in menu
		GotoXY(menu[0][i].x, menu[0][i].y);
		std::cout << menu[0][i].c << std::endl;
	}

	GotoXY(X1, Y1);
	while (true)
	{
		_COMMAND = toupper(_getch());
		if (_COMMAND == 's' or _COMMAND == arrow_down)
			MoveDown1(menu, 5);
		else if (_COMMAND == 'w' or _COMMAND == arrow_up)
			MoveUp1(menu, 5);
		else if (_COMMAND == enter_char)
		{
			if (X1 == menu[0][0].x - 1 && Y1 == menu[0][0].y)
				return 1;
			else if (X1 == menu[0][1].x - 1 && Y1 == menu[0][1].y)
				return 2;
			else if (X1 == menu[0][2].x - 1 && Y1 == menu[0][2].y)
				return 3;
			else if (X1 == menu[0][3].x - 1 && Y1 == menu[0][3].y)
				return 4;
			else if (X1 == menu[0][4].x - 1 && Y1 == menu[0][4].y)
				return 5;
		}
	}
}





