#ifndef CARD_H
#define CARD_H

enum Suite {HEARTS, DIAMONDS, CLUBS, SPADES};

class Card
{
    public:
        Card() {};
        Card(int v, int s) : value(v), suite(s) {}

        int get_value() const { return value; }
        int get_suite() const { return suite; }
        bool operator< (const Card &rhs) const {
            return (value < rhs.get_value());
        }
        bool operator==(const Card& c) const {
            return (c.get_value() == value && c.get_suite() == suite);
        }

    private:
        int value;
        int suite;
};

#endif // CARD_H
