#ifndef MOV_H
#define MOV_H

#define MAX_M 100

typedef struct{
    char times[30];
    char hall[30];
    char movie[30];
    int count;
} Record;

extern Record movies[MAX_M];
extern int num_mov;

void read_data();               
void write_movie();   
void sort_hall(); 
void add_b();               
void edit_b();              
void delete_b();            
void print_all(); 

#endif /* MOV_H */