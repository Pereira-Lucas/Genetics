//
// Created by Lucas on 14/12/2017.
//

#include "world.h"

World::World()
    : popSize(0), sorted(false) {}

void World::generatePops(int popSize) {
    if(popSize % 2 != 0)
        std::cout << "Il ne peut y avoir une population impair, nouvelle population de " << ++popSize << std::endl;

    this->popSize = popSize;
    pops.reserve(popSize);

    for(unsigned int i = 0; i < popSize; i++) {
        pops.emplace_back();
    }
}

void World::sortChromosome() {
    std::sort(pops.rbegin(), pops.rend());
    sorted = true;
}

void World::killAndRebirth() {
    for(int i = popSize / 2; i < popSize; i++)
        pops.at(i) = pops.at(i - popSize / 2).getChild();
    sorted = false;
}

void World::showAll() {
    for(int i = 0; i < popSize; i++)
        pops.at(i).showInfos();
}

void World::showBest() {
    if(sorted) {
        std::cout << "Best ";
        pops.at(0).showInfos();
    }
}

void World::showMedian() {
    if(sorted) {
        std::cout << "Median ";
        pops.at(popSize / 2).showInfos();
    }
}

bool World::isFinish() {
    return pops.at(0).getFitness() == 36;
}