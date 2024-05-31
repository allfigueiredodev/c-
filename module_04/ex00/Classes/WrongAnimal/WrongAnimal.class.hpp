#ifndef WRONG_ANIMAL_CLASS_HPP
#define WRONG_ANIMAL_CLASS_HPP

#include "Polymorphism.h"

class WrongAnimal {

    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal& WrongAnimal);
        WrongAnimal& operator=(const WrongAnimal& WrongAnimal);
        ~WrongAnimal(void);
        void makeSound(void) const;
		std::string getType(void) const;

    protected:
		std::string type;

};

#endif
