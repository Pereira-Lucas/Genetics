#include <iostream>
#include "Chromosomes/world.h"

int main() {
    World world;
    world.generatePops(20);
    world.showAll();
    int gen = 1;
    while(!world.isFinish()) {

        std::cout << "--------" << std::endl;
        std::cout << "Generation " << gen++ << std::endl;
        world.sortChromosome();
        world.showAll();
        std::cout << "--------" << std::endl;
        world.showBest();
        world.killAndRebirth();
    }

    std::cout << "Fin de la simulation atteint en " << gen << " générations" << std::endl;
    return 0;
}