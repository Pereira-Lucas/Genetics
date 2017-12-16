//
// Created by Lucas on 14/12/2017.
//

#ifndef GENETICS_WORLD_H
#define GENETICS_WORLD_H

#include <vector>
#include <algorithm>
#include "chromosome.h"

class World {
public:
    World();

    void generatePops(int popSize);
    void sortChromosome();
    void killAndRebirth();

    void showAll();
    void showBest();
    void showMedian();
    bool isFinish();
private:
    int popSize;
    std::vector<Chromosome> pops;
    bool sorted;
};


#endif //GENETICS_WORLD_H
