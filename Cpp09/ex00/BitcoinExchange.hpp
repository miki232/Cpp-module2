#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <iomanip>
#include <limits>
#include <time.h>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _btcData;
    public:
        BitcoinExchange();
        BitcoinExchange(std::string fileName);
        BitcoinExchange(BitcoinExchange const &copy);
        BitcoinExchange &operator=(BitcoinExchange const &copy);
        ~BitcoinExchange();
        bool valid_data(std::string date, float value);
        void exchange_machine(std::string input);
        
};

#endif