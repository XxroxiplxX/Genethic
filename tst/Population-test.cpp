//
// Created by piotrkali on 9/9/22.
//
#include "gtest/gtest.h"
#include "genethic-lib/Individual.h"
#include "genethic-lib/Population.h"
#include "algorithm"
#include "Lower_Diag_Parser.h"

TEST(Poptest, populationgen) {
    int k = 100;
    int **distances = nullptr;
    int *data = new int[k];
    int *data2 = new int[k];
    for (int i = 0; i < k; i++) {
        data[i] = i;
        data2[i] = k - i;
    }
    std::vector<std::string> cryts =  {"tournament", "order", "invert"};

    Individual second = Individual(k, data2);
    Individual *pioneer = new Individual(k, data);
    Population population = Population(pioneer, distances, k, 0.8, 0.4, cryts);
    Individual individual1 = Individual(5, nullptr);
    Individual individual2 = Individual(5, nullptr);
    individual1.change_adatpation(0.8);
    individual2.change_adatpation(0.5);
    EXPECT_TRUE(population.comparator(individual2, individual1));
}
TEST(Poptest, copmarator) {
    Individual individual1 = Individual(5, nullptr);
    Individual *individual2 = new Individual(5, nullptr);
    individual1.change_adatpation(0.8);
    individual2->change_adatpation(0.5);
    int k = 100;
    int **distances = nullptr;
    int *data = new int[k];
    int *data2 = new int[k];
    for (int i = 0; i < k; i++) {
        data[i] = i;
        data2[i] = k - i;
    }
    std::vector<std::string> cryts =  {"tournament", "order", "invert"};
    Population population = Population(individual2, distances, k, 0.8, 0.3, cryts);
    EXPECT_TRUE(population.comparator(individual1, *individual2));
}

TEST(Poptest, sorting) {
    int k = 100;
    int **distances = nullptr;
    int *data = new int[k];
    int *data2 = new int[k];
    for (int i = 0; i < k; i++) {
        data[i] = i;
        data2[i] = k - i;
    }
    int *datai = new int[10];
    for (int i = 0; i < 10; i++) {
        data[i] = i;
    }
    std::vector<std::string> cryts =  {"tournament", "order", "invert"};

    Individual *individual = new Individual(10, data);
    Population population = Population(individual, distances, k, 0.8, 0.4, cryts);

}

TEST(PopTest, get_alpha_test) {
    Lower_Diag_Parser parser = Lower_Diag_Parser("gr17.tsp");
    parser.read_dimension();
    int **p = parser.build_matrix();
    int *data = new int[17];
    for (int i = 0; i < 17; i++) {
        data[i] = i;
    }
    Individual *individual = new Individual(17, data);
    std::vector<std::string> cryts =  {"tournament", "order", "invert"};
    Population *population =new Population(individual, p, 20, 0.8, 0.4, cryts);
    population->resolve_adaptation();
    population->get_alpha()->print_individual();
}