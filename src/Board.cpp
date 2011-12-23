#include "../include/Board.h"

const int board_size = 5;

Board::Board()
{
    //ctor
}

int Board::size() {
    return board_size;
}

void Board::print_board() {
    for (int i = 0; i < board.size(); i++) {
        cout << board[i].get_value() << " ";
    }
}

