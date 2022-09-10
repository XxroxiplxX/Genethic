//
// Created by piotrkali on 9/9/22.
//

#ifndef GENETHIC_PARSER_H
#define GENETHIC_PARSER_H

#include "fstream"
#include "Abstract_Parser.h"
class Parser : public Abstract_Parser{
public:
    bool cracked;
    int **matrixt;
    int dimension;
    std::string file;
    Parser(std::string file) : file(file) {}
    void read(const std::string file_name);
    void read_dimension() override;
    int** build_matrix() override;

};


#endif //GENETHIC_PARSER_H
