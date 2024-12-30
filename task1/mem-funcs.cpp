#include <iostream>
#include "header.h"
#include "struct.h"


void allocateOneMoreStructure(Product*& production, short size) {
    if (size == 0) {
        production = new Product[1];
    }
    else {
        Product* new_production = new Product[size + 1];
        for (size_t i{}; i < size; i++) {
            new_production[i] = production[i];
        }
        delete[] production;
        production = new_production;
    }
}
