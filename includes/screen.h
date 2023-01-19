#pragma once
#include <map>

void screen_clear();
void screen_draw_board(const std::map<std::pair<int,int>,bool> &board);

