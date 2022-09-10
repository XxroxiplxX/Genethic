//
// Created by piotrkali on 9/9/22.
//

#ifndef GENETHIC_LOWER_DIAG_PARSER_H
#define GENETHIC_LOWER_DIAG_PARSER_H

#include "fstream"
#include "Abstract_Parser.h"
class Lower_Diag_Parser : public Abstract_Parser{
public:
    bool cracked;
    int **matrixt;
    int dimension;
    std::string file;
    Lower_Diag_Parser(std::string file) : file(file) {}
    void read(const std::string file_name);
    void read_dimension() override;
    int** build_matrix() override;

};


#endif //GENETHIC_LOWER_DIAG_PARSER_H
