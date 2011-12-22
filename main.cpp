#include "include/Card.h"
#include "include/Deck.h"
#include "include/Player.h"
#include "include/Board.h"
#include <iostream>
#include <windows.h>
#include <time.h>
#include "include/Data.h"

using namespace std;

int find_winning_player(Player p[], int num_players, Board b) {
    int max = 0;
    int index = 0;
    for (int i = 0; i < num_players; i++) {
        p[i].calc_win_level(b);
        if (p[i].get_win_level() > max) {
            max = p[i].get_win_level();
            index = i;
        }
        if (p[i].get_win_level() == max) {
            if (p[i].get_high_card() > p[index].get_high_card()) {
                max = p[i].get_win_level();
                index = i;
            }
        }
    }
    return index;
}
int main() {
    try {
        int num_rounds;
        cout << "How many hands to simulate? (500k takes 1 min): ";
        cin >> num_rounds;
        srand(time(NULL));
        string filename = "stats.txt";
        int num_players = 2;
        //int num_rounds = 100000;
        Player players[num_players];
        Deck deck;
        Board board;
        Data stats;
        int index;
        int victor;

        for (int z = 0; z < num_rounds; z++) {
            deck.shuffle();
            board.clear_board();
            for (int i = 0; i < num_players; i++) {
                players[i].new_hand();
            }


            // Deals cards
            index = 0;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < num_players; j++) {
                    players[j].add_card(deck[index]);
                    index++;
                }
            }
            int x = board.size()+index;
            for (int i = index; i < x; i++) {
                board.add_card(deck[index]);
                index++;
            }

            victor = find_winning_player(players, num_players, board);

            stats.add(Hand(players[victor].get_hand()[0], players[victor].get_hand()[1]), filename);


            if (z%1000 == 0) {
                cout << "Hand " << z << endl;
            }
        }
        stats.flush();
        stats.condense_data(filename);
    }
    catch(...) {
        cout << "Oh dear";
    }
    return 0;
}
