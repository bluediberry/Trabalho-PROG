#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

void sort(vector<string> &v1)
{
	// Sort elements in their range (start to finish)
	sort(v1.begin(), v1.end());
}


// --- Algorithm that removes duplicate words --- //
void remove_duplicates(vector<string> &v1)
{
	// Considering that the vector is already in order
  v1.erase(unique(v1.begin(), v1.end()), v1.end());
}


void headlines(vector<string> &words, string line)

 {
  string newword = "";
  //words.push_back(line);

  for(int i = 0; i < line.length(); i++) {
//    if(line[i] < 'A' || line[i] > 'Z' || line[i] != ';' || line[i] != ' ')
    if(line[i] < 'A' || line[i] > 'Z' || line[i] != ';' || line[i] != ' ') {
        i++;
        for(int i = 0; i < line.length(); i++)
        {
          if(line[i] >= 'A' && line[i] <= 'Z')
          {
          newword = newword + line[i];
          continue;
          }

         if((line[i] == ';' || line[i] == ' ') && newword != "")
          {
          words.push_back(newword);
          newword = "";
          continue;
          }

          if((line[i] == ';' || line[i] == ' ') && newword == "")
          continue;

      }
    }
  }
}



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

      f.close();


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
	cout << "Number of simple words = " << words.size() << endl;
	cout << "Sorting words ... " << endl;
  sort(words);
	cout << "Removing duplicate words ..." << endl;
  remove_duplicates(words);
	cout << "Number of non-duplicate simple words = " << words.size() << endl;

	cout << "Saving words into file " << word_list_file << " ..." << endl;
      for (int i=0; i < words.size(); i++) {
        fo << words[i] << endl;
        }
        fo.close();



	cout << "End of processing." << endl;


	return 0;
}
