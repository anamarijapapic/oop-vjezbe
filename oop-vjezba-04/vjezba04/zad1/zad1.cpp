/*
	[OP] - VJEZBA 4 - ZADATAK 1
	@file zad1.cpp
	@author Anamarija Papic
*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

bool multiple_spaces(char first, char second)
{
	return (isspace(first)) && (isspace(second));
}

string correct_punctuation(const string& str)
{
	size_t i;
	string newstr = str;

	// converts tabs to a single space
	replace(newstr.begin(), newstr.end(), '\t', ' ');

	// removes multiple spaces - leaves just one single space
	string::iterator new_end = unique(newstr.begin(), newstr.end(), multiple_spaces);
	newstr.erase(new_end, newstr.end());

	for (i = 0; i < newstr.size(); i++) {
		if (ispunct(newstr[i])) {
			// erases spaces before punctuation
			if (newstr[i - 1] == ' ')
				newstr.erase(newstr.begin() + --i);
			// adds one space after punctuation
			if (newstr[i + 1] != ' ')
				newstr.insert(i + 1, " ");
		}
	}

	return newstr;
}

int main()
{
	string str;
	cout << "Enter a sentence:" << endl;
	getline(cin, str);
	string corrected = correct_punctuation(str);
	cout << endl << "Original sentence :" << endl << str << endl;
	cout << "Corrected sentence: " << endl<< corrected << endl;
	return 0;
}