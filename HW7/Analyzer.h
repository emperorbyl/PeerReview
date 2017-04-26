//
// Created by Justin Fairbourn on 4/23/2017.
//

#ifndef HW7_ANALYZER_H
#define HW7_ANALYZER_H

#include "ResultSet.h"
#include "Configuration.h"

class Analyzer {
public:
    virtual ResultSet run(std::istream &in) = 0;
};


#endif //HW7_ANALYZER_H
