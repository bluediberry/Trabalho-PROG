#include "Dictionary.h"
#include "Board.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int main()
{
    // Variáveis
    string Dictionary;
    int Option;
    int Lines, Columns;


    /*  clrscr();
       srand((unsigned int)time(NULL));
       for (int x = 0; x < 80; x++)
       for (int y = 0; y < 24; y++)
       {
       gotoxy(x, y);
       if (rand() % 2 == 0)
       setcolor(x % 15 + 1);
       else
       setcolor(y % 15 + 1, rand() % 2);
       cout << x % 10; */

    cout << "CROSSWORDS PUZZLE CREATOR" << endl;
    cout << "=============================================" << endl;
    cout << "INSTRUCTIONS:" << endl << endl;
    cout << "Position ( LCD / Crtz-Z = Stop)" << endl;
    cout << "LCD stands for Line Column and Direction" << endl;
    // TO COMPLETE
    cout << "----------------------------------------------" << endl;
    cout << "OPTIONS:" << endl;
    cout << "1 - Create Puzzle" << endl;
    cout << "2 - Resume Puzzle" << endl;
    cout << "3 - Exit" << endl;
    cout << "Option ? ";
    cin >> Option;

    if (Option == 1)
    {
        cout << "CREATE PUZZLE" << endl << endl;
        cout << "Dictionary File Name ?" << endl;
        cin >> Dictionary;
        cout << "Board Size (Lines Columns) ? ";
        cin >> Lines >> Columns;

        // Mostrar Board Vazio Com as Dimensoes do Input

        cout << "Position (Line Column Direction / Crtz-z = Stop"

    }

    return 0;
}
