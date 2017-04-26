//
// Created by Justin Fairbourn on 4/23/2017.
//

#ifndef HW7_ITAK_H
#define HW7_ITAK_H

#include "Analyzer.h"

class ITAK {
public:
    ITAK(std::istream &in, Configuration config);
private:
    Analyzer *analyzer;
    ResultSet *results;
};


#endif //HW7_ITAK_H
