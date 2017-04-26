//
// Created by Justin Fairbourn on 4/23/2017.
//

#include "Configuration.h"

std::string Configuration::printConfigs() const {
    std::string output = "";
    for(int i = 0; i < getSize(); i++){
        KeyValue<std::string, std::string> *thisPair = configs.getByIndex(i);
        output += thisPair->getKey();
        output += ": ";
        output += thisPair->getValue();
        output += '\n';
    }
    return output;
}