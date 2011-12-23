#include "../include/win_state.h"

win_state::win_state(vector<Card> &cards)
{
    int cards_size = cards.size();
    vector<Card> holder;

    //Sort cards in ascending order
    sort(cards.begin(), cards.end());

    // High card
    high_card = cards[cards_size-1].get_value();
    win_level = 0;

    // Pair
    for (int i = 0; i < cards_size - 1; i++) {
        if (cards[i].get_value() == cards[i+1].get_value()) {
            high_card = cards[i].get_value();
            win_level = 1;
        }
    }

    // Two pair
    for (int i = 0; i < cards_size - 3; i++) {
        if (cards[i].get_value() == cards[i+1].get_value() && cards[i+2].get_value() == cards[i+3].get_value()) {
            high_card = cards[i+2].get_value();
            win_level = 2;
        }
    }
    // Trips
    for (int i = 0; i < cards_size - 2; i++) {
        if (cards[i].get_value() == cards[i+1].get_value() && cards[i].get_value() == cards[i+2].get_value()) {
            high_card = cards[i].get_value();
            win_level = 3;
        }
    }

    // Straight
    bool ace_flag = false;
    if (cards[cards_size-1].get_value() == 12) {
        ace_flag = true;
        cards.insert(cards.begin(), Card(0,cards[cards_size-1].get_suite()));
    }
    for (int i = 0; i < cards_size - 4; i++) {
        if (cards[i].get_value() == cards[i+1].get_value() - 1) {
            if (cards[i+1].get_value() == cards[i+2].get_value() - 1) {
                if (cards[i+2].get_value() == cards[i+3].get_value() - 1) {
                    if (cards[i+3].get_value() == cards[i+4].get_value() - 1) {
                        high_card = cards[i+4].get_value();
                        win_level = 4;
                    }
                }
            }
        }
    }
    if (ace_flag) {
        cards.erase(cards.begin());
    }
    // Flush
    int counter = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < cards_size; j++) {
            if (cards[j].get_suite() == i) {
                counter++;
                if (counter >= 5) {
                    high_card = cards[j].get_value();
                    win_level = 5;
                }
            }
            else {
                counter = 1;
            }
        }
    }

    // Full house

    vector<Card> temp;
    for (int i = 0; i < cards_size; i++) {
        temp.push_back(cards[i]);
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
        holder.resize(0);
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
        win_level = 6;
        high_card = temp_hc;
    }

    // Quads
    for (int i = 0; i < cards_size - 4; i++) {
        if (cards[i].get_value() == cards[i+1].get_value() && cards[i].get_value() == cards[i+2].get_value() && cards[i].get_value() == cards[i+3].get_value()) {
            high_card = cards[i].get_value();
            win_level = 7;
        }
    }

    // Add these in later... so rare that statistically won't matter if non existant
    // Straight flush
    // Royal flush
}
