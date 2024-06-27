
#ifndef SERIALIZER_H
#define SERIALIZER_H

class Serializer {

    private:
        Serializer(void);
        Serializer(const Serializer& Serializer);
        Serializer& operator=(const Serializer& rhs);
        ~Serializer(void);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif

