#include "../include/win_state.h"


win_state::win_state(vector<Card> &cards)
{
    cards_size = cards.size();

    //Sort cards in ascending order
    sort(cards.rbegin(), cards.rend());
    for (int i = 0; i < cards_size; i++) {
        cout << cards[i].get_value() << " ";
    }

    // Add these in later... so rare that statistically won't matter if non existant

    // Royal flush
    // Straight flush

    if (quads(cards)) {
        win_level = 7;
        cout << "quads\n";
        return;
    }
    if (full_house(cards)) {
        win_level = 6;
        cout << "fh\n";
        return;
    }
    if (flush(cards)) {
        win_level = 5;
        cout << "flush\n";
        return;
    }
    if (straight(cards)) {
        win_level = 4;
        cout << "straight\n";
        return;
    }
    if (trips(cards)) {
        win_level = 3;
        cout << "trips\n";
        return;
    }
    if (two_pair(cards)) {
        win_level = 2;
        cout << "tpair\n";
        return;
    }
    if (pair(cards)) {
        win_level = 1;
        cout << "pair\n";
        return;
    }
    // High card
    win_level = 0;
    high_card = cards[cards_size - 1].get_value();
    cout << "hc\n";


}
bool win_state::pair(vector<Card> &cards) {
    for (int i = 0; i < cards_size - 1; i++) {
        if (cards[i].get_value() == cards[i+1].get_value()) {
            high_card = cards[i].get_value();
            return true;
        }
    }
    return false;
}
bool win_state::two_pair(vector<Card> &cards) {
    vector<Card> temp;
    for (int i = 0; i < cards_size; i++) {
        temp.push_back(Card(cards[i].get_value(), cards[i].get_suite()));
    }
    if (pair(temp)) {
        int index;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i].get_value() == high_card) {
                index = i;
                break;
            }
        }
        temp.erase(temp.begin() + index, temp.begin() + index + 2);
        if (pair(temp)) {
            return true;
        }
    }
    return false;
}
bool win_state::trips(vector<Card> &cards) {
    for (int i = 0; i < cards_size - 2; i++) {
        if (cards[i].get_value() == cards[i+1].get_value() && cards[i].get_value() == cards[i+2].get_value()) {
            high_card = cards[i].get_value();
            return true;
        }
    }
    return false;
}
bool win_state::straight(vector<Card> &cards) {
    bool ace_flag = false;
    if (cards[cards_size-1].get_value() == 12) {
        ace_flag = true;
        cards.insert(cards.begin(), Card(0,cards[cards_size-1].get_suite()));
    }
    for (int i = 0; i < cards.size() - 4; i++) {
        if (cards[i].get_value() == cards[i+1].get_value() - 1) {
            if (cards[i+1].get_value() == cards[i+2].get_value() - 1) {
                if (cards[i+2].get_value() == cards[i+3].get_value() - 1) {
                    if (cards[i+3].get_value() == cards[i+4].get_value() - 1) {
                        high_card = cards[i+4].get_value();
                        return true;
                    }
                }
            }
        }
    }
    if (ace_flag) {
        cards.erase(cards.begin());
    }
    return false;
}
bool win_state::flush(vector<Card> &cards) {
    int counter = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < cards_size; j++) {
            if (cards[j].get_suite() == i) {
                counter++;
                if (counter >= 5) {
                    high_card = cards[j].get_value();
                    return true;
                }
            }
            else {
                counter = 1;
            }
        }
    }
    return false;
}
bool win_state::full_house(vector<Card> &cards) {
    vector<Card> temp;
    vector<Card> holder;
    for (int i = 0; i < cards_size; i++) {
        temp.push_back(Card(cards[i].get_value(), cards[i].get_suite()));
    }

    bool trips = false;
    bool pair = false;
    int index, temp_hc;

    for (int i = 0; i < temp.size() - 2; i++) {
        if (temp[i].get_value() == temp[i+1].get_value() && temp[i].get_value() == temp[i+2].get_value()) {
            trips = true;
            temp_hc = temp[i].get_value();
            index = i;
        }
    }
    if (trips) {
        for (int i = index; i < index+3; i++) {
            holder.push_back(temp[i]);
        }
        temp.erase(temp.begin()+index, temp.begin()+index+3);
        for (int i = 0; i < temp.size() - 1; i++) {
            if (temp[i].get_value() == temp[i+1].get_value()) {
                pair = true;
            }
        }
    }
    if (pair && trips) {
        high_card = temp_hc;
        return true;
    }
    return false;
}
bool win_state::quads(vector<Card> &cards) {
    for (int i = 0; i < cards_size - 4; i++) {
        if (cards[i].get_value() == cards[i+1].get_value() && cards[i].get_value() == cards[i+2].get_value() && cards[i].get_value() == cards[i+3].get_value()) {
            high_card = cards[i].get_value();
            return true;
        }
    }
    return false;
}
