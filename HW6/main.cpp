#include <iostream>
#include <iomanip>

#include "Dictionary.h"

int main() {
    std::cout << "Executing main" << std::endl;
    std::cout << "Creating Table 1 - Sample Directory" << std::endl << std::endl;

    Dictionary<std::string, std::string> newDictionary(3);

    newDictionary.add(new KeyValue<std::string, std::string>("Hair Color","Blonde"));
    newDictionary.add(new KeyValue<std::string, std::string>("Eye Color","Blue"));
    newDictionary.add(new KeyValue<std::string, std::string>("Favorite Candy","Reese's Pieces"));
    newDictionary.add(new KeyValue<std::string, std::string>("Favorite Movie","Rogue One"));
    newDictionary.add(new KeyValue<std::string, std::string>("Favorite Food","Pizza"));
    newDictionary.add(new KeyValue<std::string, std::string>("Favorite Class","CS1440"));
    newDictionary.add(new KeyValue<std::string, std::string>("Favorite Color","Pink"));

    newDictionary.removeByIndex(2);
    newDictionary.removeByKey("Favorite Color");

    std::cout << "Dictionary KeyValue List:" << std::endl
              << "=========================" << std::endl;
    for(int i = 0; i < newDictionary.getSize(); i++){
        std::cout << newDictionary.getByIndex(i)->getKey()
                  << " : "
                  << newDictionary.getByIndex(i)->getValue()
                  << std::endl;
    }
}