#ifndef WRONG_CAT_CLASS_HPP
#define WRONG_CAT_CLASS_HPP

#include "Polymorphism.h"

class WrongCat : public WrongAnimal {

    public:
        WrongCat(void);
        WrongCat(const WrongCat& WrongCat);
        WrongCat& operator=(const WrongCat& WrongCat);
        ~WrongCat(void);
        void makeSound(void) const;
		std::string getType(void) const;

    protected:
		std::string _type;

    };

#endif
