#pragma once
#include "struct.h"


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