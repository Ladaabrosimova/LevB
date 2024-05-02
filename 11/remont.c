#include "remont.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Record devices[MAX_R];
int num_device = 0;

void read_data() {
    FILE *f = fopen("in.txt", "r");
    if (f == NULL) {
        printf("Ошибка открытия файла in.txt\n");
        exit(1);
    }
    while (fscanf(f, "%s %s %s %s %s", devices[num_device].date, devices[num_device].client, devices[num_device].device, devices[num_device].firm, devices[num_device].category) == 5) {
        num_device++;
    }
    fclose(f);
}

void write_device() {
    FILE *f = fopen("out.txt", "w");
    if (f == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    sort_firm();

    fprintf(f, "Дата обращения\tНазвание\tПроизводитель\tКатегория\n");
    for (int i = 0; i < num_device; i++) {
        if (strcmp(devices[i].category, "Сложный") == 0) {
            fprintf(f, "%s\t%s\t%s\t%s\n", devices[i].date, devices[i].device, devices[i].firm, devices[i].category);
        }
    }

    fclose(f);
}

void sort_firm() {
    for (int i = 0; i < num_device - 1; i++) {
        for (int j = 0; j < num_device - i - 1; j++) {
            if (strcmp(devices[j].firm, devices[j + 1].firm) > 0) {
                // Обмен записями
                Record temp = devices[j];
                devices[j] = devices[j + 1];
                devices[j + 1] = temp;
            }
        }
    }
}

void add_b() {
    printf("Введите дату: ");
    scanf("%s", devices[num_device].date);
    printf("Введите клиента: ");
    scanf("%s", devices[num_device].client);
    printf("Введите прибор: ");
    scanf("%s", devices[num_device].device);
    printf("Введите производителя: ");
    scanf("%s", devices[num_device].firm);
    printf("Введите категорию: ");
    scanf("%s", devices[num_device].category);

    num_device++;
    printf("Запись добавлена.\n");
}

void edit_b() {
    char client[30];
    printf("Введите клиента для редактирования: ");
    scanf("%s", client);

    for (int i = 0; i < num_device; i++) {
        if (strcmp(devices[i].client, client) == 0) {
            printf("Введите дату: ");
            scanf("%s", devices[i].date);
            printf("Введите клиента: ");
            scanf("%s", devices[i].client);
            printf("Введите прибор: ");
            scanf("%s", devices[i].device);
            printf("Введите производителя: ");
            scanf("%s", devices[i].firm);
            printf("Введите категорию: ");
            scanf("%s", devices[i].category);

            return;
        }
    }

    printf("Клиент %s не найден\n", client);
}

void delete_b() {
    char client[30];
    printf("Введите клиента для удаления: ");
    scanf("%s", client);

    for (int i = 0; i < num_device; i++) {
        if (strcmp(devices[i].client, client) == 0) {
            for (int j = i; j < num_device - 1; j++) {
                devices[j] = devices[j + 1];
            }
            num_device--;
            printf("Записи для клиента %s удалены\n", client);
            return;
        }
    }

    printf("Клиент %s не найден\n", client);
}

void print_all() {
    for (int i = 0; i < num_device; i++) {
        printf("%s %s %s %s %s\n", devices[i].date, devices[i].client, devices[i].device, devices[i].firm, devices[i].category);
    }
}
