//
// Created by Lucas on 14/12/2017.
//

#include "random.h"


int random(int min, int max) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}

int randMinPlus() {
    if(random(1, 2) == 1)
        return 1;
    else
        return -1;
}