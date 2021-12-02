/*
	[OP] - VJEZBA 6
	@file HangmanModel.cpp
	@author Anamarija Papic
*/

#include "Hangman.hpp"
using namespace std;

HangmanModel::HangmanModel() 
{
	vector<string> movies;
	ifstream myfile("movie.txt");
	while (getline(myfile, movie))
	{
		movies.push_back(movie);
	}
	for (size_t i = 0; i < movies.size(); i++) {
		for (auto& c : movies[i]) {
			c = toupper(c);
		}
	}
	
	setMovie(movies[rand() % movies.size()]);

	for (size_t i = 0; i < movie.size(); i++) {
		if (isspace(movie[i])) {
			movieToGuess.push_back(' ');
		}
		else if (ispunct(movie[i])) {
			movieToGuess.push_back(movie[i]);
		}
		else {
			movieToGuess.push_back('-');
		}
	}

	for (char alphabet = 'A'; alphabet <= 'Z'; alphabet++)
	{
		availableCharacters.push_back(alphabet);
		availableCharacters.push_back(' ');
	}
	for (char numbers = '0'; numbers <= '9'; numbers++)
	{
		availableCharacters.push_back(numbers);
		availableCharacters.push_back(' ');
	}
}

int HangmanModel::getLives()
{
	return lives;
}

string HangmanModel::getMovie() const
{
	return movie;
}

string HangmanModel::getMovieToGuess() const 
{
	return movieToGuess;
}

string HangmanModel::getUsedCharacters() const
{
	return usedCharacters;
}

string HangmanModel::getAvailableCharacters() const 
{
	return availableCharacters;
}

void HangmanModel::setLives()
{
	lives--;
}

void HangmanModel::setMovie(const string& movie)
{
	this->movie = movie;
}

void HangmanModel::setMovieToGuess(const string& movieToGuess)
{
	this->movieToGuess = movieToGuess;
}

void HangmanModel::setUsedCharacters(char character)
{
	if (usedCharacters.find(character) == string::npos) {
		usedCharacters.push_back(character);
		usedCharacters.push_back(' ');
	}
}

void HangmanModel::setAvailableCharacters(const string& availableCharacters) 
{
	this->availableCharacters = availableCharacters;
}