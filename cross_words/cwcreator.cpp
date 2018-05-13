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
void getSuggestion(string &location, Dictionary &d1, Board &b1, vector<string> &fittingWords, int &numberOfFittingWords)
{
    for (unsigned int i = 0; i < d1.nWords(); i++)
    {
        string syn = d1.wordsList(i);
        uppercase(syn);
        if (b1.wordFits(location, syn))
        {
            fittingWords.push_back(syn);
        }
    }

    sort(fittingWords.begin(), fittingWords.end());
    fittingWords.erase(unique(fittingWords.begin(), fittingWords.end()), fittingWords.end());

    srand(time(NULL));
    if (fittingWords.size() == 0)
        cout << "No words fit in that location." << endl;
    else
    {
        if (fittingWords.size() >= 5)
        {
            numberOfFittingWords = fittingWords.size();
            for (int j = 0; j < 5; j++)
            {
                int random = rand() % fittingWords.size();
                cout << fittingWords.at(random) << endl;
                fittingWords.erase(find(fittingWords.begin(), fittingWords.end(), fittingWords.at(random)));
            }
        }
        else
        {
            numberOfFittingWords = fittingWords.size();
            for (int j = 0; j < numberOfFittingWords; j++)
            {
                int random = rand() % fittingWords.size();
                cout << fittingWords.at(random) << endl;
                fittingWords.erase(find(fittingWords.begin(), fittingWords.end(), fittingWords.at(random)));
            }
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
void save_board(Board &b1, unsigned int x, unsigned int y, vector<string> &positions, vector<string> &words)
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
    b1.Write(of, oname, x, y, positions, words);
    cin.clear();
    cin.ignore(9999, '\n');


}

//
// ...
void crosswords(string &location, string &input, Dictionary &d1, Board &b1, vector<string> &words, vector<string> &positions,  unsigned int x, unsigned int y)
{
    vector<string> fittingWords;
    int numberOfFittingWords;
    cout << "Position ( LCD / CTRL-Z = stop ) ? ";
    cin >> location;
    while (!isupper(location.at(0)) || isupper(location.at(1)) || (location.at(2) != 'H' && location.at(2) != 'V')) {
        cout << endl
             << "Please type the first letter in upper case, the second letter in lower case and the third letter as either 'H' or 'V'."
             << endl;
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Position ( LCD / CTRL-Z = stop ) ? ";
        cin >> location;
    }
    if (cin) {
        cout << "Word ( - = remove / ? = help ) ..? ";
        cin >> input;
        uppercase(input);
        while (!d1.isInDictionary(input)) {
            cin.clear();
            cin.ignore(9000000, '\n');
            if (input == "-") {
                resetBoard(b1, x, y);
                removeWord(location, b1, positions, words);
                cout << endl;
                b1.showBoard(x, y);
                break;
            }
            if (input == "?") {
                getSuggestion(location, d1, b1, fittingWords, numberOfFittingWords);
            }
            if (input != "?") {
                cout << endl;
                cout << "Word not in the dictionary." << endl;
                cout << "Word ( - = remove / ? = help ) ..? ";
                cin >> input;
                uppercase(input);
            } else {
                if (numberOfFittingWords > 0) {
                    cout << endl;
                    cout << "Word ..? ";
                    cin >> input;
                    uppercase(input);
                } else
                    break;
            }
        }


        if (input == "?")
            if (numberOfFittingWords == 0);
            else {
                if (input != "-")
                    if (b1.wordFits(location, input) && find(words.begin(), words.end(), input) == words.end()) {
                        positions.push_back(location);
                        words.push_back(input);
                        b1.updateBoard(location, input);
                        cout << endl;
                        b1.showBoard(x, y);
                    } else {
                        cout << endl << "Please choose a word that is possible to place." << endl;
                    }
            }
        else {

            if (input != "-")
                if (b1.wordFits(location, input) && find(words.begin(), words.end(), input) == words.end()) {
                    positions.push_back(location);
                    words.push_back(input);
                    b1.updateBoard(location, input);
                    cout << endl;
                    b1.showBoard(x, y);
                }
                else
                {
                    cout << endl << "Please choose a word that is possible to place." << endl;
                }
        }
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

        while (!cin.eof() && !b1.checkIfFull(x, y)) {

            cout << endl;
            crosswords(location, input, d1, b1, words, positions, x, y);

        }
    
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "============================" << endl;
    cout << "        SAVE BOARD " << endl;
    cout << "============================" << endl << endl;
    cout << "1) Save to complete later." << endl;
    cout << "2) Save and finish." << endl;
    cout << "3) Do not save." << endl;
    cout << "4) Do not save and Restart" << endl;
    int option;
    cin >> option;
    while (option > 4 || option < 1 || cin.fail() || cin.eof()) {
        cin.clear();
        cin.ignore(10, '\n');
        cout << "Invalid option! Try again." << endl;
        cin >> option;
    }
    switch (option) {
        case 1:
            save_board(b1 , x, y, positions, words);
            break;
        case 2:
            b1.Finish(x, y);
            save_board(b1, x, y, positions, words);
            break;
        case 3:
            return;
        case 4:
            createBoard();
            break;
    }
}

//
// ...
int main() {
    string filename;
    ifstream f;
    unsigned int option;
    vector<string> words;
    vector<string> positions;

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
            createBoard();
            break;

        case 2:
            break;

        default:
            break;
    }

    return 0;
 }

