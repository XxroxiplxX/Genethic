//
// Created by piotrkali on 9/7/22.
//

#ifndef GENETHIC_INDIVIDUAL_H
#define GENETHIC_INDIVIDUAL_H


class Individual {
    int *genotype;
    double adaptation;
public:
    int size;
    Individual(int size, int *genotype);
    double get_adaptation() const;
    int get_gen(int i);
    int *get_genotype();
    void change_adatpation(double adaptation);
    bool operator <(const Individual &individual);
    bool operator == (const Individual &individual) const;
    void mutation_insert(int p, int q);
    void mutation_swap(int p, int q);
    void mutation_invert(int p, int q);
    void print_individual();
};


#endif //GENETHIC_INDIVIDUAL_H
