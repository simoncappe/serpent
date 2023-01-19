#include <iostream>
#include <vector>
#include "CObjet.h"


std::pair<int,int> Objet::get_coord(int k){
    std::pair<int,int> c;
    c.first=coord[k].first;
    c.second=coord[k].second
    return c;
}


void serpent::appear(std::map<std::pair<int, int>, int> snake_board){
    for (auto pos : queue)
        {
            board_set_snake(snake_board, pos.first, pos.second);
        }
}
void pomme::appear(std::map<std::pair<int, int>, int> snake_board){
    board_set_pomme(snake_board,_x,_y);
}
