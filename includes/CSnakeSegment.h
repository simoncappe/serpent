#pragma once

class CSnakeSegment
{
protected:
    /* data */
    int _x = 0;
    int _y = 0;
private:    
    int _colour = 0;

public:
    CSnakeSegment(/* args */);
    ~CSnakeSegment();

public:
    void change_colour();
};



