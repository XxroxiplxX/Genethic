#include <gtest/gtest.h>
#include "Lower_Diag_Parser.h"
#include "iostream"
using namespace std;
//
// Created by piotrkali on 9/9/22.
//
TEST(Parstest, reading) {
    Lower_Diag_Parser parser = Lower_Diag_Parser("gr17.tsp");
    parser.read_dimension();
    int **p = parser.build_matrix();
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 17; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}