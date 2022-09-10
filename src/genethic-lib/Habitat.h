//
// Created by piotrkali on 9/10/22.
//

#ifndef GENETHIC_HABITAT_H
#define GENETHIC_HABITAT_H

#include "Population.h"
#include "Individual.h"
class Habitat {
private:
    Population population;

public:
    Habitat(int **matrix, int *parameters, std::string *cryteriums);
    void evolve() ;
};


#endif //GENETHIC_HABITAT_H
