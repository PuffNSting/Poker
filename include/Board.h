#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "..\include\Card.h"
#include <iostream>

using namespace std;

class Board
{
    public:
        Board();

        void add_card(Card);
        Card operator[](int);
        int size();
        vector<Card> get_board();
        void clear_board();
        void print_board();

    protected:
    private:
        vector<Card> board;
};

#endif // BOARD_H
