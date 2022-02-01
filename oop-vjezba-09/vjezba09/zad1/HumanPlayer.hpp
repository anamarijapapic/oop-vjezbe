/*
    [OP] - VJEZBA 9 - ZADATAK 1
    @file HumanPlayer.hpp
    @author Anamarija Papic
*/

#pragma once
#include "Player.hpp"

class HumanPlayer : virtual public Player
{
public:
    HumanPlayer(string name);
    void choose_coins();
    void guess_total_sum(const int numberOfPlayers);
};