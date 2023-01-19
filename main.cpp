#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>

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
std::map<std::pair<int, int>, int> snake_board;


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
    for (int k = 0; k < n; k++)
    {
        queue.push_back(std::make_pair(0, 0));
    }
    std::chrono::steady_clock::time_point last_move = std::chrono::steady_clock::now();
    int p = 0;
    int t = 0;
    bool b = true;

    std::random_device rd;
    std::mt19937 gen_x(rd());
    std::uniform_int_distribution<> distrib_x(1, 9);

    std::mt19937 gen_y(rd());
    std::uniform_int_distribution<> distrib_y(1, 49);
    int score =0;

    int x_pomme = distrib_x(gen_x), y_pomme = distrib_y(gen_y);

    while (b)
    {

        int m = queue.size();


        // Affichage de la scène
        screen_clear();
        board_clear(snake_board);

        board_set_apple(snake_board, x_pomme, y_pomme);

        for (auto pos : queue)
        {
            board_set_snake(snake_board, pos.first, pos.second);
        }

        screen_draw_board(snake_board);

        long ellapsedms = 0;
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        ellapsedms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(end - last_move).count();


        // Gestion des bords (le serpent réapparaît à l'opposé)
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
        }
        else if (key_scan == DOWN_ARROW)
        {
            direction = 1;
        }
        else if (key_scan == LEFT_ARROW)
        {
            direction = 2;
        }
        else if (key_scan == RIGHT_ARROW)
        {
            direction = 3;
        }

        //mise à jour de position
        if (ellapsedms > 200)
        {
            queue[0] = std::make_pair(x, y);
            queue[0] = std::make_pair(x, y);
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
            queue[0] = std::make_pair(x, y);
            p += 1;
            t += 1;
            
        }

        //grandissement de la queue
        
        if (x_pomme==x && y_pomme==y)
        {
            score++;
            int z = queue[m - 1].first;
            int t = queue[m - 1].second;
            queue.push_back(std::make_pair(z, t));
            p = 0;
            x_pomme = distrib_x(gen_x);
            y_pomme = distrib_y(gen_y);

            while (std::count(queue.begin(), queue.end(), std::make_pair(x_pomme, y_pomme)) != 0)
            {
                x_pomme = distrib_x(gen_x);
                y_pomme = distrib_y(gen_y);
            }
        }

        m=queue.size();
        //game over
        if(t>2){
            for(int k = 1;k<m;k++){
                if(x==queue[k].first && y == queue[k].second){
                    b=false;
                }
            }
        }
    }

    keyboard_end();
    std::cout<<"\n";
    std::cout<<"GAME OVER"<<std::endl;
    std::cout<<"Score: "<<score<<std::endl;
    }

