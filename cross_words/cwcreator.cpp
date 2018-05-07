// contains the main functions for the console application
//
//#include "dictionary.h"
//#include "Board.h"
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

using namespace std;


void uppercase(string &word)
{
	for (unsigned int i = 0; i < word.length(); ++i)
		word[i] = toupper(word[i]);
}


int main()
{
		string dictionary_file;
    ifstream f;
		unsigned int option;
    vector<string> words;
    vector<string> locations;

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
		          //Create_Board();
		          break;
	          }

	   return 0;

}
