//
//  G2048.h
//  CPP
//
//  Created by mac on 5/21/16.
//  Copyright (c) 2016 Fyang. All rights reserved.
//

#ifndef CPP_G2048_h
#define CPP_G2048_h

#include <iostream>
#include <set>
#include <utility>
#include <ctime>
#include <cstdlib>

using namespace std;

class G2048{
public:
    G2048();
    void display();
    bool move_up();
    bool move_down();
    bool move_left();
    bool move_right();
    void get_newone();
private:
    bool is_gameover();
    size_t up_swap(size_t, size_t);
    size_t down_swap(size_t, size_t);
    size_t left_swap(size_t, size_t);
    size_t right_swap(size_t, size_t);
    bool up_add();
    bool down_add();
    bool left_add();
    bool right_add();
private:
    int game[4][4];
};

#endif
