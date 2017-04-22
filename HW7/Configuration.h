//
// Created by Justin Fairbourn on 4/21/2017.
//

#ifndef HW7_CONFIGURATION_H
#define HW7_CONFIGURATION_H

#include "KeyValue.h"
#include "Dictionary.h"
#include <string>

class Configuration {
public:
    Configuration() {configs.Dictionary();}
    void addNew(KeyValue* newConfig) {configs.add(newConfig);}
    std::string getAsString(std::string key) {return (configs.getByKey(key))->getValue();}
    int getAsInt(std::string key) {return atoi((configs.getByKey(key))->getValue());}
    int getAsDouble(std::string key) {return atof((configs.getByKey(key))->getValue());}
private:
    Dictionary<std::string, std::string> configs;
};


#endif //HW7_CONFIGURATION_H
