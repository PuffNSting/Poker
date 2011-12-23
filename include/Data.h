#ifndef DATA_H
#define DATA_H
#include "../include/Card.h"
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct Hand {

    Hand() {};
    Hand(Card a, Card b) {
        if (a.get_value() > b.get_value()) {
            one = b;
            two = a;
        }
        else {
            two = b;
            one = a;
        }
        suited = (one.get_suite() == two.get_suite());
    }
    Hand(int a, int b, bool suit) {
        if (suit) {
            one = Card(a, 0);
            two = Card(b, 0);
        }
        else {
            one = Card(a, 0);
            two = Card(b, 1);
        }
    }
    Card one;
    Card two;
    bool suited;

    ostream& operator<<(ostream& output) {
        output << one.get_value() << " " << two.get_value() << " ";
        if (suited) {
            output << "suited";
        }
        else {
            output << "off";
        }
        return output;
    }
    bool operator==(const Hand& h) const {
        return (one == h.one && two == h.two);
    }
};

struct out_data {
    out_data(Hand h, int num) {
        hand = h;
        counter = num;
    }

    bool operator< (const out_data &rhs) const {
        return (counter > rhs.counter);
    }

    Hand hand;
    int counter;
};

class Data
{
    public:
        Data();

        void add(Hand);
        void write_to_file();
        void condense_data(string);
        void flush();

    private:
        vector<out_data> condensed;
        vector<Hand> uncondensed;

};

#endif // DATA_H
