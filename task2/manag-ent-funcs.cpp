#include <iostream>
#include <cstring>
#include <fstream>
#include <limits>

#include "header.h"

void stringInput(char* string, int size) {
    std::cin.getline(string, size);
    while (std::cin.fail()) {
        std::cout << "\e[0;31m" << "Too large name! Try to enter a smaller one: " << "\e[0m";
        std::cin.clear();
        std::cin.ignore();
        std::cin.getline(string, size);
    }
}

void positiveIntNumberInput(int& number) {
    while (true) {
        std::cin >> number;
        if (std::cin.fail() or number < 0 or std::cin.peek() != '\n') {
            std::cout << "\e[0;31m" << "Wrong input! Tru to input correct one: " << "\e[0m";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
}

Book* enterNewArrayBook(int array_size) {

    Book* books = new Book[array_size];

    for (size_t i{}; i < array_size; i++) {

        std::cout << "Enter information about book #" << i + 1 << '\n';

        std::cout << "\tregistration number: ";
        positiveIntNumberInput(books[i].registration_number);

        std::cout << "\tauthor: ";
        stringInput(books[i].author, 80);

        std::cout << "\tbook name: ";
        stringInput(books[i].name, 80);

        std::cout << "\tpublication year: ";
        positiveIntNumberInput(books[i].publication_year);

        std::cout << "\tnumber of pages: ";
        positiveIntNumberInput(books[i].pages);

        std::cout << "\e[0;33m" << "    name or location of publisher (1 - name, 2 - loc): " << "\e[0m";
        while (true) {
            char c;
            std::cin >> c;
            if (std::cin.fail() || (c != '1' && c != '2')) {
                std::cout << "\e[0;31m" << "Wrong input! Try to input correct one: " << "\e[0m";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (c == '1') {
                books[i].name_flag = true;
                std::cout << "\tname of publisher: ";
                stringInput(books[i].publisher_info.publisher_name, 80);
                break;
            } else if (c == '2') {
                books[i].name_flag = false;
                std::cout << "\tlocation of publisher: ";
                stringInput(books[i].publisher_info.publisher_location, 80);
                break;
            }
        }
    }

    return books;
}

Book* enterNewArrayBookWhile(short& book_amount) {

    Book* books = new Book[1];
    short counter = 0;
    const char* bword = "break";

    for (;;) {
        std::cout << "Enter information about book #" << counter + 1 << '\n';

        std::cout << "\tregistration number: ";
        positiveIntNumberInput(books[counter].registration_number);

        if (books[counter].registration_number == 0) {
            break;
        }

        std::cout << "\tauthor: ";
        stringInput(books[counter].author, 80);

        std::cout << "\tbook name: ";
        stringInput(books[counter].name, 80);

        std::cout << "\tpublication year: ";
        positiveIntNumberInput(books[counter].publication_year);

        std::cout << "\tnumber of pages: ";
        positiveIntNumberInput(books[counter].pages);

        std::cout << "\e[0;33m" << "    name or location of publisher (1 - name, 2 - loc): " << "\e[0m";
        while (true) {
            char c;
            std::cin >> c;
            if (std::cin.fail() || (c != '1' && c != '2')) {
                std::cout << "\e[0;31m" << "Wrong input! Try to input correct one: " << "\e[0m";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (c == '1') {
                books[counter].name_flag = true;
                std::cout << "\tname of publisher: ";
                stringInput(books[counter].publisher_info.publisher_name, 80);
                break;
            } else if (c == '2') {
                books[counter].name_flag = false;
                std::cout << "\tlocation of publisher: ";
                stringInput(books[counter].publisher_info.publisher_location, 80);
                break;
            }
        }
        counter++;
        allocateOneMoreStructure(books, counter);
    }
    std::cout << counter;
    Book* final_books = new Book[counter];

    for (size_t i{}; i < counter; i++) {
        final_books[i] = books[i];
    }

    delete[] books;

    book_amount = counter;
    return final_books;
}

Book* enterNewArrayBookDialogue(short& book_amount) {

    Book* books = new Book[1];
    short counter = 0;
    while (true) {

        std::cout << "Enter information about book #" << counter + 1 << '\n';

        std::cout << "\tregistration number: ";
        positiveIntNumberInput(books[counter].registration_number);

        std::cout << "\tauthor: ";
        stringInput(books[counter].author, 80);

        std::cout << "\tbook name: ";
        stringInput(books[counter].name, 80);

        std::cout << "\tpublication year: ";
        positiveIntNumberInput(books[counter].publication_year);

        std::cout << "\tnumber of pages: ";
        positiveIntNumberInput(books[counter].pages);

        std::cout << "\e[0;33m" << "    name or location of publisher (1 - name, 2 - loc): " << "\e[0m";
        while (true) {
            char c;
            std::cin >> c;
            if (std::cin.fail() || (c != '1' && c != '2')) {
                std::cout << "\e[0;31m" << "Wrong input! Try to input correct one: " << "\e[0m";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (c == '1') {
                books[counter].name_flag = true;
                std::cout << "\tname of publisher: ";
                stringInput(books[counter].publisher_info.publisher_name, 80);
                break;
            } else if (c == '2') {
                books[counter].name_flag = false;
                std::cout << "\tlocation of publisher: ";
                stringInput(books[counter].publisher_info.publisher_location, 80);
                break;
            }
        }

        std::cout << "Wanna continue entering? (y/n): ";
        char c;
        std::cin >> c;
        if (c == 'n') {
            break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        counter++;
        allocateOneMoreStructure(books, counter);
    }

    book_amount = counter + 1;
    return books;
}

void addNewBookToArray(Book* books, short& book_amount) {
    
    std::cout << "add book #" << book_amount + 1 << '\n';

        std::cout << "\tregistration number: ";
        positiveIntNumberInput(books[book_amount].registration_number);

        std::cout << "\tauthor: ";
        stringInput(books[book_amount].author, 80);

        std::cout << "\tbook name: ";
        stringInput(books[book_amount].name, 80);

        std::cout << "\tpublication year: ";
        positiveIntNumberInput(books[book_amount].publication_year);

        std::cout << "\tnumber of pages: ";
        positiveIntNumberInput(books[book_amount].pages);

        std::cout << "\e[0;33m" << "    name or location of publisher (1 - name, 2 - loc): " << "\e[0m";
        while (true) {
            char c;
            std::cin >> c;
            if (std::cin.fail() || (c != '1' && c != '2')) {
                std::cout << "\e[0;31m" << "Wrong input! Try to input correct one: " << "\e[0m";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (c == '1') {
                books[book_amount].name_flag = true;
                std::cout << "\tname of publisher: ";
                stringInput(books[book_amount].publisher_info.publisher_name, 80);
                break;
            } else if (c == '2') {
                books[book_amount].name_flag = false;
                std::cout << "\tlocation of publisher: ";
                stringInput(books[book_amount].publisher_info.publisher_location, 80);
                break;
            }
        }
    book_amount++;
}

void editBook(Book* books, short book_amount) {

    if (book_amount == 0) {
        std::cout << "Library is empty!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Enter name of book you want to edit: ";
    char temp_name[80];
    stringInput(temp_name, 80);
    for (size_t i{}; i < book_amount; i++) {
        if (!std::strcmp(books[i].name, temp_name)) {
            std::cout << "===================================\n"
                    << "1. edit registration number\n"
                    << "2. edit author\n"
                    << "3. edit name\n"
                    << "4. edit publication year\n"
                    << "5. edit number of pages\n"
                    << "6. edit publisher info (name/loc)\n"
                    << "7. stop editing\n"
                    << "===================================\n";
            std::cout << "Enter submenu option: ";
            int submenu;
            positiveIntNumberInput(submenu);
            if (submenu >= 7) {
                std::cout << "\e[0;31m" << "Wrong input! Tru to input correct one: " << "\e[0m";
                positiveIntNumberInput(submenu);
            }
            std::cout << "\033[2J\033[1;1H";
            switch (submenu) {
                case 1: {
                    std::cout << "Enter new reg number: ";
                    int temp_number;
                    positiveIntNumberInput(temp_number);
                    books[i].registration_number = temp_number;
                    break;
                }
                case 2: {
                    std::cout << "Enter new author: ";
                    char temp_name[80];
                    stringInput(temp_name, 80);
                    std::strcpy(books[i].author, temp_name);
                    break;
                }
                case 3: {
                    std::cout << "Enter new name: ";
                    char temp_name[80];
                    stringInput(temp_name, 80);
                    std::strcpy(books[i].name, temp_name);
                    break;
                }
                case 4: {
                    std::cout << "Enter new publication year: ";
                    int temp_number;
                    positiveIntNumberInput(temp_number);
                    books[i].publication_year = temp_number;
                    break;
                }
                case 5: {
                    std::cout << "Enter new number of pages: ";
                    int temp_number;
                    positiveIntNumberInput(temp_number);
                    books[i].pages = temp_number;
                    break;
                }
                case 6: {
                    std::cout << "Choose what do u want to edit (1 - name, 2 - location): ";
                    int submenu;
                    positiveIntNumberInput(submenu);
                    if (submenu >= 3) {
                        std::cout << "\e[0;31m" << "Wrong input! Tru to input correct one: " << "\e[0m";
                        positiveIntNumberInput(submenu);
                    }
                    switch (submenu) {
                        case 1: {
                            std::cout << "Enter new publisher name: ";
                            char temp_name[80];
                            stringInput(temp_name, 80);
                            std::strcpy(books[i].publisher_info.publisher_name, temp_name);
                            books[i].name_flag = true;
                            break;
                        }
                        case 2: {
                            std::cout << "Enter new publisher location: ";
                            char temp_name[80];
                            stringInput(temp_name, 80);
                            std::strcpy(books[i].publisher_info.publisher_location, temp_name);
                            books[i].name_flag = false;
                            break;
                        }
                    }
                }
                case 7: {
                    break;
                }
                break;
            }  
        }
    }
}

void deleteBook(Book* books, short& book_amount) {

    if (book_amount == 0) {
        std::cout << "Library is empty!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Enter registration number for book you want to delete: ";
    int temp_number;
    positiveIntNumberInput(temp_number);

    bool book_found = false;
    Book* new_books = new Book[book_amount - 1];

    for (short i = 0, counter = 0; i < book_amount; i++) {
        if (temp_number == books[i].registration_number and !book_found) {
            book_found = true;
            continue;
        }
        if (counter < book_amount - 1) {
            new_books[counter++] = books[i];
        }
    }

    for (short i = 0; i < book_amount - 1; i++) {
        books[i] = new_books[i];
    }

    delete[] new_books;
    book_amount--;

    std::cout << "Book has been deleted\n";

    std::cout << "\npress any key to continue: ";
    char c;
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}