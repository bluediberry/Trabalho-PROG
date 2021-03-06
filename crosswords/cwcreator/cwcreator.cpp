//==========================================================================================
// Contains the main functions for the console application
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include "dictionary.h"
#include "board.h"
#include <sstream>

using namespace std;

void createBoard();

int exit();

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
		word[i] = toupper(word[i]); //the word is converted into all uppercase
}

//==========================================================================================
// Removes a word that was previously placed on the board
void removeWord(string &location, Board &b1, vector<string> &positions, vector<string> &words)
{
	for (unsigned int i = 0; i < positions.size(); i++)
	{
		if (positions.at(i) == location)
		{
			positions.erase(positions.begin() + i); //erases from the positions vector
			words.erase(words.begin() + i); //erases from the words vector
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
        uppercase(syn); //shows all synonyms in uppercase
        if (b1.wordFits(location, syn))
        {
            fittingWords.push_back(syn); //if a synonym is valid its pushed onto the fitting words vector
        }
    }

    sort(fittingWords.begin(), fittingWords.end()); //rearranges the synonyms vector
    fittingWords.erase(unique(fittingWords.begin(), fittingWords.end()), fittingWords.end()); //deletes duplicates

    srand(time(NULL));
    //if possible, shows a list compromised of 5 random words out the synonyms vector that fit the location
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
    string filename = "b" + filenameb.str() + ".txt"; //format of the board save file
    of.open(filename); //opens the file
    if (of.fail())
    {
        cerr << "Error in opening file" << endl;
        exit(3);
    }
    cout << "Writing to file " << filename << "." << endl;

    b1.Write(of, filename, x, y, positions, words); //writes the board to the previously open file
    cin.clear();
    cin.ignore(9999, '\n');

    exit();
}


/*void save_Interface(unsigned int &x, unsigned int &y, string &location, string &input, vector<string> &positions, vector<string> &words, Board &b1)
{


    cin.ignore(10000);
    cin.clear();
    cout << endl;
    cout << "============================" << endl;
    cout << "        SAVE BOARD " << endl;
    cout << "============================" << endl << endl;
    cout << "1) Save to complete later." << endl;
    cout << "2) Save and finish." << endl;
    cout << "3) Do not save." << endl;
    cout << "4) Do not save and Restart" << endl;
    cin.ignore(10000);
    cin.clear();


    int option;
    cin >> option;

    while (option > 4 || option < 1) {
        cin.ignore(10, '\n');
        cin.clear();

        cout << "Invalid option! Try again." << endl;
        cin >> option;
    }
    switch (option) {
        case 1:
            save_board(b1 , x, y, positions, words);
            exit();
            break;
        case 2:
            b1.Finish(x, y);
            save_board(b1, x, y, positions, words);
            exit();
            break;
        case 3:
            exit();
            return;
        case 4:
            createBoard();
            exit();
            break;
    }
}*/

//==========================================================================================
// Deals with processing words and positioning on the board
void crosswords(string &location, string &input, Dictionary &d1, Board &b1, vector<string> &words, vector<string> &positions,  unsigned int x, unsigned int y)
{
    vector<string> fittingWords;
    int numberOfFittingWords;

    cin.ignore(99999, '\n');
    cout << "Position ( LCD / CTRL-Z = stop ) ? ";
    cin >> location;

        if (location == "CTRL-Z") //equivalent of cin.eof(), terminates the program and saves
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
                    save_board(b1, x, y, positions, words); //saves the board as is
                    exit();
                    break;
                case 2:
                    b1.Finish(x, y); //the board is finished and cannot be continued later
                    save_board(b1, x, y, positions, words);
                    exit();
                    break;
                case 3:
                    exit();
                    break;
                case 4:
                    createBoard(); //returns to the crate board interface
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
        uppercase(input); //converts the input into uppercase
        while (!d1.isInDictionary(input)) { //checks all the valid and invalid inputs
            cin.clear();
            cin.ignore(9000000, '\n');
            if (input == "-") {
                resetBoard(b1, x, y);
                removeWord(location, b1, positions, words); //deletes a previously placed word
                cout << endl;
                b1.showBoard(x, y);
                break;
            }
            if (input == "?") {
                getSuggestion(location, d1, b1, fittingWords, numberOfFittingWords); //show a list of words that can be placed
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
            }
            else {

                if (input != "-") {
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
            }

    }

}

//==========================================================================================
// Creates a new board with the desired width and length and in the end saves it
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

	cout << "                 CREATE BOARD" << endl;
    cout << "=============================================" << endl;

    cin.ignore(1000,  '\n');
    cin.clear();

	openFile(filename, f); //opens the dicitionary synonyms file
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
	Board b1(x, y); //creates a board with the specified size
	cout << endl;
	b1.showBoard(x, y); //shows the board on the screen

        while (!cin.eof() && !b1.checkIfFull(x, y)) { //ends if eof or if the board is full

            cout << endl;
            crosswords(location, input, d1, b1, words, positions, x, y);

        }


   if(cin.fail()) {
        if(!cin.eof())
            cin.ignore(1000,  '\n');
        cin.clear();
    }



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
            save_board(b1, x, y, positions, words);
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
        case 4:
            createBoard();
            exit();
            break;
    }
}

