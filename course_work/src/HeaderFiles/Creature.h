#pragma once
#include <cstdlib>
class Creature
{
    public:
        Creature() : x(0), y(0) {}
        ~Creature() {}

        int x;
        int y;
        
        void Move();

    public:
        int step;
};