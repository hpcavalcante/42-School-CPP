#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {
}

bool PmergeMe::is_positive_integer(const std::string& str) {
	if (str.empty())
		return false;

	for (size_t i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i]))
			return false;
	}

	return true;
}

double PmergeMe::get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000.0 + tv.tv_usec;
}
