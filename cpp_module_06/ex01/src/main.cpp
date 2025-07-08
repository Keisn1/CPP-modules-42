#include "Data.h"
#include "Serializer.h"
#include <iostream>

int main() {
    Data d1 = {12, 12.3, "hello"};

    Data d2 = *Serializer::deserialize(Serializer::serialize(&d1));

    std::cout << "address of d1" << &d1 << std::endl;
    std::cout << "address of d2" << &d2 << std::endl;

    if (d1.nbr != d2.nbr) {
        std::cout << "failed on d.nbr" << std::endl;
    }
    if (d1.flt != d2.flt) {
        std::cout << "failed on d.str" << std::endl;
    }
    if (d1.str != d2.str) {
        std::cout << "failed on d.str" << std::endl;
    }

    std::cout << "worked" << std::endl;
    return 0;
}
