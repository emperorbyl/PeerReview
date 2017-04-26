//
// Created by Justin Fairbourn on 4/23/2017.
//

#ifndef HW7_PORTSCANANALYZER_H
#define HW7_PORTSCANANALYZER_H


#include "Analyzer.h"

class PortScanAnalyzer : public Analyzer{
public:
    PortScanAnalyzer(Configuration config);
    ResultSet run(std::ostream &out);
private:
    int likelyThreshold;
    int possibleThreshold;
};


#endif //HW7_PORTSCANANALYZER_H
