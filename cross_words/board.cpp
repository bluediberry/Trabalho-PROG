#include "board.h"
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <map>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>

using namespace std;

//==========================================================================================
// TEXT COLOR CODES
#define NO_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BROWN "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define LIGHTGRAY "\033[0;37m"
#define DARKGRAY "\033[1;30m"
#define LIGHTRED "\033[1;31m"
#define LIGHTGREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define LIGHTBLUE "\033[1;34m"
#define LIGHTMAGENTA "\033[1;35m"
#define LIGHTCYAN "\033[1;36m"
#define WHITE "\033[1;37m"
// BACKGROUND COLOR CODES
#define BLACK_B "\033[0;40m"
#define RED_B "\033[0;41m"
#define GREEN_B "\033[0;42m"
#define YELLOW_B "\033[0;43m"
#define BLUE_B "\033[0;44m"
#define MAGENTA_B "\033[0;45m"
#define CYAN_B "\033[0;46m"
#define WHITE_B "\033[1;47m"

//==========================================================================================
// Position the cursor at column 'x', line 'y'
// The coodinates of upper left corner of the screen are (x,y)=(0,0)
void gotoxy(int x, int y)
{
    ostringstream oss;
    oss << "\033[" << y << ";" << x << "H";
    cout << oss.str();
}

//==========================================================================================
// Clear the screen
void clrscr(void)
{
    cout << "\033[2J";
    gotoxy(0, 0);
}
//==========================================================================================
// Set text color & background
void setcolor(string color, string background_color)
{
    cout << color << background_color;
}

//
//...
Board::Board(unsigned int x, unsigned int y)
{

  vector<vector<char>> tempBoard(x + 1, vector<char>(y + 1));
	this->numLines = x;
	this->numCols = y;

	for (unsigned int i = 0; i <= x; i++)
		fill(tempBoard.at(i).begin(), tempBoard.at(i).end(), '.');
	tempBoard.at(0).at(0) = ' ';

	for (unsigned int i = 0; i < x; i++)
		tempBoard.at(i + 1).at(0) = 'A' + i;

	for (unsigned int j = 0; j < y; j++)
		tempBoard.at(0).at(j + 1) = 'a' + j;

	this->board = tempBoard;

	}


//
// ...
void Board::showBoard(unsigned int x, unsigned int y)
{
  	for (unsigned int i = 0; i < x + 1; i++)
  	{
  		for (unsigned int j = 0; j < y + 1; j++)
  		{
  			if (i == 0 || j == 0)
  				setcolor(LIGHTRED, LIGHTRED);
  			else
  				setcolor(LIGHTBLUE, LIGHTBLUE);
  			if (j == 0)
  				cout << this->board[i][j] << ' ';
  			else
  			{
  				if (j == y)
  				{
  					cout << setw(2) << this->board[i][j] << ' ';
  				}
  				else
  				cout << setw(2) << this->board.at(i).at(j);
  			}
  		}
  		cout << endl;
  	}
  	setcolor(LIGHTBLUE, LIGHTBLUE);
}

//
// ...
bool Board::wordFits(string location, string input)
{
	int x = location.at(0) - 'A' + 1;
	int y = location.at(1) - 'a' + 1;

	switch (location.at(2))
	{
	case 'H':

		if (input.size() > this->numCols - y + 1)
			return false;

		for (unsigned int n = 0; n < input.size(); n++)
		{
			if ((isupper(board.at(x).at(y + n)) && (board.at(x).at(y + n) != input.at(n))) && (board.at(x).at(y + n) != '.'))
				return false;
		}
		break;

	case 'V':
		if (input.size() > this->numLines - x + 1)
			return false;

		for (unsigned int m = 0; m < input.size(); m++)
		{
			if ((isupper(board.at(x + m).at(y)) && (board.at(x + m).at(y) != input.at(m))) && (board.at(x + m).at(y) != '.'))
				return false;
		}
		break;
	}

    return true;
}

//
// ...
void Board::updateBoard(string location, string input)
{
	int x = location.at(0) - 'A' + 1;
	int y = location.at(1) - 'a' + 1;

	switch (location.at(2))
	{

	case 'H':
		if (y > 1)

			if (board.at(x).at(y - 1) == '.')
				board.at(x).at(y - 1) = '#';

		for (unsigned int n = 0; n < input.size(); n++)
		{
			board.at(x).at(y + n) = input.at(n);
		}
		if (y + input.size() <= this->numCols)
		{
			if (board.at(x).at(y + input.size()) == '.')
				board.at(x).at(y + input.size()) = '#';
		}
		break;

	case 'V':
		if (x > 1)
			if (board.at(x - 1).at(y) == '.')
				board.at(x - 1).at(y) = '#';
		for (unsigned int m = 0; m < input.size(); m++)
		{
			board.at(x + m).at(y) = input.at(m);
		}
		if (x + input.size() <= this->numLines)
		{
			if (board.at(x + input.size()).at(y) == '.')
				board.at(x + input.size()).at(y) = '#';
		}
		break;
	}
}



/*void Board::Write(string &filename, outstream &f)
{

    ofstream outStream;
    string outFileName;

    cout << "Insert name of file to write: ";
    cin >> outFileName;

    outStream.open(outFileName);
    outStream << "Words taken from: " << filename << endl;
    outStream << board;

    for (auto &it : &words) {
        outStream << setw(8) << left << it.first << it.second << endl;
    }

    cout << "Writing finished." << endl;
}*/
