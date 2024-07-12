#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 <ClassName>"
    exit 1
fi

CLASS_NAME=$1

if [ ! -d "Classes" ]; then
    mkdir Classes
fi

mkdir -p Classes/${CLASS_NAME}

BASE_NAME="${CLASS_NAME}"
UPPER_CASE_CLASS_NAME=$(echo "$CLASS_NAME" | tr '[:lower:]' '[:upper:]' | sed 's/$/_H/')

cpp_content="
#include \"${CLASS_NAME}.hpp\"

${CLASS_NAME}::${CLASS_NAME}(void) {
    std::cout << \"${CLASS_NAME} class default constructor called.\" << std::endl;
};

${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& ${CLASS_NAME}) {
    std::cout << \"${CLASS_NAME} class copy constructor called.\" << std::endl;
    *this = ${CLASS_NAME};
};

${CLASS_NAME}& ${CLASS_NAME}::operator=(const ${CLASS_NAME}& rhs) {
    std::cout << \"${CLASS_NAME} class copy assign operator called.\" << std::endl;
    if (this != &rhs){
        //...
    }
    return *this;
};

${CLASS_NAME}::~${CLASS_NAME}(void) {
    std::cout << \"${CLASS_NAME} class destructor called.\" << std::endl;
};
"

hpp_content="
#ifndef ${UPPER_CASE_CLASS_NAME}
#define ${UPPER_CASE_CLASS_NAME}

class ${CLASS_NAME} {

    public:
        ${CLASS_NAME}(void);
        ${CLASS_NAME}(const ${CLASS_NAME}& ${CLASS_NAME});
        ${CLASS_NAME}& operator=(const ${CLASS_NAME}& rhs);
        ~${CLASS_NAME}(void);

};

#endif
"

echo "$cpp_content" > "Classes/${CLASS_NAME}/${BASE_NAME}.cpp"

echo "$hpp_content" > "Classes/${CLASS_NAME}/${BASE_NAME}.hpp"

chmod +w "Classes/${CLASS_NAME}/${BASE_NAME}.cpp" "Classes/${CLASS_NAME}/${BASE_NAME}.hpp"
chmod +x "Classes/${CLASS_NAME}/${BASE_NAME}.cpp" "Classes/${CLASS_NAME}/${BASE_NAME}.hpp"
