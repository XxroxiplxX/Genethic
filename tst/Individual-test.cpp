//
// Created by piotrkali on 9/9/22.
//
#include "gtest/gtest.h"
#include "genethic-lib/Individual.h"

TEST(IndTest, genome_corectness) {
    //arrange
    //act
    //assert
    int *data = new int[10];
    for (int i = 0; i < 10; i++) {
        data[i] = i;
    }
    Individual individual = Individual(10, data);
    individual.print_individual();
    EXPECT_EQ (individual.get_gen(3),  3);

}
TEST(IndTest, operators) {
    Individual individual1 = Individual(5, nullptr);
    Individual individual2 = Individual(5, nullptr);
    individual1.change_adatpation(0.8);
    individual2.change_adatpation(0.5);
    EXPECT_TRUE(individual2 < individual1);
    EXPECT_FALSE(individual1 == individual2);
}
TEST(IndTest, operators_on_pointers) {
    Individual individual1 = Individual(5, nullptr);
    Individual *individual2 = new Individual(5, nullptr);
    individual1.change_adatpation(0.8);
    individual2->change_adatpation(0.5);
    EXPECT_TRUE(*individual2 < individual1);
    EXPECT_FALSE(individual1 == *individual2);
    individual2->change_adatpation(0.8);
    EXPECT_TRUE(*individual2 == individual1);
}