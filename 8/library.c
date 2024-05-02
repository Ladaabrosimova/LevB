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
    while (fscanf(f, "%s %s %s %s", books[num_book].date, books[num_book].reader, books[num_book].name, books[num_book].author) == 4) {
        num_book++;
    }
    fclose(f);
}

void write_book() {
    FILE *f = fopen("out.txt", "w");
    if (f == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    sort_reader();
    
    fprintf(f, "Читатель\tКнига\n");
    char cur_read[100];
    strcpy(cur_read, books[0].reader);
    for (int i = 0; i < num_book; i++) {
        if (strcmp(books[i].author, "Пушкин") == 0) {
            if (strcmp(books[i].reader, cur_read) != 0) {
                strcpy(cur_read, books[i].reader); // Update current reader
            }
            fprintf(f, "%s\t%s\n", books[i].reader, books[i].name);
        }
    }

    fclose(f);
}

void sort_reader() {
    for (int i = 0; i < num_book - 1; i++) {
        for (int j = 0; j < num_book - i - 1; j++) {
            if (strcmp(books[j].reader, books[j + 1].reader) < 0) {
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
    printf("Введите название книги: ");
    scanf("%s", books[num_book].name);
    printf("Введите автора книги: ");
    scanf("%s", books[num_book].author);

    num_book++;
    printf("Запись добавлена.\n");
}

void edit_b() {
    char reader[100];
    printf("Введите фамилию читателя для редактирования: ");
    scanf("%s", reader);

    for (int i = 0; i < num_book; i++) {
        if (strcmp(books[i].reader, reader) == 0) {
            printf("Введите новую дату (ДД.ММ.ГГГГ): ");
            scanf("%s", books[i].date);
            printf("Введите новое название книги: ");
            scanf("%s", books[i].name);
            printf("Введите нового автора книги: ");
            scanf("%s", books[i].author);
            printf("Изменения сохранены\n");
            return;
        }
    }

    printf("Читатель %s не найден\n", reader);
}

void delete_b() {
    char reader[100];
    printf("Введите фамилию читателя для удаления: ");
    scanf("%s", reader);

    for (int i = 0; i < num_book; i++) {
        if (strcmp(books[i].reader, reader) == 0) {
            for (int j = i; j < num_book - 1; j++) {
                strcpy(books[j].date, books[j + 1].date);
                strcpy(books[j].reader, books[j + 1].reader);
                strcpy(books[j].name, books[j + 1].name);
                strcpy(books[j].author, books[j + 1].author);
            }
            num_book--;
            printf("Записи для читателя %s удалены\n", reader);
            return;
        }
    }

    printf("Читатель %s не найден\n", reader);
}

void print_all() {
    for (int i = 0; i < num_book; i++) {
        printf("%s %s %s %s\n", books[i].date, books[i].reader, books[i].name, books[i].author);
    }
}
