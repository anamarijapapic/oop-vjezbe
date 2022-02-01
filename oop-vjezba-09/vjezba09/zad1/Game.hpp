/*
    [OP] - VJEZBA 9 - ZADATAK 1
    @file Game.hpp
    @author Anamarija Papic
*/

#pragma once
#define MODE_HUMANS 1
#define MODE_HUMANS_COMPUTERS 2
#define MIN_HUMANS 2
#define MIN_HUMANS_COMPUTERS 1
#include "HumanPlayer.hpp"
#include "ComputerPlayer.hpp"

class Game
{
    int gameMode = MODE_HUMANS;
    vector<Player*> players;
    int scoreGoal = 0;
    int round = 1;
public:
    Game() {}
    void print_welcome_message() const;
    void add_player(Player* player);
    void initialize_players();
    void initialize_humans(const int minNumberOfHumans);
    void initialize_computers(const int minNumberOfComputers);
    void set_goal();
    void play_game();
    bool goal_reached(Player* player) const;
    bool game_finished() const;
    void run_game();
    ~Game() {}
};