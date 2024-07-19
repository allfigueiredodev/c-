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
	double durationV = static_cast<double>(vData._endTime - vData._startTime) / CLOCKS_PER_SEC * 1000.0;
	double durationD = static_cast<double>(dData._endTime - dData._startTime) / CLOCKS_PER_SEC * 1000.0;
	if (this->vData._theOddOne != -1)
		this->vData._unsortedInput.push_back(this->vData._theOddOne);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << CYAN << "Before: ";
	for (size_t i = 0; i < this->vData._unsortedInput.size(); i++) {
		std::cout << ORANGE << this->vData._unsortedInput[i] << " ";
	}
	println("");
	std::cout << CYAN << "After: ";
	for (vIt iter = vData._sorted.begin(); iter != vData._sorted.end(); iter++) {
		std::cout << ORANGE << *iter << " ";
	}
	println("");
	println(GREEN << "Time to process a range of " << argc - 1 <<  " elements with std::vector: " << durationV << " us");
	println(GREEN << "Time to process a range of " << argc - 1 <<  " elements with std::deque : " << durationD << " us");
}

void	PmergeMe::vMergePend(void) {
	int	value;
	vIt pos;  
	for (vIt iter = vData._insertionOrder.begin(); iter != vData._insertionOrder.end(); iter++) {
		value = vData._pend[*iter];
		pos = std::upper_bound(vData._sorted.begin(), vData._sorted.end(), value);
		vData._sorted.insert(pos, value);
	}
	// vData._sorted.erase(std::unique(vData._sorted.begin(), vData._sorted.end()), vData._sorted.end());
	this->vData._endTime = std::clock();
	// println(CYAN << "Sorted result: ");
	// for (it iter = _sorted.begin(); iter != _sorted.end(); iter++) {
	// 	std::cout << ORANGE << *iter << ", ";
	// }
	// println("");
}

void	PmergeMe::dMergePend(void) {
	int	value;
	dIt pos;  
	for (dIt iter = dData._insertionOrder.begin(); iter != dData._insertionOrder.end(); iter++) {
		value = dData._pend[*iter];
		pos = std::upper_bound(dData._sorted.begin(), dData._sorted.end(), value);
		dData._sorted.insert(pos, value);
	}
	dData._sorted.erase(std::unique(dData._sorted.begin(), dData._sorted.end()), dData._sorted.end());
	this->dData._endTime = std::clock();
	// println(CYAN << "Sorted result: ");
	// for (it iter = _sorted.begin(); iter != _sorted.end(); iter++) {
	// 	std::cout << ORANGE << *iter << ", ";
	// }
	// println("");
}

void	PmergeMe::vCreateInsertionOrder(void) {
	vData._insertionOrder.push_back(vData._jacobsSequence.front());

	while (vData._insertionOrder.size() < vData._pend.size()) {
		vData._jacobsSequence.erase(vData._jacobsSequence.begin());
		if (!(vData._jacobsSequence.empty())) {
			int	_lastInsertionNbr = vData._insertionOrder.back();
			int	_currentJacobs = vData._jacobsSequence.front();
		
			vData._insertionOrder.push_back(_currentJacobs);
			_currentJacobs--;
			while(_currentJacobs > _lastInsertionNbr && vData._insertionOrder.size() < vData._pend.size()) {
				vIt begin = vData._insertionOrder.begin();
				vIt end = vData._insertionOrder.end();

				if (std::find(begin, end, _currentJacobs) == end) {
					vData._insertionOrder.push_back(_currentJacobs);
				}
				_currentJacobs--;
			}
		} else {
			size_t	missing = vData._pend.size() - 1;

			while (vData._insertionOrder.size() < vData._pend.size()) {
				vData._insertionOrder.push_back(missing);
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

void	PmergeMe::dCreateInsertionOrder(void) {
	dData._insertionOrder.push_back(dData._jacobsSequence.front());

	while (dData._insertionOrder.size() < dData._pend.size()) {
		dData._jacobsSequence.erase(dData._jacobsSequence.begin());
		if (!(dData._jacobsSequence.empty())) {
			int	_lastInsertionNbr = dData._insertionOrder.back();
			int	_currentJacobs = dData._jacobsSequence.front();
		
			dData._insertionOrder.push_back(_currentJacobs);
			_currentJacobs--;
			while(_currentJacobs > _lastInsertionNbr && dData._insertionOrder.size() < dData._pend.size()) {
				dIt begin = dData._insertionOrder.begin();
				dIt end = dData._insertionOrder.end();

				if (std::find(begin, end, _currentJacobs) == end) {
					dData._insertionOrder.push_back(_currentJacobs);
				}
				_currentJacobs--;
			}
		} else {
			size_t	missing = dData._pend.size() - 1;

			while (dData._insertionOrder.size() < dData._pend.size()) {
				dData._insertionOrder.push_back(missing);
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

void	PmergeMe::vInitJacobs(void) {
	this->vData._jacobsSequence.push_back(0);
	this->vData._jacobsSequence.push_back(1);
	while (this->vData._jacobsSequence.back() <= static_cast<int>(this->vData._pend.size())) {
		this->vData._jacobsSequence.push_back(this->vData._jacobsSequence.back() + (2 * *(this->vData._jacobsSequence.end() - 2)));
	}
	this->vData._jacobsSequence.erase(this->vData._jacobsSequence.begin() + 1);
	// println(CYAN << "Jacobs: ");
	// for (it iter = this->_jacobsSequence.begin(); iter != this->_jacobsSequence.end(); iter++) {
	// 	std::cout << ORANGE << *iter << ", ";
	// }
	// println("");
}

void	PmergeMe::dInitJacobs(void) {
	this->dData._jacobsSequence.push_back(0);
	this->dData._jacobsSequence.push_back(1);
	while (this->dData._jacobsSequence.back() <= static_cast<int>(this->dData._pend.size())) {
		this->dData._jacobsSequence.push_back(this->dData._jacobsSequence.back() + (2 * *(this->dData._jacobsSequence.end() - 2)));
	}
	this->dData._jacobsSequence.erase(this->dData._jacobsSequence.begin() + 1);
	// println(CYAN << "Jacobs: ");
	// for (it iter = this->_jacobsSequence.begin(); iter != this->_jacobsSequence.end(); iter++) {
	// 	std::cout << ORANGE << *iter << ", ";
	// }
	// println("");
}

void	PmergeMe::vSplitSortedPend(void) {
	for (vIntPairIter iter = this->_unsortedVPairInput.begin(); iter != this->_unsortedVPairInput.end(); iter++) {
		this->vData._sorted.push_back(iter->first);
		this->vData._pend.push_back(iter->second);
	}
	if(this->vData._theOddOne >= 0)
		this->vData._pend.push_back(this->vData._theOddOne);
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

void	PmergeMe::dSplitSortedPend(void) {
	for (dIntPairIter iter = this->_unsortedDPairInput.begin(); iter != this->_unsortedDPairInput.end(); iter++) {
		this->dData._sorted.push_back(iter->first);
		this->dData._pend.push_back(iter->second);
	}
	if(this->dData._theOddOne >= 0)
		this->dData._pend.push_back(this->dData._theOddOne);
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

void	PmergeMe::vMakePairs(void) {
	for (size_t i = 0; i < this->vData._unsortedInput.size(); i+=2) {
		this->_unsortedVPairInput.push_back(std::make_pair(this->vData._unsortedInput[i], this->vData._unsortedInput[i + 1] ));
	}
	for (size_t i = 0; i < this->_unsortedVPairInput.size(); i++) {
		// println(ORANGE << "Pair[" << i << "]: ");
		// println(GREEN << this->_unsortedVPairInput[i].first);
		// println(GREEN << this->_unsortedVPairInput[i].second);
		if (this->_unsortedVPairInput[i].first < this->_unsortedVPairInput[i].second)
			std::swap(this->_unsortedVPairInput[i].first, this->_unsortedVPairInput[i].second);
		// println(GREEN << this->_unsortedVPairInput[i].first);
		// println(GREEN << this->_unsortedVPairInput[i].second);
	}
	sort(this->_unsortedVPairInput.begin(), this->_unsortedVPairInput.end());
	// println(CYAN << "After sort: ");
	// for (size_t i = 0; i < this->_unsortedPairInput.size(); i++) {
	// 	std::cout << ORANGE << this->_unsortedPairInput[i].first << ", ";
	// }
}

void	PmergeMe::dMakePairs(void) {
	for (size_t i = 0; i < this->dData._unsortedInput.size(); i+=2) {
		this->_unsortedVPairInput.push_back(std::make_pair(this->dData._unsortedInput[i], this->dData._unsortedInput[i + 1] ));
	}
	for (size_t i = 0; i < this->_unsortedVPairInput.size(); i++) {
		// println(ORANGE << "Pair[" << i << "]: ");
		// println(GREEN << this->_unsortedVPairInput[i].first);
		// println(GREEN << this->_unsortedVPairInput[i].second);
		if (this->_unsortedVPairInput[i].first < this->_unsortedVPairInput[i].second)
			std::swap(this->_unsortedVPairInput[i].first, this->_unsortedVPairInput[i].second);
		// println(GREEN << this->_unsortedVPairInput[i].first);
		// println(GREEN << this->_unsortedVPairInput[i].second);
	}
	sort(this->_unsortedVPairInput.begin(), this->_unsortedVPairInput.end());
	// println(CYAN << "After sort: ");
	// for (size_t i = 0; i < this->_unsortedPairInput.size(); i++) {
	// 	std::cout << ORANGE << this->_unsortedPairInput[i].first << ", ";
	// }
}

void	PmergeMe::vCheckIfIsOdd(void) {
	this->vData._startTime = std::clock();
	if (this->vData._unsortedInput.size() % 2) {
		this->vData._theOddOne = this->vData._unsortedInput.back();
		this->vData._unsortedInput.pop_back();
	}
	else
		this->vData._theOddOne = -1;
}

void	PmergeMe::dCheckIfIsOdd(void) {
	this->dData._startTime = std::clock();
	if (this->dData._unsortedInput.size() % 2) {
		this->dData._theOddOne = this->dData._unsortedInput.back();
		this->dData._unsortedInput.pop_back();
	}
	else
		this->dData._theOddOne = -1;
}

int	PmergeMe::vIsSorted(void) {
	std::vector<int> testCpy;
	testCpy = this->vData._unsortedInput;
	sort(testCpy.begin(), testCpy.end());
	if (testCpy == this->vData._unsortedInput) {
		println(GREEN << "Arguments are already sorted.")
		return (0);
	}
	return (1);
}

int	PmergeMe::dIsSorted(void) {
	std::deque<int> testCpy;
	testCpy = this->dData._unsortedInput;
	sort(testCpy.begin(), testCpy.end());
	if (testCpy == this->dData._unsortedInput) {
		println(GREEN << "Arguments are already sorted.")
		return (0);
	}
	return (1);
}

void	PmergeMe::vInputValidation(int argc, char **argv) {
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
		this->vData._unsortedInput.push_back(temp);
		if (this->vData._unsortedInput[i] < 0)
			throw std::invalid_argument("Negative number found.");
		i++;
	}
	if(!stream.eof())
		throw std::invalid_argument("Not valid type found.");
};

void	PmergeMe::dInputValidation(int argc, char **argv) {
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
		this->dData._unsortedInput.push_back(temp);
		if (this->dData._unsortedInput[i] < 0)
			throw std::invalid_argument("Negative number found.");
		i++;
	}
	if(!stream.eof())
		throw std::invalid_argument("Not valid type found.");
};

void PmergeMe::FJSort(int argc, char **argv) {
	try {
		this->vInputValidation(argc, argv);
		if(!this->vIsSorted())
			return ;
	}
	catch (std::exception& e) {
		errorln(e.what());
	}
	this->vCheckIfIsOdd();
	this->vMakePairs();
	this->vSplitSortedPend();
	this->vInitJacobs();
	this->vCreateInsertionOrder();
	this->vMergePend();
	this->dCheckIfIsOdd();
	this->dMakePairs();
	this->dSplitSortedPend();
	this->dInitJacobs();
	this->dCreateInsertionOrder();
	this->dMergePend();
	this->printLog(argc);
};
