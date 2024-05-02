#include "movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Record movies[MAX_M];
int num_mov = 0;

void read_data() {
    FILE *f = fopen("in.txt", "r");
    if (f == NULL) {
        printf("Ошибка открытия файла in.txt\n");
        exit(1);
    }
    while (fscanf(f, "%s %s %s %d", movies[num_mov].times, movies[num_mov].hall, movies[num_mov].movie, &movies[num_mov].count) == 4) {
        num_mov++;
    }
    fclose(f);
}

void write_movie() {
    FILE *f = fopen("out.txt", "w");
    if (f == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    sort_hall();

    fprintf(f, "Зал	Продано\n");
    char cur_hall[30];
    strcpy(cur_hall, movies[0].hall);
    int total_count = movies[0].count;
    for (int i = 1; i < num_mov; i++) {
        if (strcmp(movies[i].hall, cur_hall) == 0) {
            total_count += movies[i].count;
        } else {
            fprintf(f, "%s %s %s %d\n", movies[i].times, cur_hall, movies[i].movie, total_count);
            strcpy(cur_hall, movies[i].hall);
            total_count = movies[i].count;
        }
    }
    fprintf(f, "%s %s %s %d\n", movies[num_mov-1].times, cur_hall, movies[num_mov-1].movie, total_count);

    fclose(f);
}

void sort_hall() {
    for (int i = 0; i < num_mov - 1; i++) {
        for (int j = 0; j < num_mov - i - 1; j++) {
            if (strcmp(movies[j].hall, movies[j + 1].hall) > 0) {
                // Обмен записями о фильмах
                Record temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}

void add_b() {
    printf("Введите время: ");
    scanf("%s", movies[num_mov].times);
    printf("Введите зал: ");
    scanf("%s", movies[num_mov].hall);
    printf("Введите фильм: ");
    scanf("%s", movies[num_mov].movie);
    printf("Введите количество: ");
    scanf("%d", &movies[num_mov].count);

    num_mov++;
    printf("Запись добавлена.\n");
}

void edit_b() {
    char hall[30];
    printf("Введите зал для редактирования: ");
    scanf("%s", hall);

    for (int i = 0; i < num_mov; i++) {
        if (strcmp(movies[i].hall, hall) == 0) {
            printf("Введите время: ");
            scanf("%s", movies[i].times);
            printf("Введите зал: ");
            scanf("%s", movies[i].hall);
            printf("Введите фильм: ");
            scanf("%s", movies[i].movie);
            printf("Введите количество: ");
            scanf("%d", &movies[i].count);

            return;
        }
    }

    printf("Зал %s не найден\n", hall);
}

void delete_b() {
    char hall[30];
    printf("Введите зал для удаления: ");
    scanf("%s", hall);

    for (int i = 0; i < num_mov; i++) {
        if (strcmp(movies[i].hall, hall) == 0) {
            for (int j = i; j < num_mov - 1; j++) {
                movies[j] = movies[j + 1];
            }
            num_mov--;
            printf("Записи для зала %s удалены\n", hall);
            return;
        }
    }

    printf("Зал %s не найден\n", hall);
}

void print_all() {
    for (int i = 0; i < num_mov; i++) {
        printf("%s %s %s %d\n", movies[i].times, movies[i].hall, movies[i].movie, movies[i].count);
    }
}
