#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "../include/Card.h"
#include <iostream>

using namespace std;

class Board
{

    public:
        Board();

        void print_board();
        int size();

        void add_card(Card c) {
            board.push_back(c);
        }
        Card operator[](int index) {
            return board[index];
        }

        vector<Card> get_board() {
            return board;
        }
        void clear_board() {
            board.resize(0);
        }

    private:
        vector<Card> board;
};

#endif // BOARD_H
