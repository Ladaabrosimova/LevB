#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Record books[MAX_R];
int num_book = 0;

void read_data() {
    FILE *f = fopen("in.txt", "r");
    if (f == NULL) {
        printf("Ошибка открытия файла in.txt\n");
        exit(1);
    }
    while (fscanf(f, "%s %s %d", books[num_book].date, books[num_book].reader, &books[num_book].count) == 3) {
        num_book++;
    }
    fclose(f);
}

void write_book_count() {
    FILE *f = fopen("out.txt", "w");
    if (f == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    sort_reader();
    
    fprintf(f, "Читатель Количество\n");
    char cur_read[100];
    strcpy(cur_read, books[0].reader);
    int total_count = books[0].count;
    for (int i = 1; i < num_book; i++) {
        if (strcmp(books[i].reader, cur_read) == 0) {
            total_count += books[i].count;
        } else {
            fprintf(f, "%s %d\n", cur_read, total_count); 
            strcpy(cur_read, books[i].reader);
            total_count = books[i].count;
        }
    }
    fprintf(f, "%s %d\n", cur_read, total_count); 

    fclose(f); 
}

void sort_reader() {
    for (int i = 0; i < num_book - 1; i++) {
        for (int j = 0; j < num_book - i - 1; j++) {
            if (strcmp(books[j].reader, books[j + 1].reader) > 0) {
                // Обмен записями о продажах
                Record temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void add_b() {
    printf("Введите дату (ДД.ММ.ГГГГ): ");
    scanf("%s", books[num_book].date);
    printf("Введите фамилию читателя: ");
    scanf("%s", books[num_book].reader);
    printf("Введите количество книг: ");
    scanf("%d", &books[num_book].count);

    num_book++;
    printf("Запись добавлена.\n");
}

void edit_b() {
    char date[11];
    printf("Введите дату для редактирования (ДД.ММ.ГГГГ): ");
    scanf("%s", date);

    for (int i = 0; i < num_book; i++) {
        if (strcmp(books[i].date, date) == 0) {
            printf("Введите новую дату (ДД.ММ.ГГГГ): ");
            scanf("%s", books[i].date);
            printf("Введите новую фамилию: ");
            scanf("%s", books[i].reader);
            printf("Введите новое количество: ");
            scanf("%d", &books[i].count);
            printf("Изменения сохранены\n");
            return;
        }
    }

    printf("Запись с датой %s не найдена\n", date);
}

void delete_b() {
    char date[11];
    printf("Введите дату для удаления (ДД.ММ.ГГГГ): ");
    scanf("%s", date);

    for (int i = 0; i < num_book; i++) {
        if (strcmp(books[i].date, date) == 0) {
            for (int j = i; j < num_book - 1; j++) {
                strcpy(books[j].date, books[j + 1].date);
                strcpy(books[j].reader, books[j + 1].reader);
                books[j].count = books[j + 1].count;
            }
            num_book--;
            printf("Запись с датой %s удалена\n", date);
            return;
        }
    }

    printf("Запись с датой %s не найдена\n", date);
}


void print_all() {
    for (int i = 0; i < num_book; i++) {
        printf("%s %s %d\n", books[i].date, books[i].reader, books[i].count);
    }
}
