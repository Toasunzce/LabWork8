#pragma once

typedef union {
    char publisher_name[80];
    char publisher_location[80];
} Publisher;

typedef struct {
    int registration_number;
    char author[80];
    char name[80];
    int publication_year;
    int pages;
    Publisher publisher_info;
    bool name_flag;
} Book;