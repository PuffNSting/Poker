#include "..\include\Board.h"

Board::Board()
{
    //ctor
}

void Board::add_card(Card c) {
    board.push_back(c);
}

Card Board::operator[](int index) {
    return board[index];
}
int Board::size() {
    return 5;
}
vector<Card> Board::get_board() {
    return board;
}
void Board::clear_board() {
    board.resize(0);
}
void Board::print_board() {
    for (int i = 0; i < board.size(); i++) {
        cout << board[i].get_value() << " ";
    }
}
