//
// Created by piotrkali on 9/7/22.
//

#include "Population.h"
#include "iostream"
#include "thread"
using namespace std;
Population::Population(Individual pioneer, int **distances, int size_of_population, double roulette_crit) : size_of_population(size_of_population), roulette_crit(roulette_crit), distances(distances) {
    srand(time(nullptr));
    generator = std::mt19937(random());
    population = std::vector<Individual>();
    parents = std::vector<Individual>();
    init(pioneer);
}

int *Population::permutation(int *arg, int size) {
    std::uniform_int_distribution<int> distribution(0, size - 1);
    int *pi = new int[size];
    for (int i = 0; i < size; i++) {
        pi[i] = arg[i];

    }

    for (int i = 0; i < size; i++) {
        int tmp1 = pi[i];
        int r = distribution(generator);
        pi[i] = pi[r];
        pi[r] = tmp1;

    }

    return pi;
}

vector<Individual> Population::order_crossover(Individual parent1, Individual parent2) {
    vector<Individual> children;
    int *ospring1 = new int[parent1.size];
    int *ospring2 = new int[parent2.size];

    uniform_int_distribution<int> distribution(0, parent2.size/2);

    int beg = distribution(generator);
    int end = beg + distribution(generator);

    auto copy_of_genes = [](int *ospring, Individual parent, int beg, int end){
        //cout << "kopiuje" << endl;
        for (int i = beg; i <= end; i++) {
            ospring[i] = parent.get_gen(i);
            cout << i << endl;
        }
    };

    auto rest_of_the_genes = [](int *ospring, Individual parent, int beg, int end) {
        int c,i = end + 1;

        while (i < parent.size) {
            if (does_not_contain_a_gene(ospring, parent.get_gen(c), beg, end)) {
                ospring[i] = parent.get_gen(c);
                c = (c + 1)%parent.size;
                i++;
            } else {
                c = (c + 1)%parent.size;
            }
        }
        i = 0;
        while (i < beg) {
            if (does_not_contain_a_gene(ospring, parent.get_gen(c), beg, end)) {
                ospring[i] = parent.get_gen(c);
                ospring[i] = parent.get_gen(c);
                c = (c + 1)%parent.size;
                i++;
            } else {    //potomek zawiera juz gen c wiec wyrzucam go z puli
                c = (c + 1)%parent.size;
            }
        }
    };
    cout <<"bb" << endl;
    thread thread_object1(copy_of_genes, ospring1, parent1, beg, end);
    thread thread_object2(copy_of_genes, ospring2, parent2, beg, end);
    thread_object1.join();
    thread_object2.join();
    //thread rest_of_work1(rest_of_the_genes, ospring1, parent2, beg, end);
    //thread rest_of_work2(rest_of_the_genes, ospring2, parent1, beg, end);
    //rest_of_work1.join();
    //rest_of_work2.join();
    //Individual o1 = Individual(parent1.size, ospring1);
    //Individual o2 = Individual(parent2.size, ospring2);
    //children.push_back(o1);
    //children.push_back(o2);

    return children;
}

bool Population::does_not_contain_a_gene(const int *tabu, int x, int p, int q) {
    for (int i = p; i <= q; i++) {
        if (tabu[i] == x) {
            return false;
        }
    }
    return true;
}

int Population::objective_function(Individual individual) {
    return 0;
}

Individual Population::find_alpha() {
    return Individual(0, nullptr);
}

void Population::init(Individual pioneer) {
    for (int i = 0; i < size_of_population; i++) {
        Individual individual = Individual(pioneer.size, permutation(pioneer.get_genotype(), pioneer.size));
        population.push_back(individual);
    }
}

void Population::mutate_population(double probability) {

}

void Population::do_crossing() {

}

void Population::print_population(int type) {
    if (type == 1) {

    } else if (type == 0) {
        for (auto item : population) {
            item.print_individual();
        }
    }
}

