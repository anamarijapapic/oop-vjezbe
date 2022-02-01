/*
    [OP] - VJEZBA 9 - ZADATAK 1
    @file Game.cpp
    @author Anamarija Papic
*/

#include "Game.hpp"

void Game::print_welcome_message() const
{
    cout << "Welcome to the game of" << endl;
    cout << "  ____   ____  ____   ____  ____     ___  __\\/_   ____ " << endl;
    cout << " |    | /    ||    \\ /    ||    \\   /  _]|     | /    |" << endl;
    cout << " |__  ||  o  ||  o  )  o  ||  _  | /  [_ |__/  ||  o  |" << endl;
    cout << " __|  ||     ||   _/|     ||  |  ||    _]|   __||     |" << endl;
    cout << "/  |  ||  _  ||  |  |  _  ||  |  ||   [_ |  /  ||  _  |" << endl;
    cout << "\\  `  ||  |  ||  |  |  |  ||  |  ||     ||     ||  |  |" << endl;
    cout << " \\____j|__|__||__|  |__|__||__|__||_____||_____||__|__|" << endl << endl;
}

void Game::add_player(Player* player)
{
    players.push_back(player);
}

void Game::initialize_players()
{
    cout << "Game mode:" << endl << "1. Just human players" << endl << "2. Both human and computer players" << endl;
    do {
        cout << "Enter your choice: ";
        cin >> gameMode;
        if (gameMode < MODE_HUMANS || gameMode > MODE_HUMANS_COMPUTERS)
            cout << "Wrong entry! Please retry." << endl;
    } while (gameMode < MODE_HUMANS || gameMode > MODE_HUMANS_COMPUTERS);

    int minNumberOfPlayers = (gameMode == MODE_HUMANS) ? MIN_HUMANS : MIN_HUMANS_COMPUTERS;

    cout << endl << "Players:" << endl;
    initialize_humans(minNumberOfPlayers);
    if (gameMode == MODE_HUMANS_COMPUTERS)
        initialize_computers(minNumberOfPlayers);
}

void Game::initialize_humans(const int minNumberOfHumans)
{
    int numberOfHumans;

    do {
        cout << "Enter number of human players (at least " << minNumberOfHumans << "): ";
        cin >> numberOfHumans;
        if (numberOfHumans < minNumberOfHumans)
            cout << "Wrong entry! Please retry." << endl;
    } while (numberOfHumans < minNumberOfHumans);

    for (int i = 1; i <= numberOfHumans; i++) {
        string name;
        
        cout << "Enter player " << i << " name: ";
        cin >> name;

        HumanPlayer* human = new HumanPlayer(name);
        add_player(human);
    }
}

void Game::initialize_computers(const int minNumberOfComputers)
{
    int numberOfComputers;

    do {
        cout << "Enter number of computer players (at least " << minNumberOfComputers << "): ";
        cin >> numberOfComputers;
        if (numberOfComputers < minNumberOfComputers)
            cout << "Wrong entry! Please retry." << endl;
    } while (numberOfComputers < minNumberOfComputers);

    for (int i = 1; i <= numberOfComputers; i++) {
        ComputerPlayer* computer = new ComputerPlayer("Computer" + to_string(i));
        add_player(computer);
    }
}

void Game::set_goal()
{
    int goal;
    cout << endl << "Score goal:" << endl;
    do {
        cout << "Enter a score goal for the game: ";
        cin >> goal;
        if (goal <= 0)
            cout << "Wrong entry! Please retry." << endl;
    } while (goal <= 0);
    scoreGoal = goal;
}

void Game::play_game()
{
    int allHandsSum;
    vector<Player*> playersWhoGuessed;

    while (!game_finished()) {
        cout << endl << "Round " << round << ":" << endl;

        allHandsSum = 0;

        for (auto player : players) {
            cout << player->get_name() << "'s turn: " << endl;
            player->choose_coins();
            allHandsSum += player->get_hand_sum();
            player->guess_total_sum(players.size());
            cout << endl;
        }

        cout << "The total sum of coins in this round is " << allHandsSum << "." << endl;

        for (auto player : players) {
            if (allHandsSum == player->get_guess()) {
                playersWhoGuessed.push_back(player);
                player->increase_score();
            }
        }

        cout << playersWhoGuessed.size() << " player(s) guessed!";

        if (playersWhoGuessed.size() > 0) {
            cout << " -> ";
            for (auto player : playersWhoGuessed)
                cout << player->get_name() << " ";
        }
        
        cout << endl;
        playersWhoGuessed.clear();
        round++;
    }
}

bool Game::goal_reached(Player* player) const
{
    if (player->get_score() == scoreGoal)
        return true;
    return false;
}

bool Game::game_finished() const
{
    vector<Player*> playersWhoWon;
    vector<Player*> playersWhoLost;

    for (auto player : players) {
        if (goal_reached(player))
            playersWhoWon.push_back(player);
        else
            playersWhoLost.push_back(player);
    }

    if (playersWhoWon.size() > 0) {
        cout << endl << "Game is finished, the goal is reached!" << endl << endl;
        cout << "Player(s) who won: " << endl;
        for (auto player : playersWhoWon) {
            cout << player->get_name() << endl;
        }
        cout << "Congratulations!" << endl << endl;

        cout << "Player(s) who lost: " << endl;
        for (auto player : playersWhoLost) {
            cout << player->get_name() << endl;
        }
        cout << "Game over! Better luck next time!" << endl;

        return true;
    }

    return false;
}

void Game::run_game()
{
    print_welcome_message();
    initialize_players();
    set_goal();
    play_game();
}