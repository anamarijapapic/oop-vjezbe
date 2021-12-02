/*
    [OP] - VJEZBA 6
    @file main.cpp
    @author Anamarija Papic
*/

#include "Hangman.hpp"
using namespace std;

int main()
{
	srand(time(NULL));
	HangmanModel model;
	HangmanController controller;
	HangmanView view;
	view.displayWelcomeMessage();
	while (!controller.isGameFinished(model)) {
		view.displayHangmanDrawing(model);
		view.displayGuessingProgress(model);
		controller.userEntry(model);
		system("cls");
	}
	view.displayHangmanDrawing(model);
	view.displayGuessingProgress(model);
	view.displayOutcomeMessage(model);
}