void Population::selection_by_roulette() {
    uniform_real_distribution<double> distribution(0,1);
    int i = 0;
    while (i < size_of_population) {
        for (auto individual : population) {
            if (i == size_of_population) {
                return;
            }
            if (distribution(generator) + roulette_crit < individual.get_adaptation()) {
                parents.push_back(individual);
                i++;
            }
        }
    }
}

void Population::selection_by_tournament() {
    uniform_int_distribution<int> distribution(0,size_of_population - 1);
    int i = 0;
    int group = size_of_population/10;
    int *indexes = new int[group];
    int best;
    int k = 0;
    while (i < size_of_population) {
        for (int j = 0; j < group; j++) {
            indexes[j] = distribution(generator);
        }
        best = objective_function(population[indexes[0]]);

    }
}

void Population::resolve_adaptation() {

}

int Population::get_objective_function() {
    return 0;
}

Individual Population::get_alpha() {
    return Individual(0, nullptr);
}

std::vector<Individual> Population::order_crossover_slow(Individual parent1, Individual parent2) {
    vector<Individual> chiildren;
    int *osrping1 = new int[parent1.size];
    int *osrping2 = new int[parent2.size];

    uniform_int_distribution<int> distribution(0, parent2.size/2);

    int beg = distribution(generator);
    int end = beg + distribution(generator);

    for (int i = beg; i <= end; i++) {
        osrping1[i] = parent1.get_gen(i);
        osrping2[i] = parent2.get_gen(i);
    }

    int c = end + 1;
    int i = end + 1;
    while (i < parent1.size){
        if (does_not_contain_a_gene(osrping1, parent2.get_gen(c), beg, end)) {  //potomek nie zawiera genu o indeksie c, dodaje gen i wyrzucam go z puli
            osrping1[i] = parent2.get_gen(c);

            c = (c + 1)% parent1.size;
            i++;
        } else {    //potomek zawiera juz gen c wiec wyrzucam go z puli
            c = (c + 1)% parent1.size;
        }
    }
    //uzupelniam przod genomu pierwszego potomka
    i = 0;
    while (i < beg) {
        if (does_not_contain_a_gene(osrping1, parent2.get_gen(c), beg, end)) {  //potomek nie zawiera genu o indeksie c, dodaje gen i wyrzucam go z puli
            osrping1[i] = parent2.get_gen(c);
            osrping1[i] = parent2.get_gen(c);
            c = (c + 1)% parent1.size;
            i++;
        } else {    //potomek zawiera juz gen c wiec wyrzucam go z puli
            c = (c + 1)% parent1.size;
        }
    }




    //uzupelniam tyl genomu drugiego potomka
    i = end + 1;
    c = end + 1;
    while (i < parent1.size){
        if (does_not_contain_a_gene(osrping2, parent1.get_gen(c), beg, end)) {  //potomek nie zawiera genu o indeksie c, dodaje gen i wyrzucam go z puli
            osrping2[i] = parent1.get_gen(c);

            c = (c + 1)% parent1.size;
            i++;
        } else {    //potomek zawiera juz gen c wiec wyrzucam go z puli
            c = (c + 1)% parent1.size;
        }
    }



    //uzupelniam prodz genomu drugiego potomka
    i = 0;
    while (i < beg){
        if (does_not_contain_a_gene(osrping2, parent1.get_gen(c), beg, end)) {  //potomek nie zawiera genu o indeksie c, dodaje gen i wyrzucam go z puli
            osrping2[i] = parent1.get_gen(c);
            c = (c + 1)% parent1.size;
            i++;
        } else {    //potomek zawiera juz gen c wiec wyrzucam go z puli
            c = (c + 1)% parent1.size;
        }
    }
    //System.out.println();

    chiildren.push_back(Individual(parent1.size, osrping1));
    chiildren.push_back(Individual(parent1.size, osrping2));
    return chiildren;
}