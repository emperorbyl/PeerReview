//
// Created by Justin Fairbourn on 4/23/2017.
//

#ifndef HW7_DENIALOFSERVICEANALYZER_H
#define HW7_DENIALOFSERVICEANALYZER_H

#include "Analyzer.h"

class DenialOfServiceAnalyzer : public Analyzer {
public:
    DenialOfServiceAnalyzer(Configuration config);
    ResultSet run(std::istream &in);
private:
    int timeframe;
    int likelyThreshold;
    int possibleThreshold;
    int checkTimeBlock(int startingIndex, Dictionary<int, int> *timeRecord);
    Dictionary<std::string, Dictionary<int, int>*> data;
    ResultSet results;
};


#endif //HW7_DENIALOFSERVICEANALYZER_H
