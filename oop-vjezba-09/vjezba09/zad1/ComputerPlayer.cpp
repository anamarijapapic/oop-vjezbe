/*
    [OP] - VJEZBA 9 - ZADATAK 1
    @file ComputerPlayer.cpp
    @author Anamarija Papic
*/

#include "ComputerPlayer.hpp"

ComputerPlayer::ComputerPlayer(string name)
{
    srand(time(NULL));
    set_name(name);
}

void ComputerPlayer::choose_coins()
{
    vector<int> coins = { FIRST_COIN, SECOND_COIN, THIRD_COIN };
    vector<int> hand = {};
    int numberOfCoins, chosenCoin, coinPosition, handSum = 0;

    numberOfCoins = rand() % (coins.size() + 1);

    for (int i = 0; i < numberOfCoins; i++) {
        coinPosition = rand() % coins.size();
        chosenCoin = coins[coinPosition];

        coins.erase(coins.begin() + coinPosition);
        hand.push_back(chosenCoin);
        handSum += chosenCoin;        
    }

    cout << "Had chosen " << numberOfCoins << " coin(s).";
    if (numberOfCoins != 0) {
        cout << " -> ";
        for (auto coin : hand)
            cout << coin << " ";
        cout << endl;
    }
    
    set_hand(hand);
    set_hand_sum(handSum);
}

void ComputerPlayer::guess_total_sum(const int numberOfPlayers)
{
    int maxAllHandsSum = numberOfPlayers * 8, sumGuess;

    do {
        sumGuess = rand() % (maxAllHandsSum + 1);
    } while (sumGuess < get_hand_sum());
    
    cout << endl << "Guessed " << sumGuess << " as the total sum of coins in this round."  << endl;

    set_guess(sumGuess);
}