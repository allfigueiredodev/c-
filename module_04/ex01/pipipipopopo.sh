#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 <ClassName>"
    exit 1
fi

CLASS_NAME=$1

BASE_NAME="${CLASS_NAME}"

cpp_content="
#include \"${CLASS_NAME}.hpp\"

${CLASS_NAME}::${CLASS_NAME}(void){
    std::cout << \"${CLASS_NAME} class default constructor called.\" << std::endl;
};

${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& ${CLASS_NAME}){
    std::cout << \"${CLASS_NAME} class copy constructor called.\" << std::endl;
};

${CLASS_NAME}& ${CLASS_NAME}::operator=(const ${CLASS_NAME}& ${CLASS_NAME}){
    std::cout << \"${CLASS_NAME} class copy assign operator called.\" << std::endl;
    return *this;
};

${CLASS_NAME}::~${CLASS_NAME}(void){
    std::cout << \"${CLASS_NAME} class destructor called.\" << std::endl;
};
"

hpp_content="
class ${CLASS_NAME} {

public:
    ${CLASS_NAME}(void);
    ${CLASS_NAME}(const ${CLASS_NAME}& ${CLASS_NAME});
    ${CLASS_NAME}& operator=(const ${CLASS_NAME}& ${CLASS_NAME});
    ~${CLASS_NAME}(void);

};
"

echo "$cpp_content" > "${BASE_NAME}.cpp"

echo "$hpp_content" > "${BASE_NAME}.hpp"

chmod +w "${BASE_NAME}.cpp" "${BASE_NAME}.hpp"
chmod +x "${BASE_NAME}.cpp" "${BASE_NAME}.hpp"
