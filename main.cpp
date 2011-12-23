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


/*  TODO
    Reverse the order of loops in hand checks to make sure the highest is taken
*/

int main() {
    try {
        /*
        // Detection testing
        Player player;
        Board board;

        player.add_card(Card(2,2));
        player.add_card(Card(3,1));

        board.add_card(Card(3,1));
        board.add_card(Card(3,1));
        board.add_card(Card(3,1));
        board.add_card(Card(5,1));
        board.add_card(Card(6,1));

        cout << player.win_level_to_string(player.calc_win_level(board)) << endl;
        cout << player.get_high_card();*/

        // Declarations and what not
        int num_rounds;
        srand(time(NULL));
        string filename = "stats.txt";
        Deck deck;
        Board board;
        Data stats;
        int index;
        int victor;
        int num_players;

        cout << "How many hands to simulate? (500k takes 1 min): ";
        cin >> num_rounds;
        cout << "How many players?: ";
        cin >> num_players;

        // If I had used a vector instead, I could declare it up there ^
        Player players[num_players];

        // Main game loop
        for (int z = 0; z < num_rounds; z++) {
            deck.shuffle();
            board.clear_board();

            // Empties hands
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
            // Flop, turn, river
            int x = board.size()+index;
            for (int i = index; i < x; i++) {
                board.add_card(deck[index]);
                index++;
            }

            // Find winner, take note of winning hand
            victor = find_winning_player(players, num_players, board);
            stats.add(Hand(players[victor].get_hand()[0], players[victor].get_hand()[1]));
            cout << "winning hand: " << players[victor].get_hand()[0].get_value() << " " << players[victor].get_hand()[1].get_value() << endl;

            if (z%1000 == 0) {
                //cout << "Hand " << z << endl;
            }
        }
        stats.flush(); //Outputs all winning hands to file
        stats.condense_data(filename); // Sorts and enumerates winning hands
    }
    catch(...) {
        cout << "Oh dear";
    }
    return 0;
}
