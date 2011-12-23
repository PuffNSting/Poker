#include "../include/Board.h"

const int board_size = 5;

Board::Board()
{
    //ctor
}
/*
Card Board::operator[](int index) {
    return board[index];
}*/
int Board::size() {
    return board_size;
}

void Board::print_board() {
    for (int i = 0; i < board.size(); i++) {
        cout << board[i].get_value() << " ";
    }
}

