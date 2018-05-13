
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Board
{
public:
	Board(unsigned int x, unsigned int y);
	void updateBoard(string location, string input);
	void showBoard(unsigned int x, unsigned int y);
	bool wordFits(string location, string input);
    bool checkIfFull(unsigned int x, unsigned int y);
    void Finish(unsigned int x, unsigned int y);
	void Write(ofstream& file, string name, unsigned int x, unsigned int y, vector<string> &positions, vector<string> &words);

private:
	vector<vector<char> > board;
	int numLines, numCols;
};

#endif
