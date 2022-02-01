/*
    [OP] - VJEZBA 9 - ZADATAK 1
    @file Player.cpp
    @author Anamarija Papic
*/

#include "Player.hpp"

void Player::set_name(const string playerName)
{
    name = playerName;
}

string Player::get_name() const
{
    return name;
}

void Player::set_hand(vector<int> playerHand)
{
    hand = playerHand;
}

void Player::set_hand_sum(const int sum)
{
    handSum = sum;
}

int Player::get_hand_sum() const
{
    return handSum;
}

void Player::set_guess(const int playerGuess)
{
    guess = playerGuess;
}

int Player::get_guess() const
{
    return guess;
}

void Player::increase_score()
{
    score++;
}

int Player::get_score() const
{
    return score;
}