/*
    [OP] - VJEZBA 4 - ZADATAK 5
    @file zad5.cpp
    @author Anamarija Papic
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void print_matches(vector<char> matchbox, int n) {
    if (matchbox.size() == 1)
        cout << "There is " << matchbox.size() << " match left." << endl;
    else
        cout << "There are " << matchbox.size() << " matches left." << endl;
    for (size_t i = 0; i < matchbox.size(); i++) {
        cout << matchbox[i] << " ";
    }
}

void remove_matches(vector<char>& matchbox, int n) {
    for (int i = 0; i < n; i++) {
        if (matchbox.size() > 0)
            matchbox.pop_back();
    }
}

int main()
{
    vector<char> matchbox(21, '|');

    cout << "Welcome to the Game of NIM - 21 matches variant." << endl;
    cout << "It's a two-player game, so it's you against the computer." << endl;
    cout << "The computer and user take turns removing 1, 2 or 3 matches at once from the matchbox until the last one is left." << endl;
    cout << "The one who takes the last matchstick loses." << endl;
    cout << "Good luck!" << endl << endl;
    // the player will win for sure by removing the amount of matches that is equal to (4 - lastComputerChoice) in every turn

    int user, computer; // amount of matches to remove - user's choice and computer's choice
    int matchesLeft = matchbox.size();
    bool winner = false;

    srand((unsigned)time(NULL));

    print_matches(matchbox, matchesLeft);

    while (matchesLeft > 1) {
        
        winner = false;

        cout << endl << endl << "Computer's turn:" << endl;

        if (matchesLeft <= 4)
            computer = matchesLeft - 1;
        else
            computer = rand() % 3 + 1;

        if (computer == 1)
            cout << "The computer removed " << computer << " match." << endl;
        else
            cout << "The computer removed " << computer << " matches." << endl;

        remove_matches(matchbox, computer);
        matchesLeft -= computer;
        print_matches(matchbox, matchesLeft);

        if (matchesLeft == 1) break;

        cout << endl << endl << "Your turn:" << endl;
        do {
            cout << "Enter the amount of matches that you want to remove (1, 2 or 3): ";
            cin >> user;
            winner = true;
            if (user < 1 || user > 3)
                cout << "Invalid input! Please enter valid value." << endl;
            else if (user > matchesLeft)
                cout << "Invalid input! There is not enough matches, please enter valid value." << endl;
            else if ((matchesLeft == user) && (user >= 1 && user <= 3)) {
                winner = false;
                break;
            }
        } while ((user < 1 || user > 3) || user > matchesLeft);

        remove_matches(matchbox, user);
        matchesLeft -= user;
        print_matches(matchbox, matchesLeft);
        if (matchesLeft == 0) break;

        matchesLeft = matchbox.size();
    }

    if (winner && (matchesLeft == 1)) {
        cout << endl << endl << "The computer had to take the last match.";
        cout << endl << endl << "Winner = User" << endl << "CONGRATS! YOU WON!" << endl;
    }
    else if (!winner && (matchesLeft == 1)) {
        cout << endl << endl << "You had to take the last match.";
        cout << endl << endl << "Winner = Computer" << endl << "GAME OVER! YOU LOST, BETTER LUCK NEXT TIME." << endl;
    }
    else if (!winner && (matchesLeft < 1)) {
        cout << endl << endl << "You took all the remaining matches including the last one. That wasn't a smart move.";
        cout << endl << endl << "Winner = Computer" << endl << "GAME OVER! YOU LOST, BETTER LUCK NEXT TIME." << endl;
    }

    return 0;
}