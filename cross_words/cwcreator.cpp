// contains the main functions for the console application
// ...
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

//
// ...
string filename(const string& s)
{
    cout << endl << s << " file name ? ";
    string name;
    cin >> name;
    return name;
}


//
// ...
void uppercase(string &word)
{
	for (unsigned int i = 0; i < word.length(); ++i)
		word[i] = toupper(word[i]);
}

//
// ...
void removeWord(string &location, Board &b1, vector<string> &positions, vector<string> &words)
{
	for (unsigned int i = 0; i < positions.size(); i++)
	{
		if (positions.at(i) == location)
		{
			positions.erase(positions.begin() + i);
			words.erase(words.begin() + i);
		}
	}
	for (unsigned int j = 0; j < positions.size(); j++)
	{
		b1.updateBoard(positions.at(j), words.at(j));
	}
}

//
// ...
void resetBoard(Board &b1, unsigned int x, unsigned int y)
{
	Board b2(x, y);
	b1 = b2;
}

//
// ...
void getSuggestion(string &location, Dictionary &d1, Board &b1)
{
	for (unsigned int i = 0; i < d1.nWords(); i++)
	{
		string snnm = d1.wordsList(i);
		uppercase(snnm);
		if (b1.wordFits(location, snnm))
		{
			cout << snnm << " ";
		}
	}
}

//
// ...
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

//
// ...
void save_board(Board &b1, unsigned int x, unsigned int y, vector<string> &positions)
{
    string oname = filename("Board");
    ofstream of;
    of.open(oname);
    if (of.fail())
    {
        cerr << "Error opening file" << endl;
        exit(3);
    }
    cout << "Writing file " << oname << "." << endl;
    b1.Write(of, oname, x, y, positions);
    cin.clear();
    cin.ignore(9999, '\n');
}

//
// ...
void crosswords(string &location, string &input, Dictionary &d1, Board &b1, vector<string> &words, vector<string> &positions,  unsigned int x, unsigned int y)
{

   while (!cin.eof() && !b1.checkIfFull(x, y))
    {

	cout << "Position ( LCD / CTRL-Z = stop ) ? ";
	cin >> location;
	while (!isupper(location.at(0)) || isupper(location.at(1)) || (location.at(2) != 'H' && location.at(2) != 'V'))
	{
		cout << endl << "Please type the first letter in upper case and the second letter in lower case." << endl;
		cin.clear();
		cin.ignore(99999, '\n');
		cout << "Position ( LCD / CTRL-Z = stop ) ? ";
		cin >> location;
	}
	cout << "Word ( - = remove / ? = help ) .. ? ";
	cin >> input;
	uppercase(input);
	while (!d1.isInDictionary(input))
	{
		cin.clear();
		cin.ignore(99999, '\n');
		if (input == "-")
		{
			resetBoard(b1, x, y);
			removeWord(location, b1, positions, words);
			cout << endl;
			b1.showBoard(x, y);
			break;
		}
		if (input == "?")
		{
			getSuggestion(location, d1, b1); //define
		}
		if (input != "?")
		{
			cout << endl;
			cout << "Please insert a valid word." << endl;
			cout << "Word ( - = remove / ? = help ) ..? ";
			cin >> input;
			uppercase(input);
		}
		else
		{
			cout << endl;
			cout << "Word ? ";
			cin >> input;
			uppercase(input);
		}
	}
	if (input != "-")
		if (b1.wordFits(location, input))
		{
			positions.push_back(location);
			words.push_back(input);
			b1.updateBoard(location, input);
			cout << endl;
			b1.showBoard(x, y);
		}

    }

        cin.clear();
        cout << "============================" << endl;
        cout << "        SAVE BOARD " << endl;
        cout << "============================" << endl << endl;
        cout << "1) Save to complete later." << endl;
        cout << "2) Save and finish." << endl;
        cout << "3) Do not save." << endl;
        int option;
        cin >> option;
        while (option > 3 || option < 1 || cin.fail() || cin.eof()) {
            cin.clear();
            cin.ignore(10, '\n');
            cout << "Invalid option! Try again." << endl;
            cin >> option;
        }
        switch (option) {
            case 1:
                save_board(b1, x, y, positions);
                break;
            case 2:
                b1.Finish(x, y);
                save_board(b1, x, y, positions);
                break;
            case 3:
                return;
        }

}

//
// ...
void createBoard()
{
	unsigned int x;
	unsigned int y;
	string location;
	string input;
	string filename;
	ifstream f;
	vector<string> words;
	vector<string> positions;

	cout << "CREATE PUZZLE" << endl;
	cout << "-------------------------------------------" << endl;
	openFile(filename, f);
	Dictionary d1(f);
	cout << "Board size (lines columns) ? ";
	cin >> x >> y;
	while ((x > 26 || y > 26) || (x <= 0 || y <= 0))
	{
		cout << endl << "Please choose a number between 1 and 26." << endl;
		cin.clear();
		cin.ignore(99999, '\n');
		cout << endl << "Board size (lines columns)? ";
		cin >> x >> y;
	}
	Board b1(x, y);
	cout << endl;
	b1.showBoard(x, y);

	while (cin)
	{

		cout << endl;
		crosswords(location, input, d1, b1, words, positions, x, y);

	}
}

//
// ...
int main()
{
		string filename;
    ifstream f;
		unsigned int option;
    vector<string> words;
    vector<string> positions;

		cout << "CROSSWORDS PUZZLE CREATOR" << endl;
    cout << "=============================================" << endl << endl;
		cout << "INSTRUCTIONS: " << endl << endl;
    cout << "The objetive of this Crosswords puzzle creator is to allow you to create a new puzzle from scratch and save it, so that then you can complete it in your own time." << endl;
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


    while (option != 1 && option != 2 && option != 0)
	     {
		        cout << endl << "Please enter a valid option." << endl;
		        cout << endl << "Option ? ";
		        cin >> option;
		        cin.clear();
		        cin.ignore(9999, '\n');
	      }

	       cout << "-------------------------------------------" << endl;

	        switch (option)
	         {
	             case 1:
                     createBoard();
		             break;

                 case 2:
                     break;

                 default:
                     break;
	          }

	   return 0;

}
