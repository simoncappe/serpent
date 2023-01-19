#include <iostream>
#include "screen.h"
#define clear() printf("\033[H\033[J")

void screen_clear()
{
    // Clear terminal
    std::cout << "\x1b[H\x1b[J";
    // Hide cursor
    std::cout << "\e[?25l";
}

void screen_draw_board(const std::map<std::pair<int,int>, int> &board)
{
    for (std::pair<const std::pair<int, int>, int> element : board)
    {
        std::pair<int, int> coords = element.first;
        int value = element.second;
        int x = coords.first;
        int y = coords.second;

        // Positionnement en row/column.
        // (1,1) en haut a gauche
        // x = row, y = column
        std::cout << "\x1b["<<x << ";"<< y <<";H";
        
        switch (value)
        {
            case 1:
                std::cout << "*";
                break;
            case 2:
                std::cout << "A";
                break;
        }
    }

    std::cout << std::flush;
}