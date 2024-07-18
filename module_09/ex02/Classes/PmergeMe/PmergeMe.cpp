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

bool comparePairsInDescending(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first > b.first;
}

void	PmergeMe::createInsertionOrder(void) {
	this->_insertionOrder.push_back(*(this->_jacobs.begin()));
	this->_jacobs.erase(this->_jacobs.begin());
	while(this->_insertionOrder.size() <= this->_pend.size()) {
		if(!this->_jacobs.empty()) {
			this->_firstJacob = this->_jacobs.front();
			this->_lastInsertionOrder = this->_insertionOrder.back();
			this->_insertionOrder.push_back(this->_jacobs.front());
			this->_firstJacob--;
			//Coloca o valor do primeiro elemento do jacobsthal num int -> int jacob = jacobsthal.front()
			//Coloca o valor do último elemento da lista de inserção em outro int -> int last = container.back()
		} else {

		}
	}
}

void	PmergeMe::initJacobs(void) {
	this->_jacobs.push_back(0);
	this->_jacobs.push_back(1);
	while (this->_jacobs.back() <= static_cast<int>(this->_pend.size())) {
		this->_jacobs.push_back(this->_jacobs.back() + (2 * *(this->_jacobs.end() - 2)));
	}
	this->_jacobs.erase(this->_jacobs.begin() + 1);
	// println("Jacobs: ");
	// for (it iter = this->_jacobs.begin(); iter != this->_jacobs.end(); iter++) {
	// 	println(ORANGE << *iter);
	// }
	// Dentro desse loop, você vai dar push num novo número cada vez.
	// Esse número vai ser o último número + duas vezes o número anterior a ele -> new_nbr = container.back() + 2 * *(container.end() + 1)
}

void	PmergeMe::splitSortedPend(void) {
	for (vIntPairIter iter = this->_unsortedPairInput.begin(); iter != this->_unsortedPairInput.end(); iter++) {
		this->_sorted.push_back(iter->first);
		this->_pend.push_back(iter->second);
	}
	if(this->_theOddOne >= 0)
		this->_pend.push_back(this->_theOddOne);
	println(CYAN << "_sorted: ");
	for (it iter = this->_sorted.begin(); iter != this->_sorted.end(); iter++) {
		std::cout << ORANGE << *iter << ", ";
	}
	println("");
	println(CYAN << "_pend: ");
	for (it iter = this->_pend.begin(); iter != this->_pend.end(); iter++) {
		std::cout << ORANGE << *iter << ", ";
	}
	println("");
}

void	PmergeMe::makePairs(void) {
	for (size_t i = 0; i < this->_unsortedInput.size(); i+=2) {
		this->_unsortedPairInput.push_back(std::make_pair(this->_unsortedInput[i], this->_unsortedInput[i + 1] ));
	}
	for (size_t i = 0; i < this->_unsortedPairInput.size(); i++) {
		println(ORANGE << "Pair[" << i << "]: ");
		println(GREEN << this->_unsortedPairInput[i].first);
		println(GREEN << this->_unsortedPairInput[i].second);
		if (this->_unsortedPairInput[i].first < this->_unsortedPairInput[i].second)
			std::swap(this->_unsortedPairInput[i].first, this->_unsortedPairInput[i].second);
		println(GREEN << this->_unsortedPairInput[i].first);
		println(GREEN << this->_unsortedPairInput[i].second);
	}
	// sort(this->_unsortedPairInput.begin(), this->_unsortedPairInput.end(), comparePairsInDescending);
	sort(this->_unsortedPairInput.begin(), this->_unsortedPairInput.end());
	// println(CYAN << "After sort: ");
	// for (size_t i = 0; i < this->_unsortedPairInput.size(); i++) {
	// 	std::cout << ORANGE << this->_unsortedPairInput[i].first << ", ";
	// }
}

void	PmergeMe::checkIfIsOdd(void) {
	if (this->_unsortedInput.size() % 2) {
		this->_theOddOne = this->_unsortedInput.back();
		this->_unsortedInput.pop_back();
	}
	else
		this->_theOddOne = -1;
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
	this->splitSortedPend();
	this->initJacobs();
	this->createInsertionOrder();
};
