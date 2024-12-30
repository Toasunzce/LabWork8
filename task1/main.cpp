#include <iostream>
#include "struct.h"
#include "header.h"

const char* filename = "/home/toasunzce/Documents/453501/ОАиП/LR8/task1/vault.bin";


int main() {

    Product* production = nullptr;
    short product_amount = 0;

    while (true) {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "==========={ MAIN MENU }===========\n"
                  << "1.  Data entering (3 options)\n"
                  << "2.  Data showing\n"
                  << "3.  Adding data to array\n"
                  << "4.  Searching for specific data\n"
                  << "5.  Editing data elements\n"
                  << "6.  Delete products\n"
                  << "7.  Sort data (number/name)\n"
                  << "8.  Describe workshop (by name)\n"
                  << "9.  Save into binary\n"
                  << "10. Load from binary\n"
                  << "11. Edit binary\n"
                  << "12. Exit\n"
                  << "current amount of products: " << product_amount << '\n'
                  << "===================================\n";
        std::cout << "Enter menu option: ";
        int menu;
        positiveIntNumberInput(menu);
        if (menu >= 13) {
            std::cout << "\e[0;31m" << "Wrong input! Tru to input correct one: " << "\e[0m";
            positiveIntNumberInput(menu);
        }
        
        switch (menu) {
            case 1: {
                std::cout << "===================================\n"
                          << "1. Entering number of products\n"
                          << "2. Entering products till break word\n"
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

                switch (submenu) {
                    case 1: {
                        std::cout << "Enter amount of products: ";
                        int array_size;
                        positiveIntNumberInput(array_size);
                        std::cout << '\n';
                        production = enterNewArrayProduct(array_size);
                        product_amount = array_size;
                        break;
                    }
                    case 2: {
                        production = enterNewArrayProductWhile(product_amount);
                        break;
                    }
                    case 3: {
                        production = enterNewArrayProductDialogue(product_amount);
                        break;
                    }
                    case 4: {
                        break;
                    }
                    break;
                }
                break;
                
            }
            case 2: {
                printArrayProduct(production, product_amount);
                break;
            }
            case 3: {
                allocateOneMoreStructure(production, product_amount);
                addNewProductToArray(production, product_amount);
                break;
            }
            case 4: {
                searchInProductArray(production, product_amount);
                break;
            }
            case 5: {
                editProduct(production, product_amount);
                break;
            }
            case 6: {
                deleteProduct(production, product_amount);
                break;
            }
            case 7: {
                shekerSort(production, product_amount);
                break;
            }
            case 8: {
                describeWorkshop(production, product_amount);
                break;
            }
            case 9: {
                writeToBinaryFile(filename, production, product_amount);
                break;
            }
            case 10: {
                loadFromBinary(filename, production, product_amount);
                break;
            }
            case 11: {
                editBinary(filename, production, product_amount);
                break;
            }
            case 12: {
                delete[] production;
                production = nullptr;
                return 0;
            }
        }
    }
    
    delete[] production;
    return 0;
}