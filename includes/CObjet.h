#pragma once
#include <iostream>
#include <vector>


class Objet{
    private:
        std::vector<std::pair<int,int>> _coord;
    public:
        Objet(){};
        ~Objet(){};
        void maj();
        std::pair<int,int> get_coord(int k);
};

class serpent: public Objet{
    private:
        std::vector<std::pair<int,int>> _queue;

    public:
        serpent();
        ~serpent();
        //void maj();
        void agrandir();
};

class pomme: public Objet{
    private:
    int _x;
    int _y;
    public:
    pomme();
    ~pomme();
    void apparait();
};


