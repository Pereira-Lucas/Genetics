//
// Created by Lucas on 14/12/2017.
//

#include "chromosome.h"

Chromosome::Chromosome()
    : gen(1) {
    for(int i = 0; i < 8; i++)
        g.emplace_back(random(0, 9));
    //std::cout << "Creation du chromosome" << std::endl;
    fitness = (g.at(0) + g.at(1)) - (g.at(2) + g.at(3)) + (g.at(4) + g.at(5)) - (g.at(6) + g.at(7));
}

Chromosome::Chromosome(std::vector<int> g, int gen)
        : gen(gen) {
    g.reserve(8);
    for(int i = 0; i < 8; i++)
        this->g.emplace_back(g.at(i));
    //std::cout << "Creation du chromosome" << std::endl;
    fitness = (g.at(0) + g.at(1)) - (g.at(2) + g.at(3)) + (g.at(4) + g.at(5)) - (g.at(6) + g.at(7));
}

Chromosome::~Chromosome() {
    //std::cout << "Destruction du chromosome" << std::endl;
}

void Chromosome::showInfos() {
    std::cout << "Chromosome (";
    for(int i = 0; i < 7; i++)
        std::cout << g.at(i) << ", ";
    std::cout << g.at(7) << ")";
    std::cout << " | gen " << gen;
    std::cout << " | fitness: " << getFitness() << std::endl;
}

int Chromosome::getFitness() const {
    return fitness;
}

Chromosome Chromosome::getChild() {
    std::vector<int> newG = mutate();
    return Chromosome(newG, gen+1);
}

std::vector<int> Chromosome::mutate() {
    // Little Mutation (between 1 and 4 mutation)
    int nbMutation = random(1, 4);
    std::vector<int> newG;
    newG.reserve(8);

    for(int i = 0; i < 8; i++)
        newG.emplace_back(g.at(i));

    for(int i = 0; i < nbMutation; i++) {
        int mutationPos = random(0, 7);
        if(newG.at(mutationPos) == 0)
            newG.at(mutationPos) += 1;
        else if(newG.at(mutationPos) == 9)
            newG.at(mutationPos) -= 1;
        else
            newG.at(mutationPos) += randMinPlus();
    }

    // Big Mutation (0.05%)
    if(random(1, 20) == 1)
        newG.at(random(0, 7)) = random(0, 9);

    return newG;
}

bool Chromosome::operator<(const Chromosome &other) {
    return (this->getFitness() < other.getFitness());
}

bool Chromosome::operator>(Chromosome const &other) {
    return (this->getFitness() > other.getFitness());
}

bool operator<(const Chromosome &left, const Chromosome &right) {
    return (left.getFitness() < right.getFitness());
}

bool operator>(const Chromosome &left, const Chromosome &right) {
    return (left.getFitness() > right.getFitness());
}