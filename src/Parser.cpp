//
// Created by piotrkali on 9/9/22.
//

#include "Parser.h"
#include "string"
#include "iostream"
using namespace std;
void Parser::read(const std::string file_name) {
    fstream stream;
    stream.open("/home/piotrkali/projects/CLionProjects/Genethic/resources/" + file_name);
    std::string text;
    if (stream.is_open()) {
        int **matrix;
        do {
            stream >> text;
            if (text == "DIMENSION:") {
                stream >> dimension;
                matrix = new int*[dimension];
                for (int i = 0; i < dimension; i++) {
                    matrix[i] = new int[dimension];
                }
            }
            if (text == "EDGE_WEIGHT_FORMAT:") {
                stream >> text;
                if (text == "LOWER_DIAG_ROW") {
                    cracked = false;
                } else {
                    cracked = true;
                }
            }
            if (text == "EDGE_WEIGHT_SECTION") {
                int tmp;
                for (int i = 0; i < dimension; i++) {
                    for (int j = 0; j <= i; j++) {
                        stream >> tmp;
                        matrix[i][j] = tmp;
                    }
                }
                for (int i = 0; i < dimension; i++) {
                    for (int j = dimension - 1; j >= i; j--) {
                        matrix[i][j] = matrix[j][i];
                    }
                }
            }
        } while (text != "EOF");
    }
    stream.close();
}

void Parser::read_dimension() {
    fstream stream;
    stream.open("/home/piotrkali/projects/CLionProjects/Genethic/resources/" + file);
    std::string text;
    if (stream.is_open()) {
        int **matrix;
        do {
            stream >> text;
            if (text == "DIMENSION:") {
                stream >> dimension;
            }
        } while (text != "EOF");
    }
}

int **Parser::build_matrix() {
    int **matrix;
    matrix = new int*[dimension];
    for (int i = 0; i < dimension; i++) {
        matrix[i] = new int[dimension];
    }
    string text;
    fstream stream;
    stream.open("/home/piotrkali/projects/CLionProjects/Genethic/resources/" + file);
    if (stream.is_open()) {
        do {
            stream >> text;
            if (text == "EDGE_WEIGHT_FORMAT:") {
                stream >> text;
                if (text == "LOWER_DIAG_ROW") {
                    cracked = false;
                } else {
                    cracked = true;
                }
            }
            if (text == "EDGE_WEIGHT_SECTION") {
                int tmp;
                for (int i = 0; i < dimension; i++) {
                    for (int j = 0; j <= i; j++) {
                        stream >> tmp;
                        matrix[i][j] = tmp;
                    }
                }
                for (int i = 0; i < dimension; i++) {
                    for (int j = dimension - 1; j >= i; j--) {
                        matrix[i][j] = matrix[j][i];
                    }
                }
            }
        } while (text != "EOF");
    }
    return matrix;
}


