#include "header.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include <limits>

void printArrayProduct(Product* production, short product_amount) {

    if (product_amount == 0) {
        std::cout << "production list is empty!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    for (size_t i{}; i < product_amount; i++) {
        std::cout << "product #" << i + 1 << '\n';
        std::cout << "\tproduct name: " << production[i].name << '\n';
        std::cout << "\tproduct amount: " << production[i].amount << '\n';
        std::cout << "\tproduct price: " << production[i].price_per_unit << '\n';
        std::cout << "\tis automised: " << (production[i].is_automized ? "true" : "false") << '\n';

        if (production[i].name_flag == false) {
            std::cout << "\tworkshop number: " << production[i].workshop_info.workshop_number << '\n';
        }
        else {
            std::cout << "\tworkshop name: " << production[i].workshop_info.workshop_name << '\n';
        }

    }

    std::cout << "\npress any key to continue: ";
    char c;
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   
}

void searchInProductArray(Product* production, short product_amount) {

    if (product_amount == 0) {
        std::cout << "production list is empty!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "===================================\n"
              << "1. Find by name\n"
              << "2. Find by amount of production\n"
              << "3. Find by price\n"
              << "4. Find by automatization\n"
              << "5. Find by workshop name/number \n"
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
            std::cout << "Enter name for searching: ";
            char temp_name[80];
            stringInput(temp_name, 80);
            for (size_t i{}; i < product_amount; i++) {
                if (!std::strcmp(production[i].name, temp_name)) {
                    std::cout << "product #" << i + 1 << '\n';
                    std::cout << "\tproduct name: " << production[i].name << '\n';
                    std::cout << "\tproduct amount: " << production[i].amount << '\n';
                    std::cout << "\tproduct price: " << production[i].price_per_unit << '\n';
                    std::cout << "\tis automised: " << (production[i].is_automized ? "true" : "false") << '\n';
                    if (production[i].name_flag == false) {
                        std::cout << "\tworkshop number: " << production[i].workshop_info.workshop_number << '\n';
                    }
                    else {
                        std::cout << "\tworkshop name: " << production[i].workshop_info.workshop_name << '\n';
                    }
                }
            }
            break;
        }
        case 2: {
            std::cout << "Enter amount for searching: ";
            int temp_amount;
            positiveIntNumberInput(temp_amount);
            for (size_t i{}; i < product_amount; i++) {
                if (temp_amount == production[i].amount) {
                    std::cout << "product #" << i + 1 << '\n';
                    std::cout << "\tproduct name: " << production[i].name << '\n';
                    std::cout << "\tproduct amount: " << production[i].amount << '\n';
                    std::cout << "\tproduct price: " << production[i].price_per_unit << '\n';
                    std::cout << "\tis automised: " << (production[i].is_automized ? "true" : "false") << '\n';
                    if (production[i].name_flag == false) {
                        std::cout << "\tworkshop number: " << production[i].workshop_info.workshop_number << '\n';
                    }
                    else {
                        std::cout << "\tworkshop name: " << production[i].workshop_info.workshop_name << '\n';
                    }
                }
            }   
            break;
        }
        case 3: {
            std::cout << "Enter price value for searching: ";
            double temp_price;
            positiveDoubleNumberInput(temp_price);
            for (size_t i{}; i < product_amount; i++) {
                if (temp_price == production[i].price_per_unit) {
                    std::cout << "product #" << i + 1 << '\n';
                    std::cout << "\tproduct name: " << production[i].name << '\n';
                    std::cout << "\tproduct amount: " << production[i].amount << '\n';
                    std::cout << "\tproduct price: " << production[i].price_per_unit << '\n';
                    std::cout << "\tis automised: " << (production[i].is_automized ? "true" : "false") << '\n';
                    if (production[i].name_flag == false) {
                        std::cout << "\tworkshop number: " << production[i].workshop_info.workshop_number << '\n';
                    }
                    else {
                        std::cout << "\tworkshop name: " << production[i].workshop_info.workshop_name << '\n';
                    }
                }
            }
            break;
        }
        case 4: {
            std::cout << "Enter 1 (automatizationed) or 0 for searching: ";
            bool temp_automatization;
            
            while(true) {
                std::cin >> temp_automatization;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
            }

            for (size_t i{}; i < product_amount; i++) {
                if (temp_automatization == production[i].is_automized) {
                    std::cout << "product #" << i + 1 << '\n';
                    std::cout << "\tproduct name: " << production[i].name << '\n';
                    std::cout << "\tproduct amount: " << production[i].amount << '\n';
                    std::cout << "\tproduct price: " << production[i].price_per_unit << '\n';
                    std::cout << "\tis automised: " << (production[i].is_automized ? "true" : "false") << '\n';
                    if (production[i].name_flag == false) {
                        std::cout << "\tworkshop number: " << production[i].workshop_info.workshop_number << '\n';
                    }
                    else {
                        std::cout << "\tworkshop name: " << production[i].workshop_info.workshop_name << '\n';
                    }
                }
            }
            break;
        }
        case 5: {
            std::cout << "Choose how do u want to search (1 - number, 2 - name): ";
            int submenu;
            positiveIntNumberInput(submenu);
            if (submenu >= 3) {
                std::cout << "\e[0;31m" << "Wrong input! Tru to input correct one: " << "\e[0m";
                positiveIntNumberInput(submenu);
            }
            switch (submenu) {
                case 1: {
                    std::cout << "Enter number for searching: ";
                    int temp_number;
                    positiveIntNumberInput(temp_number);
                    for (size_t i{}; i < product_amount; i++) {
                        if (production[i].name_flag == 0 and temp_number == production[i].workshop_info.workshop_number) {
                            std::cout << "product #" << i + 1 << '\n';
                            std::cout << "\tproduct name: " << production[i].name << '\n';
                            std::cout << "\tproduct amount: " << production[i].amount << '\n';
                            std::cout << "\tproduct price: " << production[i].price_per_unit << '\n';
                            std::cout << "\tis automised: " << (production[i].is_automized ? "true" : "false") << '\n';
                            if (production[i].name_flag == false) {
                                std::cout << "\tworkshop number: " << production[i].workshop_info.workshop_number << '\n';
                            }
                            else {
                                std::cout << "\tworkshop name: " << production[i].workshop_info.workshop_name << '\n';
                            }
                        }
                    }
                    break;
                }
                case 2: {
                    std::cout << "Enter name for searching: ";
                    char temp_name[80];
                    stringInput(temp_name, 80);
                    for (size_t i{}; i < product_amount; i++) {
                        if (production[i].name_flag == 1 and !std::strcmp(production[i].workshop_info.workshop_name, temp_name)) {
                            std::cout << "product #" << i + 1 << '\n';
                            std::cout << "\tproduct name: " << production[i].name << '\n';
                            std::cout << "\tproduct amount: " << production[i].amount << '\n';
                            std::cout << "\tproduct price: " << production[i].price_per_unit << '\n';
                            std::cout << "\tis automised: " << (production[i].is_automized ? "true" : "false") << '\n';
                            if (production[i].name_flag == false) {
                                std::cout << "\tworkshop number: " << production[i].workshop_info.workshop_number << '\n';
                            }
                            else {
                                std::cout << "\tworkshop name: " << production[i].workshop_info.workshop_name << '\n';
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

void shekerSort(Product* production, short product_amount) {

    if (product_amount == 0) {
        std::cout << "production list is empty!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    short left = 0;
    short right = product_amount - 1;
    Product temp;
    short flag = 1;

    while(left < right) {
        flag = 0;
        for (short i{left}; i < right; i++) {
            if (production[i].name[0] > production[i + 1].name[0]) {
                temp = production[i];
                production[i] = production[i + 1];
                production[i + 1] = temp;
                flag = 1;
            }
        }
        right--;

        for (short i{right}; i > left; i--) {
            if (production[i - 1].name[0] > production[i].name[0]) {
                temp = production[i];
                production[i] = production[i - 1];
                production[i - 1] = temp;
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

void describeWorkshop(Product* production, short product_amount) {

    if (product_amount == 0) {
        std::cout << "production list is empty!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Choose how do u want to search (1 - number, 2 - name): ";
    int submenu;
    unsigned int sum = 0;
    positiveIntNumberInput(submenu);
    if (submenu >= 3) {
        std::cout << "\e[0;31m" << "Wrong input! Tru to input correct one: " << "\e[0m";
        positiveIntNumberInput(submenu);
    }
    switch (submenu) {
        case 1: {
            std::cout << "Enter workwhop number to describe: ";
            int temp_number;
            positiveIntNumberInput(temp_number);
            for (size_t i{}; i < product_amount; i++) {
                if (production[i].name_flag == 0 and temp_number == production[i].workshop_info.workshop_number) {
                    sum += production[i].amount;
                }
            }
            break;
        }
        case 2: {
            std::cout << "Enter workshop name to describe: ";
            char temp_name[80];
            stringInput(temp_name, 80);
            for (size_t i{}; i < product_amount; i++) {
                if (production[i].name_flag == 1 and !std::strcmp(production[i].workshop_info.workshop_name, temp_name)) {
                    sum += production[i].amount;
                }
            }
            break;
        }
    }
    std::cout << "Amount of production for this workshop: " << sum << '\n';
    
    std::cout << "\npress any key to continue: ";
    char c;
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}