//
// Created by piotrkali on 9/10/22.
//

#ifndef GENETHIC_ABSTRACT_PARSER_H
#define GENETHIC_ABSTRACT_PARSER_H


class Abstract_Parser {
    virtual void read_dimension() = 0;
    virtual int** build_matrix() = 0;
};


#endif //GENETHIC_ABSTRACT_PARSER_H
