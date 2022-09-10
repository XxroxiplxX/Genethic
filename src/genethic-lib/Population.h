//
// Created by piotrkali on 9/7/22.
//

#ifndef GENETHIC_POPULATION_H
#define GENETHIC_POPULATION_H


#include <random>
#include "Individual.h"
#include "vector"
#include "string"
class Population {
private:
    std::mt19937 generator;
    int **distances ;
    //std::vector<Individual> population;
    std::vector<Individual> parents;
    int size_of_population;
    double roulette_crit;
    int *permutation(int *arg, int size);

    static bool does_not_contain_a_gene(const int *tabu, int x, int p, int q);
    int objective_function(Individual individual);
    Individual find_alpha();

public:
    std::vector<Individual> population;
    static bool comparator(const Individual& left, const Individual& right);
    std::vector<Individual> order_crossover_slow(Individual parent1, Individual parent2);
    std::vector<Individual> order_crossover(Individual parent1, Individual parent2);
    Population(Individual pioneer, int **distances, int size_of_population, double roulette_crit);
    void init(Individual pioneer);
    void mutate_population(double probability, std::string type);
    void do_crossing(std::string type);
    void print_population(int type);
    void selection_by_roulette();
    void selection_by_tournament();
    void resolve_adaptation();
    int get_objective_function();
    Individual get_alpha();

};



#endif //GENETHIC_POPULATION_H
