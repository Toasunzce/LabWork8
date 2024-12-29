#include "header.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include <limits>

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
        if (std::cin.fail() or number <= 0 or std::cin.peek() != '\n') {
            std::cout << "\e[0;31m" << "Wrong input! Try to input a correct one: " << "\e[0m";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
}
void positiveDoubleNumberInput(double& number) {
    while (true) {
        std::cin >> number;
        if (std::cin.fail() or number <= 0 or std::cin.peek() != '\n') {
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

Product* enterNewArrayProduct(int array_size) {

    Product* production = new Product[array_size];

    for (size_t i{}; i < array_size; i++) {

        std::cout << "Enter information about product #" << i + 1 << '\n';

        std::cout << "\tproduct name: ";
        stringInput(production[i].name, 80);

        std::cout << "\tnumber of produced product: ";
        positiveIntNumberInput(production[i].amount);

        std::cout << "\tprice of single product: ";
        positiveDoubleNumberInput(production[i].price_per_unit);

        if (production[i].amount >= 1000) {
            production[i].is_automized = true;
        }
        else {
            production[i].is_automized = false;
        }

        std::cout << "\e[0;33m" << "    number or name of the workshop (1 - num, 2 - name): " << "\e[0m";
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
                production[i].name_flag = false;
                std::cout << "\tnumber of workshop: ";
                positiveIntNumberInput(production[i].workshop_info.workshop_number);
                break;
            } else if (c == '2') {
                production[i].name_flag = true;
                std::cout << "\tname of workshop: ";
                stringInput(production[i].workshop_info.workshop_name, 80);
                break;
            }
        }
    }

    return production;
}

Product* enterNewArrayProductWhile(short& product_amount) {

    Product* production = new Product[1];
    short counter = 0;
    const char* bword = "break";

    for (;;) {
        std::cout << "Enter information about product #" << counter + 1 << '\n';

        std::cout << "\tproduct name: ";
        stringInput(production[counter].name, 80);
        if (!std::strncmp(production[counter].name, bword, 5)) {
            break;
        }

        std::cout << "\tnumber of produced product: ";
        positiveIntNumberInput(production[counter].amount);

        std::cout << "\tprice of single product: ";
        positiveDoubleNumberInput(production[counter].price_per_unit);

        if (production[counter].amount >= 1000) {
            production[counter].is_automized = true;
        }
        else {
            production[counter].is_automized = false;
        }

        std::cout << "\e[0;33m" << "    number or name of the workshop (1 - num, 2 - name): " << "\e[0m";
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
                std::cout << "\tnumber of workshop: ";
                production[counter].name_flag = false;
                positiveIntNumberInput(production[counter].workshop_info.workshop_number);
                break;
            } else if (c == '2') {
                std::cout << "\tname of workshop: ";
                production[counter].name_flag = true;
                stringInput(production[counter].workshop_info.workshop_name, 80);
                break;
            }
        }
        counter++;
        allocateOneMoreStructure(production, counter);
    }
    std::cout << counter;
    Product* final_production = new Product[counter];

    for (size_t i{}; i < counter; i++) {
        final_production[i] = production[i];
    }

    delete[] production;

    product_amount = counter;
    return final_production;
}

Product* enterNewArrayProductDialogue(short& product_amount) {

    Product* production = new Product[1];
    short counter = 0;
    while (true) {
        std::cout << "Enter information about product #" << counter + 1 << '\n';

        std::cout << "\tproduct name: ";
        stringInput(production[counter].name, 80);

        std::cout << "\tnumber of produced product: ";
        positiveIntNumberInput(production[counter].amount);

        std::cout << "\tprice of single product: ";
        positiveDoubleNumberInput(production[counter].price_per_unit);

        if (production[counter].amount >= 1000) {
            production[counter].is_automized = true;
        }
        else {
            production[counter].is_automized = false;
        }

        std::cout << "\e[0;33m" << "    number or name of the workshop (1 - num, 2 - name): " << "\e[0m";
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
                std::cout << "\tnumber of workshop: ";
                production[counter].name_flag = false;
                positiveIntNumberInput(production[counter].workshop_info.workshop_number);
                break;
            } else if (c == '2') {
                production[counter].name_flag = true;
                std::cout << "\tname of workshop: ";
                stringInput(production[counter].workshop_info.workshop_name, 80);
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
        allocateOneMoreStructure(production, counter);
    }

    product_amount = counter + 1;
    return production;
}

