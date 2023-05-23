#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::~BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(std::string nameFile) : _nameFile(nameFile) {
	return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
	return;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
	if (this != &src) {
		this->_database = src._database;
		this->_nameFile = src._nameFile;
	}
	return (*this);
}

void BitcoinExchange::loadData() {
	
	std::ifstream db ("data/data.csv");
	std::string key;
	std::string value;

	if (!db.is_open()) {
		std::cerr << "Error: Could not open database file\n";
	}
	else {
		getline(db, key);
		while(!db.eof()){
			getline(db, key, ',');
			getline(db, value);
			this->_database.insert(std::pair<std::string, double>(key,std::atof(value.c_str())));
		}
		db.close();
	}
}

bool BitcoinExchange::checkDate(std::string date) {

	int year;
	int month;
	int day;

	sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
	if (day > 31 || day < 0 || month > 12 || month < 0 || year > 2022 || year < 2009) {
		std::cerr << "Error: invalid date => " << date << "\n";
		return (false);
	}
	return (true);
}

std::string BitcoinExchange::minusDate(std::string date) {
	
	int year ;
    int month ;
    int day ;

    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);

    day--;
    if (day <= 0){
        day = 31;
        month --;
    }
    if (month <= 0){
        month = 12;
        year --;
    }
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(4) << year << "-"
       << std::setw(2) << month << "-" << std::setw(2) << day;
    return ss.str();
}

bool BitcoinExchange::checkIfExist(std::string date){
    std::map<std::string,double>::iterator it = this->_database.begin();
    it = this->_database.find(date);
    if (it == this->_database.end()){
		return false;
	}
	return true;
}

bool BitcoinExchange::checkInput() {
	std::ifstream 	myfile(_nameFile.c_str());
	if (myfile.is_open()) {
		_inputFile = std::string((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());
		return (true);
	}
	else {
		std::cout << "Error: could not open file.\n";
		return (false);
	}
}

bool BitcoinExchange::isNumeric(const std::string& value) {
    bool decimalPoint = false;
    
	for (std::size_t i = 0; i < value.size(); ++i) {
        char c = value[i];
        if (i == 0 && value[i] == '-')
            continue;
        if (c == '.') {
            if (decimalPoint) {
                return false; 
            } else {
                decimalPoint = true;
            }
        } else if (!std::isdigit(c)) {
            return false; 
        }
    }
    return true;
}

void BitcoinExchange::runInput() {
	std::istringstream 	inputFile(_inputFile);
	std::string 		line;
	std::string 		value;
	std::string 		date;
	double 				finalPrice;
	
	getline(inputFile, date);
	if (date != "date | value") {
		std::cerr << "Error: Invalid header on input file\n";
		return;
	}
	while (std::getline(inputFile, line)) {
		
		std::stringstream ss(line);

		if (getline(ss, date, '|') && ss >> value) {
			date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
			date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
		} else {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!checkDate(date)) {
			continue;
		}
		if (!isNumeric(value)) {
			std::cout << "Error: input contains non-numeric characters.\n";
			continue;
		}
		if (atof(value.c_str()) < 0) {
			std::cout << "Error: Not a positive number.\n";
			continue;
		}
		if (atof(value.c_str()) > INT_MAX) {
			std::cout << "Error: too large number.\n";
			continue;
		}
		std::cout << date << " => ";
		while (!checkIfExist(date)) {
			date = minusDate(date);
			if (!checkDate(date))
				return;
		}
		finalPrice = this->_database.find(date)->second * atof(value.c_str());
		std::cout << value << " = " << finalPrice << "\n";
	}
}

std::ostream&    operator<<(std::ostream& o, const BitcoinExchange& i)
{
    (void)i;
	o << "";
    return o;
}