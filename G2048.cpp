//
//  G2048.cpp
//  CPP
//
//  Created by mac on 5/21/16.
//  Copyright (c) 2016 Fyang. All rights reserved.
//

#include "G2048.h"
G2048::G2048(){
    for (size_t i = 0; i < 4; ++i){
        for (size_t j = 0; j < 4; ++j)
            game[i][j] = 0;
    }
    get_newone();
}
void G2048::display(){
    system("cls");
    for (size_t i = 0; i < 4; ++i){
        for (size_t j = 0; j < 4; ++j)
            cout << game[i][j] << '\t';
        cout << "\n\n";
    }
}
bool G2048::is_gameover(){
    for (size_t i = 0; i != 3; ++i)
        for (size_t j = 0; j != 3; ++j)
            if (game[i][j] == 0)
                return false;
    return true;
}
void G2048::get_newone(){
    if (is_gameover())
        return;
    size_t i = rand() % 4;
    size_t j = rand() % 4;
    int n = rand() % 4;
    if (!game[i][j]) game[i][j] = n?2:4;
    else get_newone();
}
size_t G2048::up_swap(size_t x, size_t y){
    if (x > 3)
        return 3;
    if (game[x][y] != 0)
        return x;
    else
        return up_swap(x + 1, y);
}
bool G2048::up_add(){
    for (size_t j = 0; j < 4; ++j) {
        for (size_t i = 0; i < 4; ++i){
            if (game[i][j] != 0 && game[i][j] == game[i + 1][j]) {
                game[i][j] += game[i + 1][j];
                game[i + 1][j] = 0;
                return true;
            }
        }
    }
    return false;
}
bool G2048::move_up(){
    bool moved = false;
    for (size_t j = 0; j < 4; ++j){
        for (size_t i = 0; i < 4; ++i){
            if (!game[i][j]){
                size_t t = up_swap(i, j);
                if (game[t][j]){
                    swap(game[i][j], game[t][j]);
                    moved = true;
                }
            }
        }
    }
    if (up_add()){
        move_up();
        moved = true;
    }
    if (moved) return true;
    else return false;
}

size_t G2048::down_swap(size_t x, size_t y){
    if (x == 0)
        return 0;
    if (game[x][y] != 0)
        return x;
    else
        return down_swap(x - 1, y);
}
bool G2048::down_add(){
    for (size_t j = 0; j < 4; ++j) {
        for (size_t i = 3; i < 4 && i >= 0; --i){
            if (game[i][j] != 0 && game[i][j] == game[i - 1][j]) {
                game[i][j] += game[i - 1][j];
                game[i - 1][j] = 0;
                return true;
            }
        }
    }
    return false;
}
bool G2048::move_down(){
    bool moved = false;
    for (size_t j = 0; j < 4; ++j){
        for (size_t i = 3; i < 4 && i >= 0; --i){
            if (!game[i][j]){
                size_t t = down_swap(i, j);
                if (game[t][j]){
                    swap(game[i][j], game[t][j]);
                    moved = true;
                }
            }
        }
    }
    if (down_add()) {
        move_down();
        moved = true;
    }
    if (moved) return true;
    else return false;
}

size_t G2048::left_swap(size_t x, size_t y){
    if (y > 3)
        return 3;
    if (game[x][y] != 0)
        return y;
    else
        return left_swap(x, y + 1);
}
bool G2048::left_add(){
    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < 4; ++j){
            if (game[i][j] != 0 && game[i][j] == game[i][j + 1]) {
                game[i][j] += game[i][j + 1];
                game[i][j + 1] = 0;
                return true;
            }
        }
    }
    return false;
}
bool G2048::move_left(){
    bool moved = false;
    for (size_t i = 0; i < 4; ++i){
        for (size_t j = 0; j < 4; ++j){
            if (!game[i][j]){
                size_t t = left_swap(i, j);
                if (game[i][t]){
                    swap(game[i][j], game[i][t]);
                    moved = true;
                }
            }
        }
    }
    if (left_add()) {
        move_left();
        moved = true;
    }
    if (moved) return true;
    else return false;
}

size_t G2048::right_swap(size_t x, size_t y){
    if (y == 0)
        return 0;
    if (game[x][y] != 0)
        return y;
    else
        return right_swap(x, y - 1);
}
bool G2048::right_add(){
    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 3; j < 4 && j >= 0; --j){
            if (game[i][j] != 0 && game[i][j] == game[i][j - 1]) {
                game[i][j] += game[i][j - 1];
                game[i][j - 1] = 0;
                return true;
            }
        }
    }
    return false;
}
bool G2048::move_right(){
    bool moved = false;
    for (size_t i = 0; i < 4; ++i){
        for (size_t j = 3; j < 4 && j >= 0; --j){
            if (!game[i][j]){
                size_t t = right_swap(i, j);
                if (game[i][t]){
                    swap(game[i][j], game[i][t]);
                    moved = true;
                }
            }
        }
    }
    if (right_add()) {
        move_right();
        moved = true;
    }
    if (moved) return true;
    else return false;
}

