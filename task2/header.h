#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <limits>


typedef union {
    char publisher_name[80];
    char publisher_location[80];
} Publisher;

typedef struct {
    int registration_number;
    char author[80];
    char name[80];
    int publication_year;
    int pages;
    Publisher publisher_info;
    bool name_flag;
} Book;

//memory functions
void allocateOneMoreStructure(Book*& books, short size);

//management - enter functions
void stringInput(char* string, int size);
void positiveIntNumberInput(int& number);
Book* enterNewArrayBook(int array_size);
Book* enterNewArrayBookWhile(short& book_amount);
Book* enterNewArrayBookDialogue(short& book_amount);
void addNewBookToArray(Book* books, short& book_amount);
void editBook(Book* books, short book_amount);
void deleteBook(Book* books, short& book_amount);

//management - output functions
void printArrayBook(Book* books, short book_amount);
void searchInBookArray(Book* books, short book_amount);
void shekerSortForNumber(Book* books, short book_amount);
void sortedListOfBooks(Book* books, short book_amount);

//management - txt functions
void writeToTxtFile(const char* filename, Book* books, short book_amount);
void editTxt(const char* filename, Book* books, short book_amount);