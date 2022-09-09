//
// Created by piotrkali on 9/7/22.
//

#include "Individual.h"
#include <cassert>
#include <algorithm>
#include <iostream>
Individual::Individual(int size, int *genotype) {
    this->size = size;
    this->genotype = genotype;
}

double Individual::get_adaptation() const {
    return adaptation;
}

int Individual::get_gen(int i) {
    return genotype[i];
}

int *Individual::get_genotype() {
    return genotype;
}

void Individual::change_adatpation(double adaptation) {
    this->adaptation = adaptation;
}

bool Individual::operator<(const Individual &individual) {
    if (this->adaptation < individual.adaptation) {
        return true;
    } else {
        return false;
    }
}

void Individual::mutation_insert(int p, int q) {
    assert(p < q);
    for (int i = q - 1; i > p; i--) {
        int tmp = genotype[i + 1];
        std::swap(genotype[i], genotype[i + 1]);
    }
}

void Individual::mutation_swap(int p, int q) {
    std::swap(genotype[p], genotype[q]);
}

void Individual::mutation_invert(int p, int q) {
    while (p < q) {
        std::swap(genotype[p], genotype[q]);
        p++;
        q--;
    }
}

void Individual::print_individual() {
    for (int i = 0; i < size; i++) {
        std::cout << genotype[i] << " ";
    }
    std::cout << "\n";
}

