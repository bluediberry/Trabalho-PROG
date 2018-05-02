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

    cout << "CROSSWORDS PUZZLE CREATOR" << endl << endl;

    cout << "INSTRUCTIONS:" << endl << endl;
    cout << "Position (Line Column Direction / Crtz-Z = Stop)" << endl;
    // TO COMPLETE

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
