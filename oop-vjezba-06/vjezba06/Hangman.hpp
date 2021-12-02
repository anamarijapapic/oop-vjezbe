/*
    [OP] - VJEZBA 6
    @file Hangman.hpp
    @author Anamarija Papic
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

class HangmanModel {
	int lives = 7;
	string movie;
	string movieToGuess;
	string usedCharacters;
	string availableCharacters;
public:
	HangmanModel();
	~HangmanModel() {};
	int getLives();
	string getMovie() const;
	string getMovieToGuess() const;
	string getUsedCharacters() const;
	string getAvailableCharacters() const;
	void setLives();
	void setMovie(const string& movie );
	void setMovieToGuess(const string& guessMovie);
	void setUsedCharacters(char character);
	void setAvailableCharacters(const string& availableCharacters);
};

class HangmanView {
public:
	HangmanView() {};
	~HangmanView() {};
	void displayWelcomeMessage() const;
	void displayHangmanDrawing(HangmanModel& model) const;
	void displayGuessingProgress(HangmanModel& model) const;
	void displayOutcomeMessage(HangmanModel& model) const;
};

class HangmanController {
public:
	HangmanController() {};
	~HangmanController() {};
	void userEntry(HangmanModel& model);
	bool isCharacterUsed(HangmanModel& model, char character);
	void checkCharacter(HangmanModel& model, char character);
	void updateLives(HangmanModel& model, bool mistake);
	bool isGameFinished(HangmanModel& model);
};