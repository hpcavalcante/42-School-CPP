#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    PmergeMe pmergeMe;
	
	std::vector<std::string> arguments(argv + 1, argv + argc);

    std::vector<int> numbers;
    for (size_t i = 0; i < arguments.size(); ++i)
    {
        if (pmergeMe.is_positive_integer(arguments[i]))
        {
            int num;
            std::stringstream ss(arguments[i]);
            ss >> num;
            numbers.push_back(num);
        }
        else
        {
            std::cout << "Error: Invalid argument '" << arguments[i] << "'." << std::endl;
            return 1;
        }
    }

    std::cout << "Before: ";
    pmergeMe.display_elements(numbers);

    std::deque<int> numbersDeque(numbers.begin(), numbers.end());


	double startVector = pmergeMe.get_time();
    pmergeMe.merge_insert_sort(numbers);
    double endVector = pmergeMe.get_time();

    std::cout << "After: ";
    pmergeMe.display_elements(numbers);

    double startDeque = pmergeMe.get_time();
    pmergeMe.merge_insert_sort(numbersDeque);
	double endDeque = pmergeMe.get_time();

    double elapsedTimeVector = (endVector - startVector);
	double elapsedTimeDeque = (endDeque - startDeque);

    std::cout << "Time to process a range of " << numbers.size() << " elements with vector: " << elapsedTimeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << numbersDeque.size() << " elements with deque: " << elapsedTimeDeque << " us" << std::endl;
}
