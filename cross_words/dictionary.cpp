//
// ...
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "dictionary.h"
#include <map>

using namespace std;


//
// ...
bool isValid(string word)
{

	int position = 0;

	for (unsigned int i = 0; i < word.length(); i++)
	{
		char c = word[i];
		if ((c<'A' || c>'Z') && c != ' ' && c != '-')
			return false;
		else
			position++;
	}

	if (position == word.length())
		return true;
	return false;
}

//
// ...
void uppercasel(string &word)
{
	for (unsigned int i = 0; i < word.length(); ++i)
		word[i] = toupper(word[i]);
}


//
// ...
Dictionary::Dictionary(ifstream &f)
{
	string line;
	vector<string> emptyVec;

	while (getline(f, line))
	{
		uppercasel(line);
		vector<string> synonyms;
		string word = line.substr(0, line.find_first_of(':'));
		string synonym = line.substr(line.find_first_of(':') + 2, line.length());

		while (synonym.find(',') <= synonym.length())
		{

			if (isValid(synonym.substr(0, synonym.find_first_of(','))))
			{
				synonyms.push_back(synonym.substr(0, synonym.find_first_of(',')));
			}
			if (synonym.length() <= synonym.find(',') + 1)
				break;
			synonym = synonym.substr(synonym.find(',') + 2, synonym.length());
		}
		if (synonym.length() != 0)
		{
			if (isValid(synonym))
			{
				synonyms.push_back(synonym);
			}

		}
		words.insert(pair<string, vector<string> >(word, synonyms));
		possibleWords.push_back(word);
	}
}


//
// ...
int Dictionary::nWords()
{
	return possibleWords.size();
}

//
// ...
string Dictionary::wordsList(unsigned int i)
{
	return possibleWords[i];
}

//
// ...
bool Dictionary::isInDictionary(string word)
{
	vector<string> newVector;
	if (words[word] == newVector)
	{
		return false;
	}
	else
		return true;

}
