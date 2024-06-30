
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Serializer.h"
#include "Data.h"

class Serializer {

    private:
        Serializer(void);
        Serializer(const Serializer& Serializer);
        Serializer& operator=(const Serializer& rhs);
        ~Serializer(void);
    
    public:
    	static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif

