#ifndef REM_H
#define REM_H

#define MAX_R 100

typedef struct {
    char date[30];
    char client[30];
    char device[30];
    char firm[30];
    char category[30];
} Record;

extern Record devices[MAX_R];
extern int num_device;

void read_data();
void write_device();
void sort_firm();
void add_b();
void edit_b();
void delete_b();
void print_all();

#endif /* REM_H */
