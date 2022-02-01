/*
    [OP] - VJEZBA 9 - ZADATAK 1
    @file ComputerPlayer.hpp
    @author Anamarija Papic
*/

#pragma once
#include <cstdlib>
#include <ctime>
#include "Player.hpp"

class ComputerPlayer : virtual public Player
{
public:
    ComputerPlayer(string name);
    void choose_coins();
    void guess_total_sum(const int numberOfPlayers);
};