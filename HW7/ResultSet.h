//
// Created by Justin Fairbourn on 4/23/2017.
//

#ifndef HW7_RESULTSET_H
#define HW7_RESULTSET_H
#include "Dictionary.h"
#include <string>
#include <iostream>
#include <vector>

class ResultSet {
public:
    const void print(std::ostream &out);
    Dictionary<std::string, std::vector<std::string>> results;
};


#endif //HW7_RESULTSET_H
