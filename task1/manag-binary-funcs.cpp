#include "header.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include <limits>

void writeToBinaryFile(const char* filename, Product* production, short product_amount) {

    if (product_amount == 0) {
        std::cout << "production list is empty!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::ofstream file(filename, std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    
    file.write((char*)&product_amount, sizeof(short));
    file.write((char*)production, product_amount * sizeof(Product));
    file.close();

    std::cout << "Data has been writted!\n";

    std::cout << "\npress any key to continue: ";
    char c;
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void loadFromBinary(const char* filename, Product*& production, short& product_amount) {

    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    file.read((char*)&product_amount, sizeof(short));
    production = new Product[product_amount];
    file.read((char*)production, product_amount * sizeof(Product));
    file.close();

    std::cout << "Data has been loaded!\n";

    std::cout << "\npress any key to continue: ";
    char c;
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

short findProductIndexBinary(Product* production, short product_amount, char* product_name) {
    short counter = 0;
    for (size_t i{}; i < product_amount; i++) {
        if (!std::strcmp(production[i].name, product_name)) {
            return counter;
        }
        counter++;
    }
    return -1;
}

void editBinary(const char* filename, Product* production, short product_amount) {

    std::cout << "Enter name of Product you want to edit: ";
    char product_name[80];
    stringInput(product_name, 80);
    short index = findProductIndexBinary(production, product_amount, product_name);
    if (index == -1) {
        std::cerr << "Error finding index!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::fstream file(filename, std::ios::in | std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    long record_offset = sizeof(short) + index * sizeof(Product);
    Product temp_product;

    file.seekg(record_offset, std::ios::beg);
    file.read((char*)&temp_product, sizeof(Product));

    std::cout << "===================================\n"
            << "1. edit name\n"
            << "2. edit amount of production\n"
            << "3. edit price\n"
            << "4. edit workshop name/number\n"
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
            std::cout << "Enter new name: ";
            char temp_name[80];
            stringInput(temp_name, 80);
            std::strncpy(temp_product.name, temp_name, sizeof(temp_product.name) - 1);
            temp_product.name[sizeof(temp_product.name) - 1] = '\0';
            break;
        }
        case 2: {
            std::cout << "Enter new amount of production: ";
            int temp_number;
            positiveIntNumberInput(temp_number);
            temp_product.amount = temp_number;
            break;
        }
        case 3: {
            std::cout << "Enter new price: ";
            double temp_price;
            positiveDoubleNumberInput(temp_price);
            temp_product.price_per_unit = temp_price;
            break;
        }
        case 4: {
            std::cout << "Choose what do u want to edit (1 - number, 2 - name): ";
            int submenu;
            positiveIntNumberInput(submenu);
            if (submenu >= 3) {
                std::cout << "\e[0;31m" << "Wrong input! Tru to input correct one: " << "\e[0m";
                positiveIntNumberInput(submenu);
            }
            switch (submenu) {
                case 1: {
                    std::cout << "Enter new number: ";
                    int temp_number;
                    positiveIntNumberInput(temp_number);
                    temp_product.workshop_info.workshop_number = temp_number;
                    temp_product.name_flag = false;
                    break;
                }
                case 2: {
                    std::cout << "Enter new name: ";
                    char temp_name[80];
                    stringInput(temp_name, 80);
                    std::strcpy(temp_product.workshop_info.workshop_name, temp_name);
                    temp_product.name_flag = true;
                    break;
                }
            }
        }
        break;
    }

    file.seekg(record_offset, std::ios::beg);
    file.write((char*)&temp_product, sizeof(Product));
    file.seekg(0, std::ios::beg);
    file.close();
}