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
    ResultSet(){ results = new Dictionary<std::string, std::vector<std::string>>;}
    Dictionary<std::string, std::vector<std::string>>* getResults(){return results;};
    //std::vector<std::string>* getSet(int i) {return *(results->getByIndex(i)->getValue());}
    const void print(std::ostream &out);
private:
    Dictionary<std::string, std::vector<std::string>> *results;
};


#endif //HW7_RESULTSET_H
