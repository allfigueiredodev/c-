#include "array.h"
#include "Classes/Array/Array.hpp"

template<typename T>
Array<T>::Array(void) : _size(0) {
	std::cout << "Array class default constructor called." << std::endl;
	_arr = new T[0]();
};

template<typename T>
Array<T>::Array(unsigned int size) : _size(size) {
	std::cout << "Array class parameterized constructor called." << std::endl;
	_arr = new T[size]();
};

template<typename T>
Array<T>::Array(const Array& rhs){
	*this = rhs;
};

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs){
	if (this != &rhs) {
		this->_size = rhs._size;
		_arr = new T[_size];
		for (size_t i = 0; i < _size; i++){
			this->_arr[i] = rhs._arr[i];
		}
	}
	return (*this);
};

template<typename T>
Array<T>::~Array(void) {
	std::cout << "Array class destructor called." << std::endl;
	delete[] this->_arr;
};

template<typename T>
size_t Array<T>::size(void) const {
	return (this->_size);
};

template<typename T>
T& Array<T>::getIndex(int index) const {
	return (this->_arr[index]);
};

template<typename T>
void Array<T>::fillArrIndex(T data, int index) {
	this->_arr[index] = data;
};

template<typename T>
const T& Array<T>::operator[](size_t index) const {
	if (index < 0 || (index > 0 && index >= this->_size)) {
		throw std::out_of_range("Index out of bounds");
	}
	else
		return (this->getIndex(index));
};

template<typename T>
T& Array<T>::operator[](size_t index) {
	if (index < 0 || (index > 0 && index >= this->_size)) {
		throw std::out_of_range("Index out of bounds");
	}
	else
		return (this->getIndex(index));
};

template<typename T>
void Array<T>::addBack(T data) {
	T* newArr = new T[this->_size + 1];
	for (size_t i = 0; i <= this->_size; i++) {
		if (i < this->_size){
			newArr[i] = this->_arr[i];
		}
		else if (i == this->_size){
			newArr[i] = data;
		}
	}
	this->_size = _size + 1;
	delete[] this->_arr;
	this->_arr = newArr;
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const Array<T>& data) {
	o << &data;
	return (o);
};