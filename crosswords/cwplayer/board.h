
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
	char getBoard(unsigned int x, unsigned int y);


	/*
 * funcao faz x
 * @param str texto a procurar
 * @return se encontrou texto
 */
	bool CheckBoard(unsigned int x, unsigned int y, Board b1, Dictionary d1);


	/*
 * funcao faz x
 * @param str texto a procurar
 * @return se encontrou texto
 */
	Board(unsigned int x, unsigned int y);




	/*
 * funcao faz x
 * @param str texto a procurar
 * @return se encontrou texto
 */
	void updateBoard(string location, string input);


	/*
 * funcao faz x
 * @param str texto a procurar
 * @return se encontrou texto
 */
	void showBoard(unsigned int x, unsigned int y);


	/*
 * funcao faz x
 * @param str texto a procurar
 * @return se encontrou texto
 */
	bool wordFits(string location, string input);


	/*
 * funcao faz x
 * @param str texto a procurar
 * @return se encontrou texto
 */
	bool checkIfFull(unsigned int x, unsigned int y);


	/*
 * funcao faz x
 * @param str texto a procurar
 * @return se encontrou texto
 */
	void Finish(unsigned int x, unsigned int y);


	/*
 * funcao faz x
 * @param str texto a procurar
 * @return se encontrou texto
 */
	void Write(ofstream& file, string name, unsigned int x, unsigned int y, vector<string> &positions, vector<string> &words);

	/*
* funcao faz x
* @param str texto a procurar
* @return se encontrou texto
*/
	void showEmptyBoard(unsigned int x, unsigned int y);

private:
	unsigned int length, width;
	vector<vector<char> > board;
	int numLines, numCols;
};

#endif
