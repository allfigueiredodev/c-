
#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

class ScalarConverter {

    public:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& ScalarConverter);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        ~ScalarConverter(void);

    static convert(std::string value);

};

#endif

