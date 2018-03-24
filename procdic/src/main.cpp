#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {

	string dictionary_file;
	string word_list_file;

	cout << "EXTRACTION OF WORLD LIST FROM DICTIONARY" << endl;
	cout << "==========================================" << endl << endl;
	cout << "Dictionary file ? ";
	cin >> dictionary_file;
	cout << "Word list file ? ";
	cin >> word_list_file;
	cout << endl;
	cout << "Extracting simple words from file " << dictionary_file << ", " << endl;
	cout << "beginning with letter ... " << endl << endl;
	cout << "A" << endl;
	//cout << numHeadlines(A) << endl; //vai corresponder a uma funcao que tendo um dado char procura o numero de healines com esse char e escreve . para cada 100
	cout << "B" << endl;
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
