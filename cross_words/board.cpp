#include "board.h"
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

#define BLACK 0
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define WHITE 15
#define LIGHTGRAY 7
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6

void clrscr(void)
{
 COORD coordScreen = { 0, 0 }; // upper left corner
 DWORD cCharsWritten;
 DWORD dwConSize;
 HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
 CONSOLE_SCREEN_BUFFER_INFO csbi;
 GetConsoleScreenBufferInfo(hCon, &csbi);
 dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
 // fill with spaces
 FillConsoleOutputCharacter(hCon, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
 GetConsoleScreenBufferInfo(hCon, &csbi);
 FillConsoleOutputAttribute(hCon, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
 // cursor to upper left corner
 SetConsoleCursorPosition(hCon, coordScreen);
}


//==========================================================================================
// Position the cursor at column 'x', line 'y'
// The coodinates of upper left corner of the screen are (x,y)=(0,0)
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// COLOR
void setcolor(unsigned int color)
{
  HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon, color); }

void setcolor(unsigned int color, unsigned int background_color)
{
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
if (background_color == BLACK)
SetConsoleTextAttribute(hCon, color);
else     SetConsoleTextAttribute(hCon, color | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}


Board::Board(string lines, string columns)
{
	lines = stoi(lines, nullptr, 10);
	columns = stoi(columns, nullptr, 10);

	//MATRIX BOARD
	matrix.resize(lines);

	for (int i = 0; i < matrix.size(); i++)
		matrix[i].resize(columns);

	for (int i = 0; i < matrix.size(); i++)
		fill(matrix[i].begin(), matrix[i].end(), '.');


	//NAME LINES
	name_lines.resize(lines);


	for (int i = 0; i < name_lines.size(); i++)
	{
		char letter = 'a' + i;
		name_lines[i] = letter;
	}

	// NAME COLUMNS
	name_columns.resize(columns);


	for (int i = 0; i < name_columns.size(); i++)
	{
		char letter = 'A' + i;
		name_columns[i] = letter;
	}

}

void Board::Show()
{
	cout << ' ';
	// PRINT name of lines
	setcolor(LIGHTRED);

	for (int i = 0; i < lines; i++)
	{
		cout << ' ' << name_lines[i];
	}

	cout << endl;

	for (int i = 0; i < columns; i++)
	{
		setcolor(LIGHTRED, BLACK);
		cout << name_columns[i] << ' ';

		setcolor(BLACK, LIGHTGRAY);
		for (int a = 0; a < lines; a++)
			cout << matrix[a][i] << ' ';
		cout << endl;
	}
	cout << endl;
}
