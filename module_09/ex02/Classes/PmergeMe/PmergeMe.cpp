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

void	PmergeMe::printLog(int argc) {
	double duration_us = static_cast<double>(_endTime - _startTime) / CLOCKS_PER_SEC * 1000000;
	if (this->_theOddOne != -1)
		this->_unsortedInput.push_back(this->_theOddOne);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << CYAN << "Before: ";
	for (size_t i = 0; i < this->_unsortedInput.size(); i++) {
		std::cout << ORANGE << this->_unsortedInput[i] << " ";
	}
	println("");
	std::cout << CYAN << "After: ";
	for (it iter = _sorted.begin(); iter != _sorted.end(); iter++) {
		std::cout << ORANGE << *iter << " ";
	}
	println("");
	println(GREEN << "Time to process a range of " << argc - 1 <<  " elements with std::vector : " << duration_us << " us");
	println(GREEN << "Time to process a range of " << argc - 1 <<  " elements with std::deque : " << duration_us << " us");
}

void	PmergeMe::mergePend(void) {
	int	value;
	it pos;  
	for (it iter = _insertionOrder.begin(); iter != _insertionOrder.end(); iter++) {
		value = _pend[*iter];
		pos = std::upper_bound(_sorted.begin(), _sorted.end(), value);
		_sorted.insert(pos, value);
	}
	_sorted.erase(std::unique(_sorted.begin(), _sorted.end()), _sorted.end());
	this->_endTime = std::clock();
	// println(CYAN << "Sorted result: ");
	// for (it iter = _sorted.begin(); iter != _sorted.end(); iter++) {
	// 	std::cout << ORANGE << *iter << ", ";
	// }
	// println("");
}

void	PmergeMe::createInsertionOrder(void) {
	_insertionOrder.push_back(_jacobsSequence.front());

	while (_insertionOrder.size() < _pend.size()) {
		_jacobsSequence.erase(_jacobsSequence.begin());
		if (!(_jacobsSequence.empty())) {
			int	_lastInsertionNbr = _insertionOrder.back();
			int	_currentJacobs = _jacobsSequence.front();
		
			_insertionOrder.push_back(_currentJacobs);
			_currentJacobs--;
			while(_currentJacobs > _lastInsertionNbr && _insertionOrder.size() < _pend.size()) {
				it begin = _insertionOrder.begin();
				it end = _insertionOrder.end();

				if (std::find(begin, end, _currentJacobs) == end) {
					_insertionOrder.push_back(_currentJacobs);
				}
				_currentJacobs--;
			}
		} else {
			size_t	missing = _pend.size() - 1;

			while (_insertionOrder.size() < _pend.size()) {
				_insertionOrder.push_back(missing);
				missing--;
			}
		}
	}
	// println(CYAN << "Insertion order: ");
	// for (it iter = _insertionOrder.begin(); iter != _insertionOrder.end(); iter++) {
	// 	std::cout << ORANGE << *iter << ", "; 
	// }
	// println("");
}

void	PmergeMe::initJacobs(void) {
	this->_jacobsSequence.push_back(0);
	this->_jacobsSequence.push_back(1);
	while (this->_jacobsSequence.back() <= static_cast<int>(this->_pend.size())) {
		this->_jacobsSequence.push_back(this->_jacobsSequence.back() + (2 * *(this->_jacobsSequence.end() - 2)));
	}
	this->_jacobsSequence.erase(this->_jacobsSequence.begin() + 1);
	// println(CYAN << "Jacobs: ");
	// for (it iter = this->_jacobsSequence.begin(); iter != this->_jacobsSequence.end(); iter++) {
	// 	std::cout << ORANGE << *iter << ", ";
	// }
	// println("");
}

void	PmergeMe::splitSortedPend(void) {
	for (vIntPairIter iter = this->_unsortedPairInput.begin(); iter != this->_unsortedPairInput.end(); iter++) {
		this->_sorted.push_back(iter->first);
		this->_pend.push_back(iter->second);
	}
	if(this->_theOddOne >= 0)
		this->_pend.push_back(this->_theOddOne);
	// println(CYAN << "_sorted: ");
	// for (it iter = this->_sorted.begin(); iter != this->_sorted.end(); iter++) {
	// 	std::cout << ORANGE << *iter << ", ";
	// }
	// println("");
	// println(CYAN << "_pend: ");
	// for (it iter = this->_pend.begin(); iter != this->_pend.end(); iter++) {
	// 	std::cout << ORANGE << *iter << ", ";
	// }
	// println("");
}

void	PmergeMe::makePairs(void) {
	this->_startTime = std::clock();
	for (size_t i = 0; i < this->_unsortedInput.size(); i+=2) {
		this->_unsortedPairInput.push_back(std::make_pair(this->_unsortedInput[i], this->_unsortedInput[i + 1] ));
	}
	for (size_t i = 0; i < this->_unsortedPairInput.size(); i++) {
		// println(ORANGE << "Pair[" << i << "]: ");
		// println(GREEN << this->_unsortedPairInput[i].first);
		// println(GREEN << this->_unsortedPairInput[i].second);
		if (this->_unsortedPairInput[i].first < this->_unsortedPairInput[i].second)
			std::swap(this->_unsortedPairInput[i].first, this->_unsortedPairInput[i].second);
		// println(GREEN << this->_unsortedPairInput[i].first);
		// println(GREEN << this->_unsortedPairInput[i].second);
	}
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
	this->mergePend();
	this->printLog(argc);
};
