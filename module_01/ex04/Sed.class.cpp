#include "Sed.hpp"
#include "Sed.class.hpp"


Sed::Sed(void) {};

Sed::Sed(int size){
	_strArr = new std::string[size];	
};

Sed::~Sed(void) {
	delete[] _strArr;
};

std::string Sed::getStr(int i){
	return (this->_strArr[i]);
};

void Sed::setStr(std::string str, int i){
	this->_strArr[i] = str;
};

std::string	Sed::changeStr(std::string s1, std::string s2, int arrSize){
	std::string temp;
	size_t		pos;

	for (int i = 0; i < arrSize; i++){
		temp = getStr(i);
		pos = 0;
		while ((pos = (pos == 0 ? temp.find(s1) : temp.find(s1, pos))) != std::string::npos){
			temp.erase(pos, s1.length());
			temp.insert(pos, s2);
			pos += pos;
		}
		setStr(temp, i);
	}
	return (temp);
};
