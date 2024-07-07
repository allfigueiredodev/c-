#include "easyfind.h"

template<typename T>
void easyfind(T arr, int element) {
	typename T::iterator status = std::find(arr.begin(), arr.end(), element);
	if (status == arr.end()) {
		throw (std::runtime_error("Element "));
	}
	else {
		for (unsigned long i = 0; i < arr.size(); i++) {
		arr[i] = i * i;
		if (arr[i] == *status) {
			std::cout << GREEN << "index " << i << " : " << arr[i] << " -> GOT IT!" << std::endl;
		}
		else
			std::cout << BLUE << "index " << i << " : " << arr[i] << std::endl;
		}
	}
};
