#include "../include/Player.h"

void Player::print_hand() {
    cout << hand[0].get_value() << " of " << hand[0].get_suite() << endl;
    cout << hand[1].get_value() << " of " << hand[1].get_suite() << endl;
}
int Player::calc_win_level(Board b) {
    vector<Card> cards;
    cards.push_back(hand[0]);
    cards.push_back(hand[1]);
    for (int i = 0; i < b.size(); i++){
        cards.push_back(b[i]);
    }
    win_state calc(cards);
    win_level = calc.get_win_level();
    high_card = calc.get_high_card();
    return win_level;
}
string Player::win_level_to_string(int wl) {
    if (wl == 0)
        return "high card";
    if (wl == 1)
        return "pair";
    if (wl == 2)
        return "two pair";
    if (wl == 3)
        return "trips";
    if (wl == 4)
        return "straight";
    if (wl == 5)
        return "flush";
    if (wl == 6)
        return "full house";
    if (wl == 7)
        return "quads";
    if (wl == 8)
        return "straight flush";
    if (wl == 9)
        return "royal flush";
}
