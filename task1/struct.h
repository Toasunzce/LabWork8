#pragma once


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