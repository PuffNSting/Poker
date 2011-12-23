#ifndef WIN_STATE_H
#define WIN_STATE_H
#include "../include/Board.h"
#include "../include/Player.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class win_state
{
    public:
        win_state(vector<Card>&);

        int cards_size;

        bool royal_flush(vector<Card> &cards);
        bool straight_flush(vector<Card> &cards);
        bool quads(vector<Card> &cards);
        bool full_house(vector<Card> &cards);
        bool flush(vector<Card> &cards);
        bool straight(vector<Card> &cards);
        bool trips(vector<Card> &cards);
        bool two_pair(vector<Card> &cards);
        bool pair(vector<Card> &cards);

        int get_win_level() {
            return win_level;
        }
        int get_high_card() {
            return high_card;
        }

    private:
        int win_level, high_card;
};

#endif // WIN_STATE_H
