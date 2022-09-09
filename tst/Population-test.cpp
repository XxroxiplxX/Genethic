//
// Created by piotrkali on 9/9/22.
//
#include "gtest/gtest.h"
#include "genethic-lib/Individual.h"
#include "genethic-lib/Population.h"

TEST(Poptest, populationgen) {
    int k = 100;
    int **distances = nullptr;
    int *data = new int[k];
    int *data2 = new int[k];
    for (int i = 0; i < k; i++) {
        data[i] = i;
        data2[i] = k - i;
    }
    Individual second = Individual(k, data2);
    Individual pioneer = Individual(k, data);
    Population population = Population(pioneer, distances, k, 0.8);
}