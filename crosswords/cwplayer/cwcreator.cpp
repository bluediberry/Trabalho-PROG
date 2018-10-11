//==========================================================================================
// Contains the main functions for the console application
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include "dictionary.h"
#include "board.h"
#include "player.h"
#include <sstream>
#include <chrono>
#include <ctime>

using namespace std;

//void createBoard();

int exit();


//==========================================================================================
// Converts all input letters into uppercase letters
void uppercase(string &word)
{
    for (unsigned int i = 0; i < word.length(); ++i)
        word[i] = toupper(word[i]);
}

//==========================================================================================
// Removes a word that was previously placed on the board
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

//==========================================================================================
// Starts a new board
void resetBoard(Board &b1, unsigned int x, unsigned int y)
{
    Board b2(x, y);
    b1 = b2;
}

//==========================================================================================
// Gives suggestions of appropriate words that can be placed in a certain spot
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
        cout << "There are no available words that fit in that location" << endl;
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
// Saves a complete or incomplete board into a text file
void save_board(Board &b1, unsigned int x, unsigned int y, vector<string> &positions, vector<string> &words)
{

    static unsigned int boardnr = 0;
    boardnr++;
    ofstream of;

    stringstream filenameb;
    filenameb << setw(3) << setfill('0') << boardnr;
    string filename = "b" + filenameb.str() + "_p.txt";
    of.open(filename);
    if (of.fail())
    {
        cerr << "Error in opening file" << endl;
        exit(3);
    }
    cout << "Writing to file " << filename << "." << endl;

    b1.Write(of, filename, x, y, positions, words);
    cin.clear();
    cin.ignore(9999, '\n');

    exit();
}

//==========================================================================================
// Deals with processing words and positioning on the board
void crosswords(string &location, string &input, Dictionary &d1, Board &b2, vector<string> &words, vector<string> &positions,  unsigned int x, unsigned int y)
{
    vector<string> fittingWords;
    int numberOfFittingWords;

    cin.ignore(99999, '\n');
    cout << "Position ( LCD / CTRL-Z = stop ) ? ";
    cin >> location;

    if (location == "CTRL-Z")
    {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "=============================================" << endl;
        cout << "                 SAVE BOARD " << endl;
        cout << "=============================================" << endl << endl;
        cout << "[1] Save to complete later." << endl;
        cout << "[2] Save and finish." << endl;
        cout << "[3] Do not save." << endl;
        cout << "[4] Do not save and Restart" << endl;
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
                save_board(b2, x, y, positions, words);
                exit();
                break;
            case 2:
                b2.Finish(x, y);
                save_board(b2, x, y, positions, words);
                exit();
                break;
            case 3:
                exit();
                break;
            case 4:
               // createBoard();
                exit();
                break;
        }
    }


    while (!isupper(location.at(0)) || isupper(location.at(1)) || (location.at(2) != 'H' && location.at(2) != 'V')) {
        cout << endl
             << "Please type the first letter in upper case, the second letter in lower case and the third letter as either 'H' or 'V'."
             << endl;
        cin.clear();
        cin.ignore(99999, '\n');
        cout << "Position ( LCD / CTRL-Z = stop ) ? ";
        cin >> location;
        if (location != "CTRL-Z")
            return;
    }

    if (cin) {
        cout << "Word ( - = remove / ? = help ) ..? ";
        cin >> input;
        uppercase(input);
        while (!d1.isInDictionary(input)) {
            cin.clear();
            cin.ignore(9000000, '\n');
            if (input == "-") {
                resetBoard(b2, x, y);
                removeWord(location, b2, positions, words);
                cout << endl;
                b2.showBoard(x, y);
                break;
            }
            if (input == "?") {
                getSuggestion(location, d1, b2, fittingWords, numberOfFittingWords);
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
                if (input != "-") {
                    if (b2.wordFits(location, input) && find(words.begin(), words.end(), input) == words.end()) {
                        positions.push_back(location);
                        words.push_back(input);
                        b2.updateBoard(location, input);
                        cout << endl;
                        b2.showBoard(x, y);
                    } else {
                        cout << endl << "Please choose a word that is possible to place." << endl;
                    }
                }
            }
        else {

            if (input != "-") {
                if (b2.wordFits(location, input) && find(words.begin(), words.end(), input) == words.end()) {
                    positions.push_back(location);
                    words.push_back(input);
                    b2.updateBoard(location, input);
                    cout << endl;
                    b2.showBoard(x, y);
                } else {
                    cout << endl << "Please choose a word that is possible to place." << endl;
                }
            }
        }

    }

}

//==========================================================================================
// Opens the board file
void openBoard(string &filename, ifstream &f)
{

    do {

        cout << "Board File Name? ";
        getline(cin, filename);

        f.open(filename);

        if (!f.is_open())
        {
            cerr << "Board File " << filename << " not found !\n";
        }
    } while (!f.is_open());
}


