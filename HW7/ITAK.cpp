//
// Created by Justin Fairbourn on 4/23/2017.
//

#include "ITAK.h"
#include "DenialOfServiceAnalyzer.h"
#include "PortScanAnalyzer.h"

ITAK::ITAK(std::istream &in, Configuration config){
    ResultSet results;
    int type = config.getAsInt("Analyzer Type");
    if(type == 1){
        analyzer = new DenialOfServiceAnalyzer(config);
        results = analyzer->run(in);
    }else{
        //analyzer = new PortScanAnalyzer(config);
    }
    results = analyzer->run(in);
    results.print(std::cout);
}