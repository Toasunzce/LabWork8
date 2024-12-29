#include <iostream>
#include <cstring>
#include <fstream>
#include <limits>

#include "header.h"
const char* filename = "/home/toasunzce/Documents/453501/ОАиП/LR8/task2/library.txt";


int main() {

    Book* books = nullptr;
    short book_amount = 0;


    while (true) {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "==========={ MAIN MENU }===========\n"
                  << "1.  Data entering (3 options)\n"
                  << "2.  Data showing\n"
                  << "3.  Adding data to array\n"
                  << "4.  Searching for specific data\n"
                  << "5.  Editing data elements\n"
                  << "6.  Delete books\n"
                  << "7.  Sort data (by reg. number)\n"
                  << "8.  List of books by selected year\n"
                  << "9.  Write to txt file\n"
                  << "10. Edit txt file\n"
                  << "11. Exit\n"
                  << "current amount of books: " << book_amount << '\n'
                  << "===================================\n";

        std::cout << "Enter menu option: ";
        int menu;
        positiveIntNumberInput(menu);
        if (menu >= 13) {
            std::cout << "\e[0;31m" << "Wrong input! Tru to input correct one: " << "\e[0m";
            positiveIntNumberInput(menu);
        }
        std::cout << "\033[2J\033[1;1H";

        switch (menu) {
            case 1: {
                std::cout << "===================================\n"
                          << "1. Entering number of books\n"
                          << "2. Entering books till 0-reg. number\n"
                          << "3. Dialogue-like data entering\n"
                          << "4. Back to menu\n"
                          << "===================================\n";
                std::cout << "Enter submenu option: ";
                int submenu;
                positiveIntNumberInput(submenu);
                if (submenu >= 5) {
                    std::cout << "\e[0;31m" << "Wrong input! Tru to input correct one: " << "\e[0m";
                    positiveIntNumberInput(submenu);
                }

                std::cout << "\033[2J\033[1;1H";
                switch (submenu) {
                    case 1: {
                        std::cout << "\033[2J\033[1;1H";
                        std::cout << "Enter amount of books: ";
                        int array_size;
                        positiveIntNumberInput(array_size);
                        std::cout << '\n';
                        books = enterNewArrayBook(array_size);
                        book_amount = array_size;
                        std::cout << "\033[2J\033[1;1H";
                        break;

                    }
                    case 2: {
                        std::cout << "\033[2J\033[1;1H";
                        books = enterNewArrayBookWhile(book_amount);
                        std::cout << "\033[2J\033[1;1H";
                        break;

                    }
                    case 3: {
                        std::cout << "\033[2J\033[1;1H";
                        books = enterNewArrayBookDialogue(book_amount);
                        std::cout << "\033[2J\033[1;1H";
                        break;
                    }
                    case 4: {
                        std::cout << "\033[2J\033[1;1H";
                        break;
                    }
                    break;
                }
                break;
                
            }
            case 2: {
                std::cout << "\033[2J\033[1;1H";
                printArrayBook(books, book_amount);
                std::cout << "\033[2J\033[1;1H";
                break;
            }
            case 3: {
                std::cout << "\033[2J\033[1;1H";
                allocateOneMoreStructure(books, book_amount);
                addNewBookToArray(books, book_amount);
                std::cout << "\033[2J\033[1;1H";
                break;
            }
            case 4: {
                std::cout << "\033[2J\033[1;1H";
                searchInBookArray(books, book_amount);
                std::cout << "\033[2J\033[1;1H";
                break;
            }
            case 5: {
                std::cout << "\033[2J\033[1;1H";
                editBook(books, book_amount);
                std::cout << "\033[2J\033[1;1H";
                break;
            }
            case 6: {
                std::cout << "\033[2J\033[1;1H";
                deleteBook(books, book_amount);
                std::cout << "\033[2J\033[1;1H";
                break;
            }
            case 7: {
                std::cout << "\033[2J\033[1;1H";
                shekerSortForNumber(books, book_amount);
                std::cout << "\033[2J\033[1;1H";
                break;
            }
            case 8: {
                std::cout << "\033[2J\033[1;1H";
                sortedListOfBooks(books, book_amount);
                std::cout << "\033[2J\033[1;1H";
                break;
            }
            case 9: {
                std::cout << "\033[2J\033[1;1H";
                writeToTxtFile(filename, books, book_amount);
                std::cout << "\033[2J\033[1;1H";
                break;
            }
            case 10: {
                std::cout << "\033[2J\033[1;1H";
                editTxt(filename, books, book_amount);
                std::cout << "\033[2J\033[1;1H";
                break;    
            }
            case 11: {
                delete[] books;
                books = nullptr;
                return 0;
            }
        }
    }
    
    delete[] books;
    books = nullptr;

    return 0;


    delete[] books;
    return 0;
}