#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <limits>

typedef union {
    char workshop_name[80];
    int workshop_number;
} Workshop;

typedef struct {
    char name[80];
    int amount;
    Workshop workshop_info;
    bool is_automized; 
    double price_per_unit;
    bool name_flag;
} Product;


// memory functions
void allocateOneMoreStructure(Product*& production, short size);

//management-entering functions
void stringInput(char* string, int size);
void positiveIntNumberInput(int& number);
void positiveDoubleNumberInput(double& number);
Product* enterNewArrayProduct(int array_size);
Product* enterNewArrayProductWhile(short& product_amount);
Product* enterNewArrayProductDialogue(short& product_amount);
void addNewProductToArray(Product* production, short& product_amount);
void editProduct(Product* production, short product_amount);
void deleteProduct(Product* production, short& product_amount);

//management-outputting functions
void printArrayProduct(Product* production, short product_amount);
void searchInProductArray(Product* production, short product_amount);
void shekerSort(Product* production, short product_amount);
void describeWorkshop(Product* production, short product_amount);

//management-binary functions
void writeToBinaryFile(const char* filename, Product* production, short product_amount);
void loadFromBinary(const char* filename, Product*& production, short& product_amount);
short findProductIndexBinary(Product* production, short product_amount, char* product_name);
void editBinary(const char* filename, Product* production, short product_amount);