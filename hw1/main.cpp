#include "lib.h"
#include <iostream>

int main (int, char **) {
    std::cout << "build " << version() << "\n";
    std::cout << "Hello, World!" << "\n";

    return 0;
}