//==========================================================================================
// Read from a preexisting board text file and reloads the board onto the screen
void reloadBoard(unsigned int &x, unsigned int &y, string &location, string &input, vector<string> &positions, vector<string> &words) {

    string filename;
    ifstream f;

    string dictFile;
    ifstream dictionaryFile;
    string saveFileName;
    ofstream of;
    int min = 0;
    int max = 0;
    string line;
    bool unfinished = false;


    cout << "               RELOAD BOARD" << endl;
    cout << "=============================================" << endl;

    cin.ignore(1000,  '\n');
    cin.clear();

    openBoard(filename, f);

    while(getline(f, line))
    {
        static int lines = 0;

        if(lines == 0)
            dictFile = lines;

        if(line.size() == 0 && min == 0)
            min = lines;

        if(line.size() == 0 && min != 0 && max == 0)
            max = lines - 1;

        if(lines > 1)
            if(line.find_first_of('.') != string::npos)
                unfinished = true;

        if(lines == 2) { y = line.length() / 2; }

        if(line.length() > 0)
            if(line.find('-') != string::npos)
            {
                positions.push_back(line.substr(0, line.find('-') - 1));
                words.push_back(line.substr(line.find('-') + 2, line.length()));
            }

        lines++;


    }

    x = max - min;

    f.clear();
    dictionaryFile.clear();
    cin.ignore(1000,  '\n');
    cin.clear();
    if(unfinished)
        openFile(dictFile, dictionaryFile);
    Dictionary rd1(dictionaryFile);


    Board b1(x,y);

    for (unsigned int i = 0; i < positions.size(); i++) {
        b1.updateBoard(positions.at(i), words.at(i));
    }




    cout << endl;

/*    if(unfinished) {

        b2.showEmptyBoard(x, y);

        do {

            cin.ignore(1000, '\n');
            cin.clear();


            while (!cin.eof() && !rb1.checkIfFull(x, y)) {

                cout << endl;
                crosswords(location, input, rd1, rb1, words, positions, x, y);

            }

            if(!rb1.CheckBoard(x, y, rb1, rd1)) {

                cout << "This board can't be finished because it contains invalid words." << endl;
            }

        } while(!rb1.CheckBoard(x, y, rb1, rd1));


        cin.ignore(1000,  '\n');
        cin.clear();

        cout << "=============================================" << endl;
        cout << "                 SAVE BOARD " << endl;
        cout << "=============================================" << endl << endl;
        cout << "[1] Save to complete later." << endl;
        cout << "[2] Save and finish." << endl;
        cout << "[3] Do not save." << endl;
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
                save_board(rb1, x, y, positions, words);
                exit();
                break;
            case 2:
                b1.Finish(x, y);
                save_board(b1, x, y, positions, words);
                exit();
                break;
            case 3:
                exit();
                break;
        }
    }
    else
    {
        b1.Finish(x, y);
        b1.showBoard(x, y);
        cout << "This Board is already completed" << endl;
    }
    */
}

void play_game(string &location, string &input, vector<string> &positions, vector<string> &words, Player name, Board b1, unsigned int x, unsigned int y, Dictionary &d1) {

    cout << "=============================================" << endl;
    cout << "               Game Start" << endl;
    cout << "=============================================" << endl;
    cout << endl << "Welcome, " << name.getName() << endl << endl;

   // b1.Finish(x,y);

    Board b2(x,y);

   while(!cin.eof() && !b2.checkIfFull(x,y))   {


        b2.showEmptyBoard(x, y);

       crosswords(location, input, d1, b2, words, positions, x, y);

    }



}

//=================================

Player player_name()
{
    string name;
    cout << "Player's name? "; cin >> name;
    return Player(name);
}

//==========================================================================================
// Terminates the program
int exit() {
    exit(0);
}


//==========================================================================================
// Shows the available options of the program
int main() {
    string filename;
    ifstream f;
    unsigned int option;
    string location;
    string input;
    vector<string> words;
    vector<string> positions;
    unsigned int x, y;

    Dictionary d1(f);
    srand(time(NULL));
    Board b1(x,y);

    cout << "=============================================" << endl;
    cout << "          CROSSWORDS PUZZLE GAME" << endl;
    cout << "=============================================" << endl << endl;
    cout << "OPTIONS:" << endl;
    cout << "[1] Play Crossword Game" << endl;
    cout << "[0] Exit" << endl << endl;
    cout << "Option ? ";
    cin >> option;

    while (option > 1 || option < 0 || cin.fail() || cin.eof()) {
        cout << endl << "Please enter a valid option." << endl;
        cout << endl << "Option ? ";
        cin >> option;
        cin.clear();
        cin.ignore(9999, '\n');
    }

    cout << "=============================================" << endl;

    if(option == 1) {
            reloadBoard(x, y, location, input, positions, words);
            cout << "=============================================" << endl;
            cout << "Loading game...." << endl;
            cout << "=============================================" << endl;
            Player player = player_name();

            play_game(location, input, positions, words, player, b1, x, y, d1);

    }
    else if(option == 0) exit();

    return 0;
}

