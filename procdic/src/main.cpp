#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
//#include "headlines.h"

using namespace std;



int headlines(vector<string> &words, string line)
 {
   // is a headline?
   for(int i = 0; i < line.length(); i++)
    if(line[i] < 'A' || line[i] > 'Z' || line[i] != ';' || line[i] != ' ')
      return;

  // keep processing
  //ABLE; ABC; ABBA
  string newword = "";
  for(int i = 0; i < line.length(); i++) {


// se caracter for letra
  // word = word + Hletra

  // else se caracter for ; ou espaço e word nao vazia
    // adicojnar word, apagara woerd

  // else se caracter for ; ou esapclo, e word vazia
    // continue;


    // se line i for letr
      newword = newword + line[i];

      // quando line i for ; entao push newoord, newword = ""

  }

  //words.push_back(coisa)

/*

      while (!f.eof()) {
  		getline(f, line);
  		if(line.compare(line.length() - 1 - (line.length()-1), 1, letra) == 0) {
  		cout << "LINE " << ++lineCount << " -> " << line << endl;
  	}
  }
*/
return 0;

}

int numHeadlines(string Hletra)

{
  lastline = linecount/100

/*  for(i=0; i <= linecount;  i++) {
    if(i%100 == 0)
      cout << ".";
      i++;
  }
  */
      return 0;

}



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
    cerr << "File " << dictionary_file << " not found!\n";
    return(1);
  }

  cout << "FILE CONTENTS:\n";
  lineCount = 0;

  vector<string> words;

  while (!f.eof()) {
    getline(f, line);
    headlines(words, line);
  //if(line.compare(line.length() - 1 - (line.length()-1), 1, "A") == 0) {
  //cout << "LINE " << ++lineCount << " -> " << line << endl;
  }

  // words vai conter todas as apalvras simples

  // step 2; tirar dupkicados

//for i < numwords
  //for j < numwords
    // if word[i]  == word[j]
      // words.erase(j)
      //  ctr

   words.sort(0, words.size());

   // step 4
   // for i < words.size()
    // fout << words[i]
}



  //close the file
  f.close();


	cout << "Word list file ? ";
	cin >> word_list_file;
	cout << endl;


	cout << "Extracting simple words from file " << dictionary_file << ", " << endl;
	cout << "beginning with letter ... " << endl << endl;

	cout << "A" << endl;
  numHeadlines("A");
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
