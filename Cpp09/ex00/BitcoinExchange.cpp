#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    return ;
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
    std::ifstream file(filename.c_str());

    if(!file.is_open())
    {
        std::cerr << "Error: Could not open file." << std::endl;
        return ;
    }
    std::string line;
	size_t delim;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		delim = line.find(',');
		std::string rateString = line.substr(delim + 1);
		float rate = std::atof(rateString.c_str());
		this->_btcData[line.substr(0, delim)] = rate;
	}
    file.close();
}

bool    BitcoinExchange::valid_data(std::string date, float value)
{
    std::istringstream dateStream(date);
    int year, month, day;
    char dash1, dash2;

    if (!(dateStream >> year >> dash1 >> month >> dash2 >> day) ||
        dash1 != '-' || dash2 != '-' ||
        year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        std::cerr << "Error: Invalid date format => " << date << std::endl;
        return false;
    }
    if (value < 0.00) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value < 0 || value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::exchange_machine(std::string input)
{
    std::ifstream f_input(input.c_str());

    if(!f_input.is_open())
    {
        std::cerr << "Error: Could not open file." << std::endl;
        return ;
    }
    std::string line;
    while (std::getline(f_input, line)) {
        std::replace(line.begin(), line.end(), '|', ' ');

        std::istringstream iss(line);
        std::string date;
        float value;

        if (!(iss >> date >> value)) {
            if ((date.size() < 10))
                continue;
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (BitcoinExchange::valid_data(date, value) == false)
            continue;
        std::map<std::string, float>::iterator it = _btcData.find(date);
        if (it == _btcData.end()) {
            it = _btcData.lower_bound(date);
            if (it != _btcData.begin())
                --it;
        }
        float exchangeRate = it->second;
        float result = value * exchangeRate;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy)
{
    if (this != &copy)
    {
        this->_btcData = copy._btcData;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    return ;
}