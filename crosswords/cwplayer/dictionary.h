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
	Dictionary(ifstream &f);
	bool isInDictionary(string word);
	string wordsList(unsigned int i);
	int nWords();

private:
	map <string,vector<string> > words;
	vector<string> possibleWords;
};

#endif
