#include <iostream>
#include <cstring>
#include <fstream>
#include <limits>

#include "header.h"

void printArrayBook(Book* books, short book_amount) {

    if (book_amount == 0) {
        std::cout << "Library is empty!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    for (size_t i{}; i < book_amount; i++) {
        std::cout << "book #" << i + 1 << '\n';
        std::cout << "\tbook's registration number: " << books[i].registration_number << '\n';
        std::cout << "\tbook's author: " << books[i].author << '\n';
        std::cout << "\tbook's name: " << books[i].name << '\n';
        std::cout << "\tpublication year: " << books[i].publication_year << '\n';
        std::cout << "\tnumber of pages: " << books[i].pages << '\n';

        if (books[i].name_flag == false) {
            std::cout << "\tpublisher location: " << books[i].publisher_info.publisher_location << '\n';
        }
        else {
            std::cout << "\tpublisher name: " << books[i].publisher_info.publisher_name << '\n';
        }

    }

    std::cout << "\npress any key to continue: ";
    char c;
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void searchInBookArray(Book* books, short book_amount) {

    if (book_amount == 0) {
        std::cout << "Library is empty!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "===================================\n"
              << "1. Find by registration number\n"
              << "2. Find by author\n"
              << "3. Find by name\n"
              << "4. Find by published year\n"
              << "5. Find by number of pages\n"
              << "6. Find by publisher name/location \n"
              << "===================================\n";
    std::cout << "Enter submenu option: ";
    int submenu;
    positiveIntNumberInput(submenu);
    if (submenu >= 6) {
        std::cout << "\e[0;31m" << "Wrong input! Tru to input correct one: " << "\e[0m";
        positiveIntNumberInput(submenu);
    }
    std::cout << "\033[2J\033[1;1H";
    switch (submenu) {
        case 1: {
            std::cout << "Enter reg number for searching: ";
            int temp_number;
            positiveIntNumberInput(temp_number);
            for (size_t i{}; i < book_amount; i++) {
                if (temp_number == books[i].registration_number) {
                    std::cout << "book #" << i + 1 << '\n';
                    std::cout << "\tbook's registration number: " << books[i].registration_number << '\n';
                    std::cout << "\tbook's author: " << books[i].author << '\n';
                    std::cout << "\tbook's name: " << books[i].name << '\n';
                    std::cout << "\tpublication year: " << books[i].publication_year << '\n';
                    std::cout << "\tnumber of pages: " << books[i].pages << '\n';

                    if (books[i].name_flag == false) {
                        std::cout << "\tpublisher location: " << books[i].publisher_info.publisher_location << '\n';
                    }
                    else {
                        std::cout << "\tpublisher name: " << books[i].publisher_info.publisher_name << '\n';
                    }
                }
            }
            break;
        }
        case 2: {
            std::cout << "Enter author for searching: ";
            char temp_name[80];
            stringInput(temp_name, 80);
            for (size_t i{}; i < book_amount; i++) {
                if (!std::strcmp(books[i].author, temp_name)) {
                    std::cout << "book #" << i + 1 << '\n';
                    std::cout << "\tbook's registration number: " << books[i].registration_number << '\n';
                    std::cout << "\tbook's author: " << books[i].author << '\n';
                    std::cout << "\tbook's name: " << books[i].name << '\n';
                    std::cout << "\tpublication year: " << books[i].publication_year << '\n';
                    std::cout << "\tnumber of pages: " << books[i].pages << '\n';

                    if (books[i].name_flag == false) {
                        std::cout << "\tpublisher location: " << books[i].publisher_info.publisher_location << '\n';
                    }
                    else {
                        std::cout << "\tpublisher name: " << books[i].publisher_info.publisher_name << '\n';
                    }
                }
            }
            break;
        }
        case 3: {
            std::cout << "Enter name for searching: ";
            char temp_name[80];
            stringInput(temp_name, 80);
            for (size_t i{}; i < book_amount; i++) {
                if (!std::strcmp(books[i].name, temp_name)) {
                    std::cout << "book #" << i + 1 << '\n';
                    std::cout << "\tbook's registration number: " << books[i].registration_number << '\n';
                    std::cout << "\tbook's author: " << books[i].author << '\n';
                    std::cout << "\tbook's name: " << books[i].name << '\n';
                    std::cout << "\tpublication year: " << books[i].publication_year << '\n';
                    std::cout << "\tnumber of pages: " << books[i].pages << '\n';

                    if (books[i].name_flag == false) {
                        std::cout << "\tpublisher location: " << books[i].publisher_info.publisher_location << '\n';
                    }
                    else {
                        std::cout << "\tpublisher name: " << books[i].publisher_info.publisher_name << '\n';
                    }
                }
            }
            break;
        }
        case 4: {            
            std::cout << "Enter publication year for searching: ";
            int temp_number;
            positiveIntNumberInput(temp_number);
            for (size_t i{}; i < book_amount; i++) {
                if (temp_number == books[i].publication_year) {
                    std::cout << "book #" << i + 1 << '\n';
                    std::cout << "\tbook's registration number: " << books[i].registration_number << '\n';
                    std::cout << "\tbook's author: " << books[i].author << '\n';
                    std::cout << "\tbook's name: " << books[i].name << '\n';
                    std::cout << "\tpublication year: " << books[i].publication_year << '\n';
                    std::cout << "\tnumber of pages: " << books[i].pages << '\n';

                    if (books[i].name_flag == false) {
                        std::cout << "\tpublisher location: " << books[i].publisher_info.publisher_location << '\n';
                    }
                    else {
                        std::cout << "\tpublisher name: " << books[i].publisher_info.publisher_name << '\n';
                    }
                }
            }
            break;
        }
        case 5: {            
            std::cout << "Enter number of pages for searching: ";
            int temp_number;
            positiveIntNumberInput(temp_number);
            for (size_t i{}; i < book_amount; i++) {
                if (temp_number == books[i].pages) {
                    std::cout << "book #" << i + 1 << '\n';
                    std::cout << "\tbook's registration number: " << books[i].registration_number << '\n';
                    std::cout << "\tbook's author: " << books[i].author << '\n';
                    std::cout << "\tbook's name: " << books[i].name << '\n';
                    std::cout << "\tpublication year: " << books[i].publication_year << '\n';
                    std::cout << "\tnumber of pages: " << books[i].pages << '\n';

                    if (books[i].name_flag == false) {
                        std::cout << "\tpublisher location: " << books[i].publisher_info.publisher_location << '\n';
                    }
                    else {
                        std::cout << "\tpublisher name: " << books[i].publisher_info.publisher_name << '\n';
                    }
                }
            }
            break;
        }
        case 6: {
            std::cout << "Choose how do u want to search (1 - name, 2 - location): ";
            int submenu;
            positiveIntNumberInput(submenu);
            if (submenu >= 3) {
                std::cout << "\e[0;31m" << "Wrong input! Tru to input correct one: " << "\e[0m";
                positiveIntNumberInput(submenu);
            }
            switch (submenu) {
                case 1: {
                    std::cout << "Enter publisher name for searching: ";
                    char temp_name[80];
                    stringInput(temp_name, 80);
                    for (size_t i{}; i < book_amount; i++) {
                        if (!std::strcmp(books[i].publisher_info.publisher_name, temp_name) and books[i].name_flag == true) {
                            std::cout << "book #" << i + 1 << '\n';
                            std::cout << "\tbook's registration number: " << books[i].registration_number << '\n';
                            std::cout << "\tbook's author: " << books[i].author << '\n';
                            std::cout << "\tbook's name: " << books[i].name << '\n';
                            std::cout << "\tpublication year: " << books[i].publication_year << '\n';
                            std::cout << "\tnumber of pages: " << books[i].pages << '\n';

                            if (books[i].name_flag == false) {
                                std::cout << "\tpublisher location: " << books[i].publisher_info.publisher_location << '\n';
                            }
                            else {
                                std::cout << "\tpublisher name: " << books[i].publisher_info.publisher_name << '\n';
                            }
                        }
                    }
                    break;
                }
                case 2: {
                    std::cout << "Enter publicher location for searching: ";
                    char temp_name[80];
                    stringInput(temp_name, 80);
                    for (size_t i{}; i < book_amount; i++) {
                        if (!std::strcmp(books[i].publisher_info.publisher_location, temp_name) and books[i].name_flag == false) {
                            std::cout << "book #" << i + 1 << '\n';
                            std::cout << "\tbook's registration number: " << books[i].registration_number << '\n';
                            std::cout << "\tbook's author: " << books[i].author << '\n';
                            std::cout << "\tbook's name: " << books[i].name << '\n';
                            std::cout << "\tpublication year: " << books[i].publication_year << '\n';
                            std::cout << "\tnumber of pages: " << books[i].pages << '\n';

                            if (books[i].name_flag == false) {
                                std::cout << "\tpublisher location: " << books[i].publisher_info.publisher_location << '\n';
                            }
                            else {
                                std::cout << "\tpublisher name: " << books[i].publisher_info.publisher_name << '\n';
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
    std::cout << "\npress any key to continue: ";
    char c;
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void shekerSortForNumber(Book* books, short book_amount) {

    if (book_amount == 0) {
        std::cout << "Library is empty!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    short left = 0;
    short right = book_amount - 1;
    Book temp;
    short flag = 1;

    while(left < right) {
        flag = 0;
        for (short i{left}; i < right; i++) {
            if (books[i].registration_number > books[i + 1].registration_number) {
                temp = books[i];
                books[i] = books[i + 1];
                books[i + 1] = temp;
                flag = 1;
            }
        }
        right--;

        for (short i{right}; i > left; i--) {
            if (books[i - 1].registration_number > books[i].registration_number) {
                temp = books[i];
                books[i] = books[i - 1];
                books[i - 1] = temp;
                flag = 1;
            }
        }
        left++;

        if (!flag) {
            break;
        }
    }

    std::cout << "Succesfully sorted!\n";

    std::cout << "\npress any key to continue: ";
    char c;
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void sortedListOfBooks(Book* books, short book_amount) {

    if (book_amount == 0) {
        std::cout << "Library is empty!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    Book* temp_books = new Book[book_amount];
    for (size_t i{}; i < book_amount; i++) {
        temp_books[i] = books[i];
    }

    short left = 0;
    short right = book_amount - 1;
    Book temp;
    short flag = 1;

    while(left < right) {
        flag = 0;
        for (short i{left}; i < right; i++) {
            if (temp_books[i].name[0] > temp_books[i + 1].name[0]) {
                temp = temp_books[i];
                temp_books[i] = temp_books[i + 1];
                temp_books[i + 1] = temp;
                flag = 1;
            }
        }
        right--;

        for (short i{right}; i > left; i--) {
            if (temp_books[i - 1].name[0] > temp_books[i].name[0]) {
                temp = temp_books[i];
                temp_books[i] = temp_books[i - 1];
                temp_books[i - 1] = temp;
                flag = 1;
            }
        }
        left++;

        if (!flag) {
            break;
        }
    }

    std::cout << "Enter publication year for searching: ";
    int temp_number;
    positiveIntNumberInput(temp_number);
    for (size_t i{}; i < book_amount; i++) {
        if (temp_number <= temp_books[i].publication_year) {
            std::cout << "book #" << i + 1 << '\n';
            std::cout << "\tbook's registration number: " << temp_books[i].registration_number << '\n';
            std::cout << "\tbook's author: " << temp_books[i].author << '\n';
            std::cout << "\tbook's name: " << temp_books[i].name << '\n';
            std::cout << "\tpublication year: " << temp_books[i].publication_year << '\n';
            std::cout << "\tnumber of pages: " << temp_books[i].pages << '\n';

            if (temp_books[i].name_flag == false) {
                std::cout << "\tpublisher location: " << temp_books[i].publisher_info.publisher_location << '\n';
            }
            else {
                std::cout << "\tpublisher name: " << temp_books[i].publisher_info.publisher_name << '\n';
            }
        }
    }

    std::cout << "\npress any key to continue: ";
    char c;
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    delete[] temp_books;
    temp_books = nullptr;
}