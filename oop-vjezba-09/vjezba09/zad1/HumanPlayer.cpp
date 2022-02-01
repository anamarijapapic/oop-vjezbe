/*
    [OP] - VJEZBA 9 - ZADATAK 1
    @file HumanPlayer.cpp
    @author Anamarija Papic
*/

#include "HumanPlayer.hpp"

HumanPlayer::HumanPlayer(string name)
{
    set_name(name);
}

void HumanPlayer::choose_coins()
{
    vector<int> coins = { FIRST_COIN, SECOND_COIN, THIRD_COIN };
    vector<int> hand = {};
    int numberOfCoins, chosenCoin, handSum = 0;

    do {
        cout << "How many coins do you want to add to your hands (0 - " << MAX_COIN_COUNT << "): ";
        cin >> numberOfCoins;
        if (numberOfCoins < 0 || numberOfCoins > 3)
            cout << "Wrong input! Please retry." << endl;
    } while (numberOfCoins < 0 || numberOfCoins > 3);

    for (int i = 0; i < numberOfCoins; i++) {
        vector<int>::iterator pos;

        do {
            cout << "Choose a coin to add it to your hands ( ";
            for (auto coin : coins)
                cout << coin << " ";
            cout << "): ";
            cin >> chosenCoin;

            pos = find(coins.begin(), coins.end(), chosenCoin);
            if (pos == coins.end() && find(hand.begin(), hand.end(), chosenCoin) != hand.end())
                cout << "You already added that coin to hands! Please retry." << endl;
            else if (pos == coins.end() && find(hand.begin(), hand.end(), chosenCoin) == hand.end())
                cout << "There is no such coin! Please retry." << endl;
        } while (pos == coins.end());

        coins.erase(pos);
        hand.push_back(chosenCoin);
        handSum += chosenCoin;
    }

    set_hand(hand);
    set_hand_sum(handSum);
}

void HumanPlayer::guess_total_sum(const int numberOfPlayers)
{
    int maxAllHandsSum = numberOfPlayers * 8, sumGuess;

    do {
        cout << "Guess the total sum of coins in this round (0 - " << maxAllHandsSum << "): ";
        cin >> sumGuess;
        if (sumGuess < 0 && sumGuess > maxAllHandsSum)
            cout << "Wrong input! Please retry." << endl;
    } while (sumGuess < 0 && sumGuess > maxAllHandsSum);

    set_guess(sumGuess);
}