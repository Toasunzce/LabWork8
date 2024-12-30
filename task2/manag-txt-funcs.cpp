#include <iostream>
#include <fstream>
#include <limits>
#include <cstring>
#include "header.h"
#include "struct.h"


void writeToTxtFile(const char* filename, Book* books, short book_amount) {

    if (book_amount == 0) {
        std::cout << "Library is empty!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::ofstream file(filename, std::ios::out);
    if (!file) {
        std::cerr << "Error opening file!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    
    for (size_t i{}; i < book_amount; i++) {
        file << books[i].registration_number << '\n';
        file << books[i].author << '\n';
        file << books[i].name << '\n';
        file << books[i].publication_year << '\n';
        file << books[i].pages << '\n';
        if (books[i].name_flag == 1) {
            file << books[i].publisher_info.publisher_name << '\n';
        }
        else {
            file << books[i].publisher_info.publisher_location << '\n';
        }
    }

    file.close();

    std::cout << "Data has been writted!\n";

    std::cout << "\npress any key to continue: ";
    char c;
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void editTxt(const char* filename, Book* books, short book_amount) {

    if (book_amount == 0) {
        std::cout << "You need to enter data first!!\n";
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

    std::ofstream file(filename, std::ios::out);
    if (!file) {
        std::cerr << "Error opening file!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    
    for (size_t i{}; i < book_amount; i++) {
        file << books[i].registration_number << '\n';
        file << books[i].author << '\n';
        file << books[i].name << '\n';
        file << books[i].publication_year << '\n';
        file << books[i].pages << '\n';
        if (books[i].name_flag == 1) {
            file << books[i].publisher_info.publisher_name << '\n';
        }
        else {
            file << books[i].publisher_info.publisher_location << '\n';
        }
    }

    file.close();

    std::cout << "\npress any key to continue: ";
    char c;
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}