//==========================================================================================
// Contains functions of the Dictionary class
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "dictionary.h"
#include <map>

using namespace std;


//==========================================================================================
// Checks if the input words is present in the dicitionary and viable for placement
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


//==========================================================================================
// Treatment of the dictionary file
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
		words.insert(pair<string, vector<string> > (word, synonyms));
		possibleWords.push_back(word);
	}
}


//==========================================================================================
// Returns the numbers of words in the dictionary
int Dictionary::nWords()
{
	return possibleWords.size();
}

//==========================================================================================
// Returns a list of all the words in the dictionary in a certain position
string Dictionary::wordsList(unsigned int i)
{
	return possibleWords[i];
}

//==========================================================================================
// Checks if a word is present in the dictionary
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
