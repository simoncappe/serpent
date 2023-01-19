#pragma once
#include <map>


void board_clear(std::map<std::pair<int,int>, int> &board);
void board_set_snake(std::map<std::pair<int,int>, int> &board, int x, int y);
void board_set_apple(std::map<std::pair<int,int>, int> &board, int x, int y);



