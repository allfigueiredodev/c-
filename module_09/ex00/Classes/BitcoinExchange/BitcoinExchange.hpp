/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:00:30 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/19 22:00:33 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "BitcoinExchange.h"

class BitcoinExchange {

    public:
        BitcoinExchange(void);
        ~BitcoinExchange(void);
        void    runExchange(char* inputPath);
    
    private:
        BitcoinExchange(const BitcoinExchange& BitcoinExchange);
        BitcoinExchange& operator=(const BitcoinExchange& rhs);
        
        std::map<std::string, double>   _btcDb;
        std::ifstream                   _inputFile;

        void                            _inputValidator(char* inputPath);
        void                            _initDb(void);
        void                            _inputExecutor(void);
        void                            _formatChecker(std::string line);
        void                            _timestampChecker(std::string line);
        void                            _validateAmount(std::string line);
        void                            _findNearMatch(std::string line);

        class   FilePathNotFoundException : std::exception {
            public:
                virtual const char* what() const throw();
        };
        
};

#endif