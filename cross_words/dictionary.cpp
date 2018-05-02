#include "dictionary.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

Dictionary::Dictionary()
{
	synonymslist[""] = { "" };
	validwordslist = { "" };
}

Dictionary::Dictionary(string filename)
{
	loadfile(filename);
}

void uppercase(string &word)
{
	transform(word.begin(), word.end(), word.begin(), toupper);
}


void Dictionary::loadfile(string filename)
{
	ifstream dictionary;
	string words;
	string line;
	string mainwordlist;
	int wordlist = 0;
	int	next = 0;

	dictionary.open(filename);

	// Open the file; exit program if the file couldn't be opened
	if (!dictionary.is_open())
	{
		cerr << "File " << "dictionary" << " not found !\n";
		exit(1);
	}

	while (getline(dictionary, line))
	{
		uppercase(words);

		// Once you find ":", save the words from a list of synonyms
		wordlist = line.find(":");
		mainwordlist = line.substr(0, wordlist);

		synonymslist.insert(pair<string, vector<string>>(mainwordlist, vector<string>()));
		validwordslist.push_back(words);

		next = wordlist + 2; // next word
		wordlist = line.find_first_of(",", next);

		while (wordlist != string::npos)
		{
			words = line.substr(next, wordlist - next);
			uppercase_letters(words);
			// Update the list of synonyms
			synonymslist[mainwordlist].push_back(words);

			next = wordlist + 2; // next word
			wordlist = line.find_first_of(",", next);
		}

		// Check for more synonyms
		if (line[line.length() - 1] != ',')
		{
			words = line.substr(next, line.length() - next);
			uppercase_letters(words);
			// Update the list of synonyms
			synonymslist[mainwordlist].push_back(words);
		}
	}
}

bool Dictionary::validword(string word)
{
	bool isvalid;

  //......

	return isvalid;

}
