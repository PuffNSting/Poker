#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>
#include "..\include\Card.h"
#include "..\include\Board.h"
#include "..\include\win_state.h"
#include <string>

using namespace std;

class Player
{
    public:
        Player() {};
        void add_card(Card);
        void new_hand();
        void print_hand();
        vector<Card> get_hand();
        int calc_win_level(Board);
        int get_win_level();
        int get_high_card();
        string win_level_to_string(int);

    protected:
    private:
        vector<Card> hand;
        int win_level, high_card;
};

#endif // PLAYER_H
