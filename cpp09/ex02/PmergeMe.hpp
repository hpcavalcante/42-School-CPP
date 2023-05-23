#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
#include <sys/time.h>
#include <string>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		bool is_positive_integer(const std::string& str);
		double get_time();

	template <typename Container>
	void display_elements(const Container& container) {
		typename Container::const_iterator it;
		for (it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	template <typename Container>
	void merge_insert_sort(Container& container) {
		if (container.size() <= 1)
			return;

		if (container.size() <= 16) {
			std::sort(container.begin(), container.end());
			return;
		}

		typename Container::iterator mid = container.begin();
		advance(mid, container.size() / 2);

		Container left(container.begin(), mid);
		Container right(mid, container.end());

		merge_insert_sort(left);
		merge_insert_sort(right);

		container.clear();
		merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(container));
	}
};

#endif