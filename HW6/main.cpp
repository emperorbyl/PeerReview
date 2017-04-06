#include <iostream>

#include "Dictionary.h"
#include "KeyValue.h"

int main() {
    std::cout << "Executing main" << std::endl;
    std::cout << "Creating Table 1 - Sample Directory" << std::endl;

    Dictionary<std::string, std::string> newDictionary(3);

    newDictionary.add(new KeyValue<std::string, std::string>("Hair Color","Blonde"));
    newDictionary.add(new KeyValue<std::string, std::string>("Eye Color","Blue"));
    newDictionary.add(new KeyValue<std::string, std::string>("Favorite Movie","Rogue One"));
    newDictionary.add(new KeyValue<std::string, std::string>("Favorite Food","Pizza"));
    newDictionary.add(new KeyValue<std::string, std::string>("Favorite Class","CS1440"));
}