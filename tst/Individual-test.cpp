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