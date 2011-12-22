#include "..\include\Deck.h"

Deck::Deck()
{
    Card holder;
    for (int i = 0; i < 52; i++) { // creates ordered deck
        deck.push_back(Card(i%13,i%4));
    }
    //shuffle();
}

Deck::~Deck()
{

}

void Deck::print_deck() {
    for (int i = 0; i < deck.size(); i++) {
        cout << deck[i].get_value() << " of " << deck[i].get_suite() << endl;
    }
}

Card Deck::operator[](int index) {
    return deck[index];
}

void Deck::shuffle() {
    Card holder;
    int index;
    for (int i = 0; i < 52; i++) {
        for (int x = 0; x < 52; x++) {
            index = rand() % 52;
            holder = deck[x];
            deck[x] = deck[index];
            deck[index] = holder;
        }
    }
}

int Deck::size() {
    return deck.size();
}
