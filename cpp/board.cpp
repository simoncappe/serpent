#include "board.h"


void board_clear(std::map<std::pair<int,int>, int> &board)
{
    board.clear();
}

void board_set_snake(std::map<std::pair<int,int>, int> &board, int x, int y)
{
    board[{x,y}] = 1;
}

void board_set_apple(std::map<std::pair<int,int>, int> &board, int x, int y)
{
    board[{x,y}] = 2;
}
