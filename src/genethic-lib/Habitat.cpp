//
// Created by piotrkali on 9/10/22.
//

#include "Habitat.h"
#include "Individual.h"
/*
 * patameters = {id, size of population, length of genotype, best known solution}
 * d_parameters = {ppb od mutation, cryterium of roulette}
 * cryteriums = {type of selection, type of crossing, type of mutation}
 */
Habitat::Habitat(int **matrix, int *parameters, std::string *cryteriums, std::vector<std::string> results,
                 double *d_parameters) {
    int *first_geno = new int[parameters[2]];
    for (int i = 0; i < parameters[2]; i++) {
        first_geno[i] = i;
    }
    pioneer = new Individual(parameters[2], first_geno);
    //population = new Population(&pioneer, matrix, parameters[1], d_parameters[1], d_parameters[0]);
}

void Habitat::evolve() {

}
