//
// Created by Lucas on 14/12/2017.
//

#ifndef GENETICS_CHROMOSOME_H
#define GENETICS_CHROMOSOME_H

#include <iostream>
#include <vector>
#include "../Utility/random.h"

class Chromosome {
public:
    Chromosome();
    Chromosome(std::vector<int> g, int gen);
    ~Chromosome();

    void showInfos();
    int getFitness() const;
    Chromosome getChild();

    bool operator<(Chromosome const &other);
    bool operator>(Chromosome const &other);
private:
    std::vector<int> mutate();

    std::vector<int> g;
    int gen;
    int fitness;
};

bool operator<(const Chromosome &left, const Chromosome &right);
bool operator>(const Chromosome &left, const Chromosome &right);

#endif //GENETICS_CHROMOSOME_H
