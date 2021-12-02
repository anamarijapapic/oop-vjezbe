/*
    [OP] - VJEZBA 6
    @file HangmanView.cpp
    @author Anamarija Papic
*/

#include "Hangman.hpp"
using namespace std;

void HangmanView::displayWelcomeMessage() const
{
    cout << "WELCOME TO THE HANGMAN GAME!" << endl;
    cout << "You have to guess a movie title." << endl << endl;
    system("pause");
    system("cls");
}

void HangmanView::displayHangmanDrawing(HangmanModel& model) const
{
    int lives = model.getLives();

    string head = lives > 6 ? " " : "0";
    string upper_torso = lives > 5 ? " " : "|";
    string left_hand = lives > 4 ? " " : "/";
    string right_hand = lives > 3 ? " " : "\\";
    string bottom_torso = lives > 2 ? " " : "|";
    string left_leg = lives > 1 ? " " : "/";
    string right_leg = lives > 0 ? " " : "\\";

    cout << "    ________" << endl;
    cout << "    | /  |" << endl;
    cout << "    |/   " + head << endl;
    cout << "    |   " + left_hand + upper_torso + right_hand << endl;
    cout << "    |    " + bottom_torso << endl;
    cout << "    |   " + left_leg + " " + right_leg << endl;
    cout << "    |" << endl;
    cout << "    |" << endl;
    cout << " ___|___" << endl << endl;
}

void HangmanView::displayGuessingProgress(HangmanModel& model) const
{
    cout << "Movie title: " << model.getMovieToGuess() << endl << endl;
    cout << "Used letters/digits: ";
    cout << model.getUsedCharacters() << endl;
    cout << "Available letters/digits: ";
    cout << model.getAvailableCharacters() << endl;
}

void HangmanView::displayOutcomeMessage(HangmanModel& model) const
{
    int lives = model.getLives();
    if (lives) {
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "  CONGRATULATIONS! YOU WON!  " << endl;
        cout << "-----------------------------" << endl;
    }
    else {
        cout << endl;
        cout << "------------------------------------" << endl;
        cout << "  YOU LOST! BETTER LUCK NEXT TIME!  " << endl;
        cout << "------------------------------------" << endl;
        cout << "Correct movie title: " + model.getMovie() << endl;
    }
}