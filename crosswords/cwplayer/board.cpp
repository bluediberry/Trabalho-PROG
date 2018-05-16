#include "board.h"
#include <iomanip>
#include <map>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

//==========================================================================================
// TEXT COLOR CODES
#define LIGHTRED "\033[1;31m"
#define LIGHTBLUE "\033[1;34m"

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
void setcolor(string color, const string background_color)
{
    cout << color << background_color;
}



//==========================================================================================
// layout of the board
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

void Board::reloadBoard(vector<string> &positions, string &location, unsigned int x, unsigned int y) {

    string line;
    string wordTemp;

    //Get number of lines and columns of saved board
    for (size_t i = 2; i < positions.size(); i++)
        if (positions.at(i).empty())
            y = i - 2;
    x = positions.at(2).length() / 2;
    Board(x, y);

  /*  //Reload board using saved user inputs
    for (size_t i = 0; i < positions.size(); i++) {
        string posDir = location.at(i);
        string word = location.at(i).at(1);

        updateBoard(posDir, word);
    }*/

    showBoard(x, y);
}

//
//Load user inputs from file to 2D string vector
void Board::reloadUserInputs( vector<string> &positions, string &location) {

    string tempWord;
    vector<string> tempWordVector;
    unsigned int spaceCounter = 0;
    unsigned int startingPos;

    //Get the starting position of the user inputs segment of the file
    for (size_t i = 0; i < positions.size(); i++) {
        if (positions.at(i).empty())
            spaceCounter++;
        if (spaceCounter == 2) {
            startingPos = ++i;
            break;
        }
    }

    //Load user inputs to 2D vector
    for (size_t i = startingPos; i < positions.size(); i++) {
        for (size_t j = 0; j < positions.at(i).length(); j++) {
            if (j == positions.at(i).length() - 1) {
                tempWord = tempWord + positions.at(i)[j];
                tempWordVector.push_back(tempWord);
                tempWord = "";
                break;
            }

            if (positions.at(i)[j] != ' ')
                tempWord = tempWord + positions.at(i)[j];
            else {

                tempWordVector.push_back(tempWord);
                tempWord = "";

            }
        }
        for (int i = startingPos; i < positions.size(); i++) {
            for (int j = 0; j < positions.at(i).length(); j++) {
                updateBoard(location, tempWord);
                tempWordVector.resize(0);
            }
        }
    }
}

//==========================================================================================
// Displays the board
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

//==========================================================================================
// Checks the board to see if a certain word fits in the desired location
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

//==========================================================================================
// Updates the layout of the board after each positioning intruction
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


//==========================================================================================
// Checks if the current board is full
bool Board::checkIfFull(unsigned int x, unsigned int y)
{
    for (unsigned int i = 0; i < board.size() ; ++i)
        for (unsigned int j = 0; j < board.at(i).size() ; ++j)
            if (board.at(i).at(j) == '.')
                return false;
    return true;
}

//==========================================================================================
// All the leftover . are converted into #
void Board::Finish(unsigned int x, unsigned int y)
{
    unsigned int i, j;
    for (j = 0; j <= x - 1; j++)
        for (i = 0; i <= y - 1; i++)
            if (board[i][j]   == '.')
                board[i][j]   == '#';
}


//==========================================================================================
// Writes the contents of the board in a sequential order
void Board::Write(ofstream& file, string name, unsigned int x, unsigned int y, vector<string> &positions, vector<string> &words)
{
    file << name << endl << endl;

    for (size_t i = 1; i < board.size(); i++) {
        for (size_t j = 1; j < board.at(i).size(); j++)
            file << board.at(i).at(j) << ' ';
        file << endl;
    }
    file << endl;

    sort(positions.begin(), positions.end());

	for (unsigned int i = 0; i < positions.size(); i++)
	{
		file << positions.at(i) << " - " << words.at(i) << endl;
	}

    file.close();
}