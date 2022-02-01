/*
    [OP] - VJEZBA 9 - ZADATAK 1
    @file Player.hpp
    @author Anamarija Papic
*/

#pragma once
#define MAX_COIN_COUNT 3
#define FIRST_COIN 1
#define SECOND_COIN 2
#define THIRD_COIN 5
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Player
{
    string name;
    vector<int> hand;
    int handSum = 0;
    int guess = 0;
    int score = 0;
public:
    Player() {}
    void set_name(const string playerName);
    string get_name() const;
    virtual void choose_coins() = 0;
    void set_hand(vector<int> playerHand);
    void set_hand_sum(const int sum);
    int get_hand_sum() const;
    virtual void guess_total_sum(const int numberOfPlayers) = 0;
    void set_guess(const int playerGuess);
    int get_guess() const;
    void increase_score();
    int get_score() const;
    ~Player() {}
};