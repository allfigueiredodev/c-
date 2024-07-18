#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <vector>
#include <utility>

typedef std::vector<int>::iterator it;
typedef std::vector<std::pair<int, int> > vIntPair;
typedef std::vector<std::pair<int, int> >::iterator vIntPairIter;

#define println(x) std::cout << x << DFT << std::endl;
#define errorln(x) std::cerr << RED << x << DFT << std::endl;

#define RED     	"\033[1;31m"
#define GREEN   	"\033[1;32m"
#define CYAN    	"\033[1;36m"
#define ORANGE		"\033[0;38;5;166m"
#define DFT   		"\033[0m"

class PmergeMe {

    public:
        PmergeMe(void);
        ~PmergeMe(void);
		void	FJSort(int argc, char** argv);

    private:
        PmergeMe(const PmergeMe& PmergeMe);
        PmergeMe& operator=(const PmergeMe& rhs);
		
		std::vector<int>				_unsortedInput;
		vIntPair						_unsortedPairInput;
		std::vector<int>				_sorted;
		std::vector<int>				_pend;
		std::vector<int>				_jacobsSequence;
		std::vector<int>				_insertionOrder;
		int								_theOddOne;


		void				inputValidation(int argc, char** argv);
		int					isSorted(void);
		void				checkIfIsOdd(void);
		void				makePairs(void);
		void				splitSortedPend(void);
		void				initJacobs(void);
		void				createInsertionOrder(void);
		void				mergePend(void);
};

#endif

