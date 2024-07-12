#include "easyfind.h"

template<typename T>
void easyfind(T arr, int element) {
	int arrIndex = 0;
	typename T::iterator status = std::find(arr.begin(), arr.end(), element);
	if (status == arr.end()) {
		throw (std::runtime_error("Element "));
	}
	else {
		for (typename T::iterator it = arr.begin(); it != arr.end(); it++) {
		if (*it == *status) {
			std::cout << GREEN << "index " << arrIndex << " : " << *it << " -> GOT IT!" << std::endl;
		}
		else
			std::cout << BLUE << "index " << arrIndex << " : " << *it << std::endl;
		arrIndex++;
		}
	}
};
