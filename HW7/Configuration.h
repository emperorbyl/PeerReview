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
    Configuration() {};
    void addNew(KeyValue<std::string, std::string> &newConfig) {configs.add(&newConfig);}
    int getSize() const {return configs.getSize(); }
    int getAllocated() const {return configs.getAllocated();}
    std::string getAsString(std::string key) const {return (configs.getByKey(key))->getValue();}
    int getAsInt(std::string key) const {return stoi((configs.getByKey(key))->getValue());}
    double getAsDouble(std::string key) const {return stof((configs.getByKey(key))->getValue());}
    std::string printConfigs() const {
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
private:
    Dictionary<std::string, std::string> configs;
};


#endif //HW7_CONFIGURATION_H
