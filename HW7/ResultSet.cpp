//
// Created by Justin Fairbourn on 4/23/2017.
//

#include "ResultSet.h"

const void ResultSet::print(std::ostream &out){
    for(int i = 0; i < results->getSize(); i++){
        KeyValue<std::string, std::vector<std::string>> *thisPair;
        thisPair = results->getByIndex(i);
        out << thisPair->getKey() << std::endl;
        for(int j = 0; j < thisPair->getValue().size(); j++){
            out << '\t' << thisPair->getValue()[j] << std::endl;
        }
    }
}