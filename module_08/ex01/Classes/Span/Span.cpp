#include "Span.h"
#include "Classes/Span/Span.hpp"

// CANONICAL CONSTRUCTORS/DESTRUCTOR

Span::Span(void) {
    std::cout << "Span class default constructor called." << std::endl;
};

Span::Span(unsigned int i) {
    std::cout << "Span class parameterized constructor called." << std::endl;
    this->_span.reserve(i);
};

Span::Span(const Span& Span) {
    std::cout << "Span class copy constructor called." << std::endl;
    *this = Span;
};

Span& Span::operator=(const Span& rhs) {
    std::cout << "Span class copy assign operator called." << std::endl;
    if (this != &rhs){
        *this = rhs;
    }
    return *this;
};

Span::~Span(void) {
    std::cout << "Span class destructor called." << std::endl;
};

// CLASS METHODS

void    Span::addNumber(unsigned int i) {
    if (this->_span.size() < this->_span.capacity()) {
        this->_span.push_back(i);
    }
    else
        throw Span::OverMaxVectorSizeException();
};

int    Span::shortestSpan(void) {
    int                         shortest;
    std::vector<int>            spanCpy(this->_span);
    it                          currFirst;

    if (spanCpy.size() <= 1) {
        throw (Span::NotEnoughElementsToSpanException());
        return (0);
    }
    sort(spanCpy.begin(), spanCpy.end());
    currFirst = spanCpy.begin();
    shortest = *next(currFirst) - *currFirst;
    for (size_t i = 0; i < spanCpy.size(); i++) {
        if (i != spanCpy.size() - 1) {
            if (*next(currFirst) - *currFirst < shortest) {
                shortest = *next(currFirst) - *currFirst;
            }
            currFirst = next(currFirst);
        }
    }
    return (shortest);
};

int    Span::longestSpan(void) {
    if (this->_span.size() <= 1) {
        throw (Span::NotEnoughElementsToSpanException());
        return (0);
    }
    return (*max_element(this->_span.begin(), this->_span.end()) -
    *min_element(this->_span.begin(), this->_span.end()));
};

void    Span::addRange(it begin, it end, size_t pos) {
    size_t currentSpace = this->_span.capacity() - this->_span.size();
    size_t range = std::distance(begin, end);
    if (currentSpace - range < 0) {
        throw (Span::OverMaxVectorSizeException());
    }
    else if (range + pos > this->_span.capacity()) {
        throw (Span::RangePosException());
    }
    this->_span.insert(this->_span.begin() + pos, begin, end);
};

unsigned int Span::getSpanSize(void) {
    return (this->_span.size());
};

unsigned int Span::getSpanCapacity(void) {
    return (this->_span.capacity());
};

const int& Span::getIndex(int index) const {
    return (this->_span[index]);
};

int& Span::getIndex(int index) {
	return (this->_span[index]);
};

std::vector<int> Span::getSpan(void) {
    return (this->_span);
};

// EXCEPTIONS

const char* Span::OverMaxVectorSizeException::what() const throw() {
    return ("Span is at the maximum capacity.");
};

const char* Span::NotEnoughElementsToSpanException::what() const throw() {
    return ("Span hasn't enought elements to span with.");
};

const char* Span::RangePosException::what() const throw() {
    return ("There is no space to insert the range from the given position.");
};

// OPERATOR OVERLOADS

const int& Span::operator[](size_t index) const {
	if (index < 0 || (index > 0 && index >= this->_span.capacity())) {
		throw std::out_of_range("Index out of bounds");
	}
	else
		return (this->getIndex(index));
};

int& Span::operator[](size_t index) {
	if (index < 0 || (index > 0 && index >= this->_span.capacity())) {
		throw std::out_of_range("Index out of bounds");
	}
	else
		return (this->getIndex(index));
};
