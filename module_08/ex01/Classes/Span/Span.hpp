
#ifndef SPAN_HPP
#define SPAN_HPP

#include "Span.h"

class Span {

    public:
        
        Span(unsigned int i);
        Span(const Span& Span);
        Span& operator=(const Span& rhs);
        ~Span(void);
        
        void addNumber(unsigned int i);
        int shortestSpan(void);
        int longestSpan(void);
        void addRange(it begin, it end, size_t pos);
        unsigned int getSpanSize(void);
        unsigned int getSpanCapacity(void);
        const int& getIndex(int index) const;
        int& getIndex(int index);
		void printSpan(std::string color);
        std::vector<int> getSpan(void);
        
        const int& operator[](size_t index) const;
        int& operator[](size_t index);

        class OverMaxVectorSizeException : public std::exception {

            public:

                virtual const char* what() const throw(); 
        };

        class NotEnoughElementsToSpanException : public std::exception {

            public:

                virtual const char* what() const throw();
        };

        class RangePosException : public std::exception {

            public:

                virtual const char* what() const throw();
        };
    
    private:
    
        Span(void);
        std::vector<int>    _span;
};

#endif