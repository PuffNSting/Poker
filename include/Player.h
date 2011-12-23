#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>
#include "../include/Card.h"
#include "../include/Board.h"
#include "../include/win_state.h"
#include <string>

using namespace std;

class Player
{
    public:
        Player() {};

        void print_hand();
        int calc_win_level(Board);
        string win_level_to_string(int);

        void add_card(Card c) {
            hand.push_back(c);
        }
        void new_hand() {
            hand.resize(0);
        }
        vector<Card> get_hand() {
            return hand;
        }
        int get_win_level() {
            return win_level;
        }
        int get_high_card() {
            return high_card;
        }

    private:
        vector<Card> hand;
        int win_level, high_card;
};

#endif // PLAYER_H
