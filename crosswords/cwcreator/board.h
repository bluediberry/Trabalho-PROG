
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <vector>
#include "dictionary.h"

using namespace std;

class Board
{
public:
    /*
     * funcao faz x
     * @param str texto a procurar
     * @return se encontrou texto
     */
	Board();
	Board(unsigned int x, unsigned int y);
    void reloadUserInputs(vector<string> &positions, string &location);
    void reloadBoard(vector<string> &positions, string &location, unsigned int x, unsigned int y);
	void reloadBoard(ifstream& file);
	void updateBoard(string location, string input);
	void showBoard(unsigned int x, unsigned int y);
	bool wordFits(string location, string input);
    bool checkIfFull(unsigned int x, unsigned int y);
    void Finish(unsigned int x, unsigned int y);
	void Write(ofstream& file, string name, unsigned int x, unsigned int y, vector<string> &positions, vector<string> &words);

private:
	unsigned int length, width;
	vector<vector<char> > board;
	int numLines, numCols;
};

#endif
