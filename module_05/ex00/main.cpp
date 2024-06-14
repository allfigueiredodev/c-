#include "Bureaucrat.h"

void	defaultConstructorTest(void){
	Bureaucrat bZero;
	std::cout << CYAN << "The standard bureaucrat name is: " << bZero.getName()
	<< " and his standard grade is: " << bZero.getGrade() << DFT << std::endl;
}

void	decrementGradeOverLimitTest(void){
	Bureaucrat bOne("bOne", 2);
	bOne.incrementGrade();
	bOne.incrementGrade();
}

void	incrementGradeOverLimitTest(void){
	Bureaucrat bTwo("bTwo", 149);
	bTwo.decrementGrade();
	bTwo.decrementGrade();
}

void	instantiateOverLimitsTest(void){
	Bureaucrat over("OVER", 160); 
	Bureaucrat under("UNDER", 0); 
}

int main(void) {
	defaultConstructorTest();
	decrementGradeOverLimitTest();
	incrementGradeOverLimitTest();
	instantiateOverLimitsTest();
}