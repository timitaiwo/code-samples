#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <set>
#include <map>
#include <cstdio>


/**
VWAPer v0.1

// Read file in with the following format:
// [Stock],[Interval],[Volume Traded],[High],[Low]

// Calculate the total volume traded per Stock
// Calculate the total volume traded per Stock&Interval

// Write the total volume traded per Stock&Interval as a percentage of the total volume traded per Stock to stdout:
// [Stock],[Interval],[%Volume Traded]

// Write the delimiter '#' to stdout

// Write the maximum High and minimum Low for each Stock to stdout:
// [Stock],[Day High],[Day Low]

// example input:
VOD.L 1 100 184 183.7
BT.LN 1 300 449.4 448.2
VOD.L 2 25 184.1 182.4
BT.LN 2 900 449.8 449.5

// example output:
VOD.L,1,80
BT.LN,1,25
VOD.L,2,20
BT.LN,2,75
#
VOD.L,184.1,182.4
BT.LN,449.8,448.2

**/


// Add data validation checks notifying the user of empty lines

#define DELIMITER "#"

typedef std::string string;
typedef std::array<int, 4> fourIntArray;


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
        std::cout << "VWAPer version 0.1" << std::endl;
        return true;
    } else { 
        return false; 
    };
}


fourIntArray getWhitespaceLocs( const string& stockLine){
    /*
    Accepts a string of stock data and 
    Returns an integer array holding the indexes of whitespaces in the string
    */

    fourIntArray whitespaceLocs {};
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


string getLineSubstring(string line, int firstPos, int lastPos) {
    /*
    This function retrieves information used to populate the StockRecord struct.
    It accepts a line of stock data and two indexes
    */

    firstPos += 1;
    int numCharsAhead = lastPos - firstPos;

    return line.substr(firstPos, numCharsAhead);
}


std::vector<StockRecord> read_stocktrade_file(string fileLocation) {
    /*
    Returns an array of the StockRecord object with each record representing a line in the file.
    */

   string holdLine {""};
   int lines {0};                   // holds the number of lines read from file
   std::vector<StockRecord> stockFrame {};

   std::ifstream stockInfoFile {fileLocation};    // Open file
    
    if (stockInfoFile.is_open()) {
        while (stockInfoFile)
        {
            std::getline(stockInfoFile, holdLine);    // Puts a line from the file into the holdLine string
            StockRecord stockHoldingVar {};
            fourIntArray whitespaceLoc {getWhitespaceLocs(holdLine)};   // Holds location of whitespaces

            stockHoldingVar.stock_name = getLineSubstring(holdLine, -1, whitespaceLoc.at(1)-2);
            stockHoldingVar.interval = stoi(getLineSubstring(holdLine, whitespaceLoc.at(0), whitespaceLoc.at(1)));
            stockHoldingVar.vol_traded = stod(getLineSubstring(holdLine, whitespaceLoc.at(1), whitespaceLoc.at(2)));
            stockHoldingVar.high = stod(getLineSubstring(holdLine, whitespaceLoc.at(2), whitespaceLoc.at(3)));
            stockHoldingVar.low = stod(getLineSubstring(holdLine, whitespaceLoc.at(3), holdLine.size() - whitespaceLoc.at(3)));

            stockFrame.push_back(stockHoldingVar);     // add StockRecord object to stockFrame
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
    std::cout << "Reading file at: " << fileLoc << std::endl;

    auto stockInfo = read_stocktrade_file(fileLoc);

    std::set<string> stockNames {};        // a set holds all stock names
    // std::vector<string> stockNames {};

    std::map<string, double> stockVolTradedTotal {};

    std::map<string, double> stockHigh {};
    std::map<string, double> stockLow {};

    for (int i {0}; i < stockInfo.size(); ++i) {  
        auto Record = stockInfo[i];

        if (stockNames.count(Record.stock_name) == 0) {

            stockNames.insert(Record.stock_name);
            // stockNames.push_back(Record.stock_name);
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

        std::cout << Record.stock_name << ',' <<  Record.interval << ',' << percentTotal << std::endl;

        }

    std::cout << DELIMITER << std::endl;

    // stdout [StockName],[High for the day], [Low for the day]
    // The expected order is alphabetically i.e A to Z
    for (string stockName : stockNames) {
        std::cout << stockName << ',' << stockHigh.at(stockName) << ',' << stockLow.at(stockName) << std::endl;
    }

    // std::cout << std::endl << "code finished" << std::endl;

    return 0;
}