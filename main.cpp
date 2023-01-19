#include <iostream>
#include <thread>
#include <chrono>

#include "snake.h"
#include "screen.h"
#include "board.h"
#include "keyboard.h"
#include "CSnakeSegment3D.h"

#define UP_ARROW 65
#define LEFT_ARROW 68
#define DOWN_ARROW 66
#define RIGHT_ARROW 67

// Variables de contexte du board
std::map<std::pair<int, int>, bool> snake_board;

// Variables de contexte du snake
int snake_size = 5;
std::vector<snake_segment_st> snake_segments;

int main(int, char **)
{
    std::cout << "Snake starting...\n";

    snake_segment_st segment0;
    segment0.x;
    segment0.name;

    CSnakeSegment seg1;
    CSnakeSegment seg2;
    std::cout << "segment construit\n";

    std::cout << "segment détruit\n";

    // seg1._x;

    seg1.change_colour();

    CSnakeSegment3D seg3d01;
    seg3d01.change_colour();

    keyboard_init();

    int x = 0, y = 0;
    int n = 2;
    std::vector<std::pair<int, int>> queue;
    for (int k = 0; k < n; k++){
        queue.push_back(std::make_pair(0, 0));
    }
    std::chrono::steady_clock::time_point last_move = std::chrono::steady_clock::now();
    int p = 0;
    int t = 0;
    bool b = true;
    while (b)
    {

        int m = queue.size();

        





        // Affichage de la scène
        screen_clear();
        board_clear(snake_board);

        for (auto pos : queue)
        {
            board_set_pixel(snake_board, pos.first, pos.second);
        }

        screen_draw_board(snake_board);

        long ellapsedms = 0;
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        ellapsedms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(end - last_move).count();

        if (x >= 9)
        {
            x = 1;
        }
        if (x <= 0)
        {
            x = 8;
        }
        if (y >= 50)
        {
            y = 1;
        }
        if (y <= 0)
        {
            y = 49;
        }
        int direction;
        int key_scan = keyboard_scan();
        if (key_scan == UP_ARROW)
        {
            direction = 0;
            // x--;
        }
        else if (key_scan == DOWN_ARROW)
        {
            direction = 1;
            // x++;
        }
        else if (key_scan == LEFT_ARROW)
        {
            direction = 2;
            // y--;
        }
        else if (key_scan == RIGHT_ARROW)
        {
            direction = 3;
            // y++;
        }

        if (ellapsedms > 300)
        {
            queue[0]=std::make_pair(x,y);
            for (int i = 0; i < m - 1; i++)
            {
                queue[m - 1 - i] = std::make_pair(queue[m - i - 2].first, queue[m - i - 2].second);
            }
            switch (direction)
            {
            case 0:

                x--;
                break;
            case 1:

                x++;
                break;
            case 2:

                y--;
                break;
            case 3:

                y++;
                break;
            }
            // Simulation d'un déplacement automatique/calculé
            // x++;

            // Fin simulation

            last_move = std::chrono::steady_clock::now();
            queue[0]=std::make_pair(x,y);
            p+=1;
            t+=1;
        
        }
        
        if(p>=20){
            int z = queue[m-1].first;
            int t = queue[m-1].second;
            queue.push_back(std::make_pair(z,t));
            p=0;
        }
        
        
        
    }
    

    keyboard_end();

    //std::cout<<"GAME OVER"<<std::endl;
}
