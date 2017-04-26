//
// Created by Justin Fairbourn on 4/23/2017.
//

#include <iostream>
#include <fstream>
#include "DenialOfServiceAnalyzerTester.h"
#include "../ITAK.h"

void DenialOfServiceAnalyzerTester::testLoading(){
    std::cout << "DenialOfServiceAnalyzerTester::testLoading" << std::endl;

    std::ifstream fin;
    fin.open("testData.csv");

    Configuration testConfig;
    KeyValue<std::string, std::string> testParam1("Analyzer Type", "1");
    KeyValue<std::string, std::string> testParam2("Timeframe", "3");
    KeyValue<std::string, std::string> testParam3("Likely Attack Message Count", "4");
    KeyValue<std::string, std::string> testParam4("Possible Attack Message Count", "2");
    testConfig.addNew(testParam1);
    testConfig.addNew(testParam2);
    testConfig.addNew(testParam3);
    testConfig.addNew(testParam4);


    if(fin.is_open()) ITAK testITAK(fin, testConfig);

}