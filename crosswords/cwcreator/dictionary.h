#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class Dictionary
{
public:
	/*
 * Receives a dicionary file and isolates and saves the synonyms in a vector
 * @param str texto a procurar
 * @return se encontrou texto
 */
	Dictionary(ifstream &f);


	/*
 * Checks to see if a word is present in the dictionary
 * @param
 * @return
 */
	bool isInDictionary(string word);


	/*
 * Return a vector with string of all the isolated words
 * @param
 * @return words vector
 */
	string wordsList(unsigned int i);


	/*
 * Return the number of words in the vector
 * @param str texto a procurar
 * @return se encontrou texto
 */
	int nWords();

private:
	map <string,vector<string> > words;
	vector<string> possibleWords;
};

#endif
