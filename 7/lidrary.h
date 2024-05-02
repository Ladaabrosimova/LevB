#ifndef LIB_H
#define LIB_H

#define MAX_R 100

typedef struct {
    int code;
    char name[100];
    char author[100];
    char genre[100];
    int year;
} Record;

extern Record books[MAX_R];
extern int num_book;

void read_data();
void write_book();
void sort_genre();
void add_b();
void edit_b();
void delete_b();
void print_all();

#endif /* LIB_H */
