/*
	[OP] - VJEZBA 6
	@file HangmanController.cpp
	@author Anamarija Papic
*/

#include "Hangman.hpp"
using namespace std;

void HangmanController::userEntry(HangmanModel& model)
{
	char character;
	do {
		cout << endl << "Enter one non-used letter/digit: ";
		cin >> character;
		character = toupper(character);
		if (!isalpha(character) && !isdigit(character))
			cout << "Invalid input!";
		if (isCharacterUsed(model, character))
			cout << "That letter/digit is already used!";
	} while (((!isalpha(character)) && !isdigit(character)) || (isCharacterUsed(model, character)));
	model.setUsedCharacters(character);
	checkCharacter(model, character);
}

bool HangmanController::isCharacterUsed(HangmanModel& model, char character)
{
	string usedCharacters = model.getUsedCharacters();
	if (usedCharacters.find(character) != string::npos)
			return true;
	return false;
}

void HangmanController::checkCharacter(HangmanModel& model, char character) 
{
	string availableCharacters = model.getAvailableCharacters();
	size_t position = availableCharacters.find(character);
	availableCharacters.erase(availableCharacters.begin() + position, availableCharacters.begin() + position + 2);
	model.setAvailableCharacters(availableCharacters);

	string movie = model.getMovie();
	string movieToGuess = model.getMovieToGuess();
	
	bool mistake = true;
	for (int i = 0; i < movie.size(); i++) {
		if (movie[i] == character) {
			movieToGuess[i] = character;
			mistake = false;
		}
	}

	model.setMovieToGuess(movieToGuess);
	updateLives(model, mistake);
}

void HangmanController::updateLives(HangmanModel& model, bool mistake)
{
	if (mistake)
		model.setLives();
}

bool HangmanController::isGameFinished(HangmanModel& model)
{
	if (model.getMovieToGuess() == model.getMovie() || model.getLives() == 0)
		return true;
	return false;
}