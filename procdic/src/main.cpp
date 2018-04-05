#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {

	string dictionary_file;
	string word_list_file;
	ifstream f;
	string line;
	int lineCount;


	cout << "EXTRACTION OF WORLD LIST FROM DICTIONARY" << endl;
	cout << "==========================================" << endl << endl;
	cout << "Dictionary file ? ";
	cin >> dictionary_file;


	f.open(dictionary_file);
	if (!f.is_open())
	{
		cerr << "File " << dictionary_file << " not found !\n";
		return(1);
	}


	cout << "FILE CONTENTS:\n";
	lineCount = 0;
	while (!f.eof())
	{
		getline(f, line);
		cout << "LINE " << ++lineCount << " -> " << line << endl; // TO DO: process the line }

		//close the file
		f.close();
		return 0;
	}

	cout << "Word list file ? ";
	cin >> word_list_file;
	cout << endl;


	cout << "Extracting simple words from file " << dictionary_file << ", " << endl;
	cout << "beginning with letter ... " << endl << endl;
	cout << "A" << endl;
	//cout << numHeadlines(A) << endl; //vai corresponder a uma funcao que tendo um dado char procura o numero de healines com esse char e escreve . para cada 100
	cout << "B" << endl;
	cout << "C" << endl;
	cout << "D" << endl;
	cout << "E" << endl;
	cout << "F" << endl;
	cout << "G" << endl;
	cout << "H" << endl;
	cout << "I" << endl;
	cout << "J" << endl;
	cout << "K" << endl;
	cout << "L" << endl;
	cout << "M" << endl;
	cout << "N" << endl;
	cout << "O" << endl;
	cout << "P" << endl;
	cout << "Q" << endl;
	cout << "R" << endl;
	cout << "S" << endl;
	cout << "T" << endl;
	cout << "U" << endl;
	cout << "V" << endl;
	cout << "X" << endl;
	cout << "Y" << endl;
	cout << "Z" << endl;
	//etc...
	cout << endl;
	cout << "Number of simple words = " /* << função que da o numero de simple words */ << endl;
	cout << "Sorting words ... " << endl;
	cout << "Removing duplicate words ..." << endl;
	cout << "Number of non-duplicate simple words = " /* << função que da o numero de non duplicate simple words */<< endl;
	cout << "Saving words into file " << word_list_file << " ..." << endl;
	cout << "End of processing." << endl;


	return 0;
}
