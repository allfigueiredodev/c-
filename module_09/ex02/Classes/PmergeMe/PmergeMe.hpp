/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:46:26 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/19 21:46:29 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include <deque>
#include <utility>
#include <ctime>
#include <iomanip>

typedef std::vector<int>::iterator vIt;
typedef std::vector<std::pair<int, int> > vIntPair;
typedef std::vector<std::pair<int, int> >::iterator vIntPairIter;
typedef std::deque<int>::iterator dIt;
typedef std::deque<std::pair<int, int> > dIntPair;
typedef std::deque<std::pair<int, int> >::iterator dIntPairIter;

#define println(x) std::cout << x << DFT << std::endl;
#define errorln(x) std::cerr << RED << x << DFT << std::endl;

#define RED     	"\033[1;31m"
#define GREEN   	"\033[1;32m"
#define CYAN    	"\033[1;36m"
#define ORANGE		"\033[0;38;5;166m"
#define DFT   		"\033[0m"

template <typename T>
struct data {
	T				_unsortedInput;
	T				_sorted;
	T				_pend;
	T				_jacobsSequence;
	T				_insertionOrder;
	std::clock_t	_startTime;
	std::clock_t	_endTime;
	int				_theOddOne;
};

class PmergeMe {

    public:
        PmergeMe(void);
        ~PmergeMe(void);
		void	FJSort(int argc, char** argv);

    private:
        PmergeMe(const PmergeMe& PmergeMe);
        PmergeMe& operator=(const PmergeMe& rhs);
		data<std::vector<int> >			vData;
		data<std::deque<int> >			dData;
		vIntPair						_unsortedVPairInput;
		dIntPair						_unsortedDPairInput;

		void				vInputValidation(int argc, char** argv);
		void				dInputValidation(int argc, char** argv);
		int					vIsSorted(void);
		int					dIsSorted(void);
		void				vCheckIfIsOdd(void);
		void				dCheckIfIsOdd(void);
		void				vMakePairs(void);
		void				dMakePairs(void);
		void				vSplitSortedPend(void);
		void				dSplitSortedPend(void);
		void				vInitJacobs(void);
		void				dInitJacobs(void);
		void				vCreateInsertionOrder(void);
		void				dCreateInsertionOrder(void);
		void				vMergePend(void);
		void				dMergePend(void);
		void				printLog(int argc);
};

#endif

