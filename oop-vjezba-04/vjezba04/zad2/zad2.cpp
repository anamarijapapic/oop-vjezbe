/*
	[OP] - VJEZBA 4 - ZADATAK 2
	@file zad2.cpp
	@author Anamarija Papic
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

void input_sentences(vector<string>& sentencesVector)
{
	string sentence;
	cout << "Enter sentences (Ctrl + z to end input):" << endl;
	while (getline(cin, sentence)) {
		sentencesVector.push_back(sentence);
	}
}

bool isvowel(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return true;
	return false;
}

string push_consonants_to_the_end(string str) 
{
	int pos = 0;
	while (!isvowel(str[pos]) && pos < str.size()) {
		pos++;
	}
	return str.substr(pos) + str.substr(0, pos) + "ay";
}

string translate_to_pig_latin(const vector<string>& sentencesVector, size_t n)
{
	string generatedSentence = sentencesVector[n];
	// convert to lowercase
	transform(generatedSentence.begin(), generatedSentence.end(), generatedSentence.begin(), [](unsigned char ch) { return tolower(ch); });
	
	string translatedSentence = "";
	
	stringstream words(generatedSentence);
	string word;
	while (words >> word) {
		size_t wordlen = word.size();
		if (isvowel(word[0])) {
			if (ispunct(word[wordlen - 1]))
				translatedSentence.append(word.substr(0, wordlen - 1) + "hay" + word[wordlen - 1] + " ");
			else
				translatedSentence.append(word + "hay ");
		}
		if (!isvowel(word[0])) {
			if (ispunct(word[wordlen - 1]))
				translatedSentence.append(push_consonants_to_the_end(word.substr(0, wordlen - 1)) + word[wordlen - 1] + " ");
			else
				translatedSentence.append(push_consonants_to_the_end(word) + " ");
		}
	}

	return translatedSentence;
}

int main()
{
	vector<string> sentences;
	input_sentences(sentences);
	srand((unsigned)time(NULL));
	size_t randNum = rand() % (sentences.size());
	cout << endl << "Random sentence translated to pig latin:" << endl << translate_to_pig_latin(sentences, randNum) << endl;
}