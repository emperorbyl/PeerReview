//
// Created by Justin Fairbourn on 4/23/2017.
//

#include "DenialOfServiceAnalyzer.h"
#include "Utils.h"

#include <vector>

DenialOfServiceAnalyzer::DenialOfServiceAnalyzer(Configuration config){
    timeframe = config.getAsInt("Timeframe");
    likelyThreshold = config.getAsInt("Likely Attack Message Count");
    possibleThreshold = config.getAsInt("Possible Attack Message Count");
    KeyValue<std::string, std::vector<std::string>> *set1 = new KeyValue<std::string, std::vector<std::string>>("Likely Attackers", {});
    KeyValue<std::string, std::vector<std::string>> *set2 = new KeyValue<std::string, std::vector<std::string>>("Possible Attackers", {});
    KeyValue<std::string, std::vector<std::string>> *set3 = new KeyValue<std::string, std::vector<std::string>>("Attack Periods", {});
    KeyValue<std::string, std::vector<std::string>> *set4 = new KeyValue<std::string, std::vector<std::string>>("Timeframe", {});
    results.getResults()->add(set1);
    results.getResults()->add(set2);
    results.getResults()->add(set3);
    results.getResults()->add(set4);
}

ResultSet DenialOfServiceAnalyzer::run(std::istream &in){
    while(!in.eof()){
        //parse the line from the file
        std::string line;
        std::getline(in, line);
        std::string pieces[4];
        split(line, ',', pieces, 4);

        //check to see if the IP address is already in the Dictionary.
        if(data.findInDictionary(pieces[1]) == -1){
            //TODO: create a new entry in the data dictionary
            //std::cout << "Creating new entry for IP: " << pieces[1] << std::endl;
            Dictionary<int, int> *timeRecord = new Dictionary<int,int>(1);
            timeRecord->add(new KeyValue<int, int>(stoi(pieces[0]), 1));
            data.add(new KeyValue<std::string, Dictionary<int,int>*>(pieces[1],timeRecord));
        }else{
            //TODO: correctly increment the existing data
            Dictionary<int, int> *timeRecord = data.getByKey(pieces[1])->getValue();
            if(timeRecord->findInDictionary(stoi(pieces[0])) == -1){
                //std::cout << "Creating new Entry for Timestamp: " << pieces[0] << std::endl;
                timeRecord->add(new KeyValue<int, int>(stoi(pieces[0]), 1));
            }else{
                //std::cout << "Incrementing value for Timestamp: " << pieces[0];
                timeRecord->getByKey(stoi(pieces[0]))->setValue(timeRecord->getByKey(stoi(pieces[0]))->getValue() + 1);
                //std::cout << " new value: " << timeRecord->getByKey(stoi(pieces[0]))->getValue() << std::endl;
            }
        }
    }

    for(int i = 0; i < data.getSize(); i++){
        Dictionary<int, int> *timeRecord = data.getByIndex(i)->getValue();
        //the number of timeblocks that need to be checked. Should always be one more than the
        //timeRecord size - timeframe
        int rounds = (timeRecord->getSize() - timeframe) + 1;
        for(int j = 0; j < rounds; j++){
            int danger = checkTimeBlock(j, timeRecord);
            switch(danger){
                case 0:
                    break;
                case 1:
                    results.getResults()->getByIndex(0)->getValue().push_back(data.getByIndex(i)->getKey());
                    break;
                case 2:
                    results.getResults()->getByIndex(1)->getValue().push_back(data.getByIndex(i)->getKey());
                    break;
            }
        }
    }
    return results;
}

int DenialOfServiceAnalyzer::checkTimeBlock(int startingIndex, Dictionary<int, int> *timeRecord){
    int attacks = timeRecord->getByIndex(startingIndex)->getValue();
    int startTime = timeRecord->getByIndex(startingIndex)->getKey();
    int maxTime = startTime + timeframe;
    for(int i = 1; i < timeframe; i++){
        if(timeRecord->getByIndex(startingIndex + i)->getKey() < maxTime)
            attacks+= timeRecord->getByIndex(startingIndex+i)->getValue();
        else break;
    }
    std::string *period = new std::string;
    *(period) = std::to_string(startTime);
    *(period) += " - ";
    *(period) += std::to_string(maxTime);
    if(attacks >= likelyThreshold){
        results.getResults()->getByIndex(2)->getValue().push_back(*(period));
        return 2;
    }else if(attacks >= possibleThreshold){
        results.getResults()->getByIndex(2)->getValue().push_back(*(period));
        return 1;
    }else
        return 0;
}