#ifndef DECK_H
#define DECK_H
#include "../include/Card.h"
#include <vector>
#include <iostream>
#include <windows.h>

using namespace std;

class Deck
{
    public:
        Deck();

        void print_deck();
        void shuffle();

        Card operator[](int index) {
            return deck[index];
        }
        int size() {
            return deck.size();
        }

    private:
        vector<Card> deck;
};

#endif // DECK_H
