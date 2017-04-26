//
// Created by Justin Fairbourn on 4/23/2017.
//

#include "Utils.h"
#include <iostream>
#include <sstream>

//This function was taken from the GeoRegions assignment, I did not design it myself
bool split(const std::string& s, char delimiter, std::string pieces[], int expectedNumberOfPieces){
    std::stringstream ss;
    ss.str(s);
    std::string item;

    int i = 0;
    while(std::getline(ss, item, delimiter) && i < expectedNumberOfPieces){
        pieces[i++] = item;
    }
    return (i==expectedNumberOfPieces);
}