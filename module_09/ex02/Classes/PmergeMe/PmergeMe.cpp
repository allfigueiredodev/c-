#include "Classes/PmergeMe/PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
    std::cout << "PmergeMe class default constructor called." << std::endl;
};

PmergeMe::PmergeMe(const PmergeMe& PmergeMe) {
    std::cout << "PmergeMe class copy constructor called." << std::endl;
    *this = PmergeMe;
};

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
    std::cout << "PmergeMe class copy assign operator called." << std::endl;
    if (this != &rhs){
        *this = rhs;
    }
    return *this;
};

PmergeMe::~PmergeMe(void) {
    std::cout << "PmergeMe class destructor called." << std::endl;
};

void	PmergeMe::makePairs(void) {
	for (size_t i = 0; i < this->_unsortedInput.size(); i+=2) {
		this->_unsortedPairInput.push_back(std::make_pair(this->_unsortedInput[i], this->_unsortedInput[i + 1] ));
	}
	for (size_t i = 0; i < this->_unsortedPairInput.size(); i++) {
		println(ORANGE << "Pair[" << i << "]: ");
		// println(GREEN << this->_unsortedPairInput[i].first);
		// println(GREEN << this->_unsortedPairInput[i].second);
		if (this->_unsortedPairInput[i].first < this->_unsortedPairInput[i].second)
			std::swap(this->_unsortedPairInput[i].first, this->_unsortedPairInput[i].second);
		// println(GREEN << this->_unsortedPairInput[i].first);
		// println(GREEN << this->_unsortedPairInput[i].second);
	}
}

void	PmergeMe::checkIfIsOdd(void) {
	if (this->_unsortedInput.size() % 2) {
		this->_theOddOne = this->_unsortedInput.back();
		this->_unsortedInput.pop_back();
	}
}

int	PmergeMe::isSorted(void) {
	std::vector<int> testCpy;
	testCpy = this->_unsortedInput;
	sort(testCpy.begin(), testCpy.end());
	if (testCpy == this->_unsortedInput) {
		println(GREEN << "Arguments are already sorted.")
		return (0);
	}
	return (1);
}

void	PmergeMe::inputValidation(int argc, char **argv) {
	std::string buffer;
	std::string argvString;

	for (int i = 1; i < argc; ++i) {
		argvString += argv[i];
		argvString += ' ';
	}
	std::stringstream stream(argvString);
	int i = 0;
	int temp;
	while(stream >> temp) {
		this->_unsortedInput.push_back(temp);
		if (this->_unsortedInput[i] < 0)
			throw std::invalid_argument("Negative number found.");
		i++;
	}
	if(!stream.eof())
		throw std::invalid_argument("Not valid type found.");
};

void PmergeMe::FJSort(int argc, char **argv) {
	try {
		this->inputValidation(argc, argv);
		if(!this->isSorted())
			return ;
	}
	catch (std::exception& e) {
		errorln(e.what());
	}
	this->checkIfIsOdd();
	this->makePairs();
};

