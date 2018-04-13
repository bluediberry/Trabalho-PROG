#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

//Ordena o vetor de words
void sort(vector<string> &v1)
{
	sort(v1.begin(), v1.end());
}

//remove palavras duplicadas do vetor de words
void remove_duplicates(vector<string> &v1)
{
  v1.erase(unique(v1.begin(), v1.end()), v1.end());
}


//recebe linhas e procede ao tratamento das mesmas segundo as regras de headlines
void headlines(vector<string> &words, string line)

 {
  for(int i = 0; i < line.length(); i++) {

					string newword = "";

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

					if(line[i] == '-' || line[i] == '\'')
					 {
					 newword = "";
					 continue;
				 }
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

//abrir a file do dicionario
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

//abrir a file onde sera guardada a lista final
  fo.open(word_list_file);
  if (!fo.is_open())
  {
    cerr << "File " << word_list_file << " not found!\n";
    return(1);
  }

	cout << endl;


	cout << "Extracting simple words from file " << dictionary_file << ", " << endl;
	cout << "beginning with letter ... " << endl << endl;
//fazer cout de . por cada 100 headlines de cada letra
//nao completo
/*		for (int i = 0; i < 26; i++) {
				cout << endl << (char) (65 + i) << endl;
					int wordCount = 0;
						for (int i=0 ; i < words.size(); i++) {
							++wordCount;
									if (wordCount % 100 == 0) {
											cout << ".";
											}
											}
										}*/
	cout << endl;
	cout << "Number of simple words = " << words.size() - 1  << endl;
	cout << "Sorting words ... " << endl;
  sort(words); //ordenar vetor de words
	cout << "Removing duplicate words ..." << endl;
  remove_duplicates(words); //remover duplicados do vetor ordenado
	cout << "Number of non-duplicate simple words = " << words.size() - 1 << endl;

	cout << "Saving words into file " << word_list_file << " ..." << endl;
	//escrever na file designada o vetor de words final
      for (int i=0; i < words.size(); i++) {
        fo << words[i] << endl;
        }
        fo.close();



	cout << "End of processing." << endl;


	return 0;
}
