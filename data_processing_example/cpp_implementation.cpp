#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <set>
#include <map>
#include <array>

#include <cstdio>
#include <cmath>

// Future feature -> Add data validation checks notifying the user of empty lines & incorrect format

typedef std::string string;
typedef std::array<size_t, 4> fourUnsignedIntArray;


struct StockRecord {
    /*
    The values in each line in the stock data file is represented by this struct
    */
    string  stock_name;
    int     interval;
    double     vol_traded;
    double     high;
    double     low;
};


bool determineVersionReq(string * const &firstArg) {
    /*
    Prints version if requested and returns a boolean value that tells if version info was requested
    */

    if (*firstArg == "version") {
        std::cout << "version 1" << std::endl;
        return true;
    } else { 
        return false; 
    };
}


auto getWhitespaceLocs(string stockLine) {
    /*
    Accepts a string of stock data and 
    Returns an integer array holding the indexes of whitespaces in the string
    */

    fourUnsignedIntArray whitespaceLocs = {};
    int whitespaceLocHolder {0};
    const int numCharsinLine = std::size(stockLine);
    
    for (int i {0}; i < numCharsinLine; ++i) {
        char whitespace {' '};

        if (stockLine[i] == whitespace) {
            whitespaceLocs[whitespaceLocHolder] = i;
            whitespaceLocHolder += 1;
        };
    }

    return whitespaceLocs;
}


std::vector<StockRecord> read_stocktrade_file(string fileLocation) {
    /*
    Returns an array of the StockRecord object with each record representing a line in the file.
    */

   string holdLine {""};
   std::vector<StockRecord> stockFrame {};

   std::ifstream stockInfoFile {fileLocation};    // Open file
                                                  // Add file Error Handling
    
    if (stockInfoFile.is_open()) {
        while (stockInfoFile)                     // Fix the double reading of the last line in file
        {
            
            std::getline(stockInfoFile, holdLine);    // Puts a line from the file into the holdLine string
            StockRecord stockHoldingVar {};

            // Add some data validation here in the future

            fourUnsignedIntArray whitespaceLoc = getWhitespaceLocs(holdLine);

            stockHoldingVar.stock_name = string{holdLine, 0, whitespaceLoc[0]};
            stockHoldingVar.interval = stoi(string{holdLine, whitespaceLoc[0], whitespaceLoc[1]});
            stockHoldingVar.vol_traded = stod(string{holdLine, whitespaceLoc[1], whitespaceLoc[2]});
            stockHoldingVar.high = stod(string{holdLine, whitespaceLoc[2], whitespaceLoc[3]});
            stockHoldingVar.low = stod(string{holdLine, whitespaceLoc[3], holdLine.size() - whitespaceLoc[3]});

            stockFrame.push_back(stockHoldingVar);
        }
    };

    stockFrame.pop_back();      // added as the while loop above adds the last row twice
    return stockFrame;
}


int main(int argc, char* argv[])
{
    if (argc <= 1) {
        std::cerr << "No input file passed in" << std::endl;
        return 0;
    };
    
    string FirstArg { argv[1] };
    string fileLoc  {""};

    bool versionRequested = determineVersionReq(&FirstArg);
    fileLoc = versionRequested ? argv[2] : argv[1];  // assigns 2nd arguement as flie location if version is requested else the 1st arguement is file loc
    // std::cout << "Reading file at: " << fileLoc << '\n' << std::endl;

    auto stockInfo = read_stocktrade_file(fileLoc);
    // std::cout << "File Read" << std::endl;

    std::set<string> stockNames {};        // a set holds all stock names

    std::map<string, double> stockVolTradedTotal {};
    std::map<string, double> stockHigh {};
    std::map<string, double> stockLow {};

    for (int i {0}; i < stockInfo.size(); ++i) {  
        StockRecord Record = stockInfo[i];

        if (stockNames.count(Record.stock_name) == 0) {

            stockNames.insert(Record.stock_name);
            stockVolTradedTotal[Record.stock_name] = Record.vol_traded;
            stockHigh[Record.stock_name] = Record.high;
            stockLow[Record.stock_name] = Record.low;

        } else {

            stockVolTradedTotal[Record.stock_name] += Record.vol_traded;
            stockHigh[Record.stock_name] =  Record.high > stockHigh[Record.stock_name] ?  Record.high: stockHigh[Record.stock_name];
            stockLow[Record.stock_name] =  Record.low < stockLow[Record.stock_name] ?  Record.low : stockLow[Record.stock_name];
        }
    }

    // stdout [StockName],[Interval], [%Volume of the day during this interval]
    for (int i {0}; i < stockInfo.size(); ++i) {  
        auto Record = stockInfo[i];

        auto percentTotal {(Record.vol_traded)/stockVolTradedTotal[Record.stock_name] * 100};

        std::cout << Record.stock_name << ',' <<  Record.interval << ',' << std::round(percentTotal) << std::endl;

    }

    std::cout << '#' << std::endl;  // Delimiter to meet design spec

    // stdout [StockName],[High for the day], [Low for the day]
    // The expected order is alphabetically i.e A to Z
    for (string stockName : stockNames) {
        std::cout << stockName << ',' << stockHigh.at(stockName) << ',' << stockLow.at(stockName) << std::endl;
    }

    return 0;
}