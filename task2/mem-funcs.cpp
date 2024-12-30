#include <iostream>
#include "struct.h"
#include "header.h"

void allocateOneMoreStructure(Book*& books, short size) {
    if (size == 0) {
        books = new Book[1];
    }
    else {
        Book* new_books = new Book[size + 1];
        for (size_t i{}; i < size; i++) {
            new_books[i] = books[i];
        }
        delete[] books;
        books = new_books;
    }
}