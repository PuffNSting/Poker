#include "../include/Data.h"

Data::Data()
{
    //ctor
}

void Data::add(Hand input) {
    uncondensed.push_back(input);
}
void Data::flush() {
    ofstream ost("stats.txt", ios::app );

    for (int i = 0; i < uncondensed.size(); i++) {
        ost << uncondensed[i].one.get_value() << " " << uncondensed[i].two.get_value() << " ";
        if (uncondensed[i].suited) {
            ost << "suited\n";
        }
        else {
            ost << "off\n";
        }
    }

    ost.close();
}
void Data::write_to_file() {
    ofstream ost("condensed.txt");

    sort(condensed.begin(), condensed.end());

    for (int i = 0; i < condensed.size(); i++) {
        ost << condensed[i].hand.one.get_value() << " " << condensed[i].hand.two.get_value() << " ";
        if ( condensed[i].hand.one.get_suite() !=  condensed[i].hand.two.get_suite()) {
            ost << "suited";
        }
        else {
            ost << "off";
        }
        ost << " - " << condensed[i].counter << endl;
    }

    ost.close();
}

void Data::condense_data(string filename) {
    ifstream ist(filename.c_str());

    int a, b;
    string s;
    bool suit, found;
    Hand holder;

    while (ist.good()) {
        found = false;
        ist >> a >> b >> s;
        if (s == "suited") {
            suit = true;
        }
        else {
            suit = false;
        }
        holder = Hand(a,b,suit);
        for (int i = 0; i < condensed.size(); i++) {
            if (holder == condensed[i].hand) {
                condensed[i].counter++;
                found = true;
            }
        }
        if (!found) {
            condensed.push_back(out_data(holder, 1));
        }
    }
    write_to_file();

    ist.close();
}
