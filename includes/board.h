#pragma once
#include <map>


void board_clear(std::map<std::pair<int,int>,bool> &board);
void board_set_pixel(std::map<std::pair<int,int>,bool> &board, int x, int y);