void addNewProductToArray(Product* production, short& product_amount) {

    std::cout << "add product #" << product_amount + 1 << '\n';

    std::cout << "\tproduct name: ";
    stringInput(production[product_amount].name, 80);

    std::cout << "\tnumber of produced product: ";
    positiveIntNumberInput(production[product_amount].amount);

    std::cout << "\tprice of single product: ";
    positiveDoubleNumberInput(production[product_amount].price_per_unit);

    if (production[product_amount].amount >= 1000) {
        production[product_amount].is_automized = true;
    }
    else {
        production[product_amount].is_automized = false;
    }

    std::cout << "\e[0;33m" << "    number or name of the workshop (1 - num, 2 - name): " << "\e[0m";
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
            std::cout << "\tnumber of workshop: ";
            production[product_amount].name_flag = false;
            positiveIntNumberInput(production[product_amount].workshop_info.workshop_number);
            break;
        } else if (c == '2') {
            std::cout << "\tname of workshop: ";
            production[product_amount].name_flag = true;
            stringInput(production[product_amount].workshop_info.workshop_name, 80);
            break;
        }
    }
    product_amount++;
}

void editProduct(Product* production, short product_amount) {

    if (product_amount == 0) {
        std::cout << "production list is empty!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Enter name for product you want to edit: ";
    char temp_name[80];
    stringInput(temp_name, 80);
    for (size_t i{}; i < product_amount; i++) {
        if (!std::strcmp(production[i].name, temp_name)) {
            std::cout << "===================================\n"
                    << "1. edit name\n"
                    << "2. edit amount of production\n"
                    << "3. edit price\n"
                    << "4. edit workshop name/number\n"
                    << "5. stop editing\n"
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
                    std::cout << "Enter new name: ";
                    char temp_name[80];
                    stringInput(temp_name, 80);
                    std::strcpy(production[i].name, temp_name);
                    break;
                }
                case 2: {
                    std::cout << "Enter new amount: ";
                    int temp_amount;
                    positiveIntNumberInput(temp_amount);
                    production[i].amount = temp_amount;
                    break;
                }
                case 3: {
                    std::cout << "Enter new price: ";
                    double temp_price;
                    positiveDoubleNumberInput(temp_price);
                    production[i].price_per_unit = temp_price;
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
                            production[i].workshop_info.workshop_number = temp_number;
                            break;
                        }
                        case 2: {
                            std::cout << "Enter new name: ";
                            char temp_name[80];
                            stringInput(temp_name, 80);
                            std::strcpy(production[i].workshop_info.workshop_name, temp_name);
                            break;
                        }
                    }
                }
                case 5: {
                    break;
                }
                break;
            }  
        }
    } 
}

void deleteProduct(Product* production, short& product_amount) {

    if (product_amount == 0) {
        std::cout << "production list is empty!\n";
        std::cout << "\npress any key to continue: ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Enter name for product you want to delete: ";
    char temp_name[80];
    stringInput(temp_name, 80);

    bool product_found = false;
    Product* new_production = new Product[product_amount - 1];

    for (short i = 0, counter = 0; i < product_amount; i++) {
        if (!std::strcmp(production[i].name, temp_name) and !product_found) {
            product_found = true;
            continue;
        }
        if (counter < product_amount - 1) {
            new_production[counter++] = production[i];
        }
    }

    for (short i = 0; i < product_amount - 1; i++) {
        production[i] = new_production[i];
    }

    delete[] new_production;
    product_amount--;
}