#include "CSnakeSegment.h"
#include <iostream>

CSnakeSegment::CSnakeSegment(/* args */)
{
    _x = 1;
    std::cout << "Le constructeur a été appelé " << _x << std::endl;
}

CSnakeSegment::~CSnakeSegment()
{
    std::cout << "Le destructeur a été appelé" << std::endl;
}

void CSnakeSegment::change_colour()
{
    _colour++;
}
