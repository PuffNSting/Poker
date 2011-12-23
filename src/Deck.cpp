#include "../include/Deck.h"

Deck::Deck()
{
    Card holder;
    for (int i = 0; i < 52; i++) {
        deck.push_back(Card(i%13,i%4));
    }
}

void Deck::print_deck() {
    for (int i = 0; i < deck.size(); i++) {
        cout << deck[i].get_value() << " of " << deck[i].get_suite() << endl;
    }
}

void Deck::shuffle() {
    // Using Fisher-Yates shuffle
    int j; // Will hold random value
    Card holder;
    for (int i = deck.size(); i > 1; i--) {
        j = rand() % i;
        holder = deck[i];
        deck[i] = deck[j];
        deck[j] = holder;
    }
}