//==========================================================================================
// Opens the board file
void openBoard(string &filename, ifstream &f)
{

        do {

        cout << "Board File Name? ";
        getline(cin, filename);

        f.open(filename); //open the board fiel

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

    openBoard(filename, f); //opens the board

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
            if(line.find_first_of('.') != string::npos) //if there are . that means the board is unfinished
                unfinished = true;

        if(lines == 2) { y = line.length() / 2; }

        if(line.length() > 0)
            if(line.find('-') != string::npos) //the - divides the positions from the placed word
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
    openFile(dictFile, dictionaryFile); //opens the dictionary file
    Dictionary rd1(dictionaryFile);


    Board rb1(x,y); //creates a new board with the same size as the last one

    for (unsigned int i = 0; i < positions.size(); i++) {
        rb1.updateBoard(positions.at(i), words.at(i)); //places all the user inputs back onto the board again
    }




   cout << endl;

    if(unfinished) {

        rb1.showBoard(x, y);

        do {

            cin.ignore(1000, '\n');
            cin.clear();


            while (!cin.eof() && !rb1.checkIfFull(x, y)) {

                cout << endl;
                crosswords(location, input, rd1, rb1, words, positions, x, y); //continues the crosswords word placement

            }

            if(!rb1.CheckBoard(x, y, rb1, rd1)) { //does a check to see if all words are valid

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
                rb1.Finish(x, y);
                save_board(rb1, x, y, positions, words);
                exit();
                break;
            case 3:
                exit();
                break;
        }
         }
    else
    {
        rb1.Finish(x, y);
        rb1.showBoard(x, y);
        cout << "This Board is already completed" << endl;
    }
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

    cout << "=============================================" << endl;
    cout << "          CROSSWORDS PUZZLE CREATOR" << endl;
    cout << "=============================================" << endl << endl;
    cout << "INSTRUCTIONS: " << endl << endl;
    cout << "================================================" << endl;
    cout << "The objetive of this Crosswords puzzle creator is to allow you to create a new board puzzle from scratch" << endl;
    cout << "and save it, so that then you can complete it in your own time." << endl;
    cout << "In order to do this you start by defining: " << endl;
    cout << "[1] The number of rows and columns you want your board to have" << endl;
    cout << "[2] The position of the first letter of the word you want to insert on the board:" << endl;
    cout << "Position ( LCD / Crtz-Z = Stop)" << endl;
    cout << "LCD stands for Line Column and Direction, and they are introduced in that order." << endl;
    cout << "=============================================" << endl;
    cout << "OPTIONS: " << endl;
    cout << "=============================================" << endl;
    cout << "[1] Create Puzzle " << endl;
    cout << "[2] Resume Puzzle " << endl;
    cout << "[0] Exit " << endl;
    cout << "Option ?" << endl;
    cin >> option;


    while (option != 1 && option != 2 && option != 0) {
        cout << endl << "Please enter a valid option." << endl;
        cout << endl << "Option ? ";
        cin >> option;
        cin.clear();
        cin.ignore(9999, '\n');
    }

    cout << "=============================================" << endl;

    switch (option) {
        case 1:
            createBoard();
            break;

        case 2:
            reloadBoard(x, y, location, input, positions, words);
            break;

        default:
            break;
    }

    return 0;
 }

