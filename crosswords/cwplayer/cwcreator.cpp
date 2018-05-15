//==========================================================================================
// Contains the main functions for the console application
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <ctype.h>
#include <ctime>
#include <sstream>
#include "dictionary.h"
#include "board.h"

using namespace std;

//==========================================================================================
// Recieves the synonyms dictionary file name
string filename(const string& s)
{
    cout << endl << s << " file name ? ";
    string name;
    cin >> name;
    return name;
}


//==========================================================================================
// Converts all input letters into uppercase letters
void uppercase(string &word)
{
	for (unsigned int i = 0; i < word.length(); ++i)
		word[i] = toupper(word[i]);
}



//==========================================================================================
// Opens the dictionary file
void openFile(string &filename, ifstream &f)
{
	do {
		// Reads the dictionary file name
		cout << "Dictionary File ? ";
		getline(cin, filename);
		// Opens the dictionary file;
		f.open(filename);
		if (!f.is_open())
		{
			cerr << "Dictionary File ? " << filename << " not found !\n";
		}
	} while (!f.is_open());
}

//==========================================================================================
// Opens the board file
void openBoard()
{
    string filename;
    ifstream f;


    do {

        cout << "Board File ? ";
        getline(cin, filename);

        f.open(filename);

        if (!f.is_open())
        {
            cerr << "Board File " << filename << " not found !\n";
        }
    } while (!f.is_open());
}


//
// ...
void reloadBoard() {

    string dFilename;
    string bFilename;
    string line;

    vector<string> reloadContents;
    ifstream f;

    string location;
    string input;
    string filename;
    vector<string> words;
    vector<string> positions;

    unsigned int x;
    unsigned int y;
    //Get save Filename
    do {

        cout << "Board File ? ";
        getline(cin, filename);

        f.open(filename);

        if (!f.is_open())
        {
            cerr << "Board File " << filename << " not found !\n";
        }
    } while (!f.is_open());
    //Save all the contents of the file to a string vector
    while (getline(f, line)) {
        reloadContents.push_back(line);
    }

    //Rebuild dictionary
    dFilename = reloadContents.at(1);
    Dictionary rd1(f);


    //Reload the board and its user inputs
    Board rb1(x, y);
    rb1.reloadUserInputs(positions, location);
    rb1.reloadBoard(positions, location, x, y);
    if (rb1.checkIfFull(x, y)) {
        cout << endl << "This board is already full" << endl;
        cin.clear();
        cin.ignore();
        cout << "Press 'Enter' to continue" << endl;
        getchar();
        return;
    }

   // crosswords(location, input, rd1, rb1, words, positions, x, y);

}

//==========================================================================================
// Shows the available options of the program
int main() {
    string filename;
    ifstream f;
    unsigned int option;
    vector<string> words;
    vector<string> positions;
    unsigned int x, y;

    cout << "CROSSWORDS PUZZLE CREATOR" << endl;
    cout << "=============================================" << endl << endl;
    cout << "INSTRUCTIONS: " << endl << endl;
    cout
            << "The objetive of this Crosswords puzzle creator is to allow you to create a new puzzle from scratch and save it, so that then you can complete it in your own time."
            << endl;
    cout << "In order to do this you start by defining: " << endl;
    cout << "-> The number of rows and columns you want your board to have" << endl;
    cout << "-> The position of the first letter of the word you want to insert on the board." << endl;
    cout << "Position ( LCD / Crtz-Z = Stop)" << endl;
    cout << "LCD stands for Line Column and Direction, and they are introduced in that order." << endl;
    cout << "----------------------------------------------" << endl;
    cout << "OPTIONS: " << endl;
    cout << "1 - Create Puzzle " << endl;
    cout << "2 - Resume Puzzle " << endl;
    cout << "0 - Exit " << endl;
    cout << "Option ?" << endl;
    cin >> option;


    while (option != 1 && option != 2 && option != 0) {
        cout << endl << "Please enter a valid option." << endl;
        cout << endl << "Option ? ";
        cin >> option;
        cin.clear();
        cin.ignore(9999, '\n');
    }

    cout << "-------------------------------------------" << endl;

    switch (option) {
        case 1:
            break;

        case 2:
            break;

        default:
            break;
    }

    return 0;
 }

