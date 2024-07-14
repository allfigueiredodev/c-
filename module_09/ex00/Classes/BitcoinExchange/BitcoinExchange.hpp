
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

        // void                            _processOutput(std::string key, double value);

        class   FilePathNotFoundException : std::exception {
            public:
                virtual const char* what() const throw();
        };
        
};

#endif