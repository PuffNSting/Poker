#ifndef DATA_H
#define DATA_H
#include "..\include\Card.h"
#include <map>

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
    }
    Card one;
    Card two;

    bool operator==(const Hand& h) const {
        return (one == h.one && two == h.two);
    }
    bool operator<(const Hand& h) const {
        return (two.get_value() < h.two.get_value());
    }
};

class Data
{
    public:
        Data();

        void add(Hand);

    protected:
    private:
        map<Hand, int> hands;

};

#endif // DATA_H
