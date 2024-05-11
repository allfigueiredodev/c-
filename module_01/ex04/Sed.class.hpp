#ifndef SED_CLASS_HPP
#define SED_CLASS_HPP

#include "Sed.hpp"

class Sed {

	public:

		std::string getStr(int i);
		void setStr(std::string str, int i);
		std::string	changeStr(std::string s1, std::string s2, int arrSize);
		
		Sed(void);
		Sed(int size);
		~Sed(void);


	private:
		
		std::string* _strArr;
};

#endif