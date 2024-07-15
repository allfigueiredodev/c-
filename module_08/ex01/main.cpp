#include "Span.h"
#include "Classes/Span/Span.hpp"

std::vector<int> smallVector;
std::vector<int> mediumVector;
std::vector<int> largeVector;

void GlobalVectorsInit(void) {
	int small = 5;
	int medium = 25;
	int large = 50;
	
	smallVector.reserve(small);
	mediumVector.reserve(medium);
	largeVector.reserve(large);
	for (int i = 0; i < small; i++) {
		smallVector.push_back(rand() % 100);
		std::cout << GREEN << "'" << smallVector[i] << "' ,";
	}
	println(" ");
	for (int i = 0; i < medium; i++) {
		mediumVector.push_back(rand() % 100);
		std::cout << YELLOW << "'" << mediumVector[i] << "' ,";
	}
	println(" ");
	for (int i = 0; i < large; i++) {
		largeVector.push_back(rand() %  100);
		std::cout << RED << "'" << largeVector[i] << "' ,";
	}
	println(" ");
}

void	AddingElementOverTheCapacityTest(void) {
	Span sp(5);
	try {
		sp.addRange(smallVector.begin(), smallVector.end(), 0);
		sp.addNumber(42);
	}
	catch (Span::OverMaxVectorSizeException& e) {
		errorln(e.what());
	}
}

void	AddNumberMethodTest(void) {
	Span sp(3);

	println(GREEN << "Size before addition: " << sp.getSpanSize());
	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);
	println(GREEN << "Size after addition: " << sp.getSpanSize());
	sp.printSpan(YELLOW);
	std::cout << DFT << std::endl;
}

void	ShortestSpanMethodTest(void) {
	Span sp(smallVector.size());

	sp.addRange(smallVector.begin(), smallVector.end(), 0);
	println(GREEN << "Vector to be tested: ");
	sp.printSpan(YELLOW);
	std::cout << DFT << std::endl;
	println(BLUE << "Shortest span: ");
	println(GREEN << sp.shortestSpan());
};

void	LongestSpanMethodTest(void) {
	Span sp(smallVector.size());

	sp.addRange(smallVector.begin(), smallVector.end(), 0);
	println(GREEN << "Vector to be tested: ");
	sp.printSpan(YELLOW);
	std::cout << DFT << std::endl;
	println(BLUE << "Longest span: ");
	println(GREEN << sp.longestSpan());
};

void	AddRangeMethodTest(void) {
	Span spSmall(smallVector.size());
	Span spMedium(mediumVector.size());
	Span spLarge(largeVector.size());

	spSmall.addRange(smallVector.begin(), smallVector.end(), 0);
	spMedium.addRange(mediumVector.begin(), mediumVector.end(), 0);
	spLarge.addRange(largeVector.begin(), largeVector.end(), 0);

	println(MAGENTA << "Small vector: ");
	spSmall.printSpan(GREEN);
	std::cout << DFT << std::endl;
	println(MAGENTA << "Medium vector: ");
	spMedium.printSpan(YELLOW);
	std::cout << DFT << std::endl;
	println(MAGENTA << "Large vector: ");
	spLarge.printSpan(RED);
	std::cout << DFT << std::endl;
};

void	SubjectTest(void) {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
};

int main()
{
	println(CYAN << "***TESTS***");
	println(" ");
	println(CYAN << "***Creating Test Vectors***");
	println(" ");
	GlobalVectorsInit();
	println(" ");
	println(CYAN << "***Adding Element Over The Capacity Test***");
	println(" ");
	AddingElementOverTheCapacityTest();
	println(" ");
	println(CYAN << "***Add Number Method Test***");
	println(" ");
	AddNumberMethodTest();
	println(" ");
	println(CYAN << "***Shortest Span Method Test***");
	println(" ");
	ShortestSpanMethodTest();
	println(" ");
	println(CYAN << "***Longest Span Method Test***");
	println(" ");
	LongestSpanMethodTest();
	println(" ");
	println(CYAN << "***Add Range Method Test***");
	println(" ");
	AddRangeMethodTest();
	println(" ");
	println(CYAN << "***Subject Test***");
	println(" ");
	SubjectTest();
}