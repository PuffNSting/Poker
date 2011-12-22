#ifndef WIN_STATE_H
#define WIN_STATE_H
#include "..\include\Board.h"
#include "..\include\Player.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class win_state
{
    public:
        win_state(vector<Card>&);

        int get_win_level();
        int get_high_card();

    protected:
    private:
        int win_level, high_card;
};

#endif // WIN_STATE_H
