#include <iostream>
#include "Logic.h"

int main() {
    Logic *l = new Logic("C++ Tut", 3, 3);
    l->read("cTut.txt");
    l->write("test.txt");
    return 0;
}
