#ifndef DECK_H
#define DECK_H
#include "..\include\Card.h"
#include <vector>
#include <iostream>
#include <windows.h>

using namespace std;

class Deck
{
    public:
        Deck();
        ~Deck();

        void print_deck();
        Card operator[](int);
        void shuffle();
        int size();

    protected:
    private:
        vector<Card> deck;
};

#endif // DECK_H
