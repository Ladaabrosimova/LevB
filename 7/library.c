#include "lidrary.h"
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
    while (fscanf(f, "%d %s %s %s %d", &books[num_book].code, books[num_book].name, books[num_book].author, books[num_book].genre, &books[num_book].year) == 5) {
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

    sort_genre();

    fprintf(f, "Жанр Количество\n");
    int count = 1;
    for (int i = 1; i < num_book; i++) {
        if (strcmp(books[i].genre, books[i - 1].genre) != 0) {
            fprintf(f, "%s %d\n", books[i - 1].genre, count);
            count = 1;
        } else {
            count++;
        }
    }
    fprintf(f, "%s %d\n", books[num_book - 1].genre, count);

    fclose(f);
}

void sort_genre() {
    for (int i = 0; i < num_book - 1; i++) {
        for (int j = 0; j < num_book - i - 1; j++) {
            if (strcmp(books[j].genre, books[j + 1].genre) > 0) {
                Record temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void add_b() {
    printf("Введите код книги: ");
    scanf("%d", &books[num_book].code);
    printf("Введите название книги: ");
    scanf("%s", books[num_book].name);
    printf("Введите автора книги: ");
    scanf("%s", books[num_book].author);
    printf("Введите жанр книги: ");
    scanf("%s", books[num_book].genre);
    printf("Введите год издания книги: ");
    scanf("%d", &books[num_book].year);

    num_book++;
    printf("Запись добавлена.\n");
}

void edit_b() {
    int code;
    printf("Введите код книги для редактирования: ");
    scanf("%d", &code);

    for (int i = 0; i < num_book; i++) {
        if (books[i].code == code) {
            printf("Введите новое название книги: ");
            scanf("%s", books[i].name);
            printf("Введите нового автора книги: ");
            scanf("%s", books[i].author);
            printf("Введите новый жанр книги: ");
            scanf("%s", books[i].genre);
            printf("Введите новый год издания книги: ");
            scanf("%d", &books[i].year);
            printf("Изменения сохранены\n");
            return;
        }
    }

    printf("Книга с кодом %d не найдена\n", code);
}

void delete_b() {
    int code;
    printf("Введите код книги для удаления: ");
    scanf("%d", &code);

    for (int i = 0; i < num_book; i++) {
        if (books[i].code == code) {
            for (int j = i; j < num_book - 1; j++) {
                books[j] = books[j + 1];
            }
            num_book--;
            printf("Книга с кодом %d удалена\n", code);
            return;
        }
    }

    printf("Книга с кодом %d не найдена\n", code);
}

void print_all() {
    for (int i = 0; i < num_book; i++) {
        printf("%d %s %s %s %d\n", books[i].code, books[i].name, books[i].author, books[i].genre, books[i].year);
    }
}
