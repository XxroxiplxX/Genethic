//
// Created by piotrkali on 9/10/22.
//

#ifndef GENETHIC_HABITAT_H
#define GENETHIC_HABITAT_H

#include "Population.h"
#include "Individual.h"
class Habitat {
private:
    Population *population;
    int **matrix;
    Individual *pioneer;
    int best_known;
    double ppb_of_mutation;
    int id;
public:
    Habitat(int **matrix, int *parameters, std::string *cryteriums, std::vector<std::string> results, double *d_parameters);
    void evolve() ;
};


#endif //GENETHIC_HABITAT_H
