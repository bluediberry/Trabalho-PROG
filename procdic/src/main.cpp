#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;


void headlines(vector<string> &words, string line)
 {
   //words.push_back("Hello");


   for(int i = 0; i < line.length(); i++) {

     if(line[i] < 'A' || line[i] > 'Z' || line[i] != ';' || line[i] != ' ')
         return;

    string newword = "";
    for(int i = 0; i < line.length(); i++)
      {
      if(line[i] >= 'A' && line[i] <= 'Z')
            newword = newword + line[i];

      if(line[i] == ';' || line[i] == ' ') {
            words.push_back(newword);
            newword = "";
        }

       if(line[i] == ';' || line[i] == ' ')
          continue;
   }
  }
}

/*int numHeadlines(string Hletra)

{
      return 0;
}*/



int main() {

	string dictionary_file;
	string word_list_file;
	ifstream f;
  ofstream fo;
	string line;
  vector<string> words;


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


  while (!f.eof()) {
    getline(f, line);
    headlines(words, line);
  }

  // words vai conter todas as apalvras simples

  // step 2; tirar dupkicados

//for i < numwords
  //for j < numwords
    // if word[i]  == word[j]
      // words.erase(j)
      //  ctr

  // words.sort(0, words.size());

   // step 4
   // for i < words.size()
    // fout << words[i]


	cout << "Word list file ? ";
	cin >> word_list_file;

  fo.open(word_list_file);
  if (!fo.is_open())
  {
    cerr << "File " << word_list_file << " not found!\n";
    return(1);
  }

	cout << endl;


	cout << "Extracting simple words from file " << dictionary_file << ", " << endl;
	cout << "beginning with letter ... " << endl << endl;
	cout << endl;
	cout << "Number of simple words = " /* << função que da o numero de simple words */ << endl;
	cout << "Sorting words ... " << endl;
	cout << "Removing duplicate words ..." << endl;
	cout << "Number of non-duplicate simple words = " /* << função que da o numero de non duplicate simple words */<< endl;

	cout << "Saving words into file " << word_list_file << " ..." << endl;
      for (int i=0; i < words.size(); i++) {
        fo << words[i] << endl;
        }
        fo.close();
        f.close();



	cout << "End of processing." << endl;


	return 0;
}
