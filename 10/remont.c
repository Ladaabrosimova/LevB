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
    while (fscanf(f, "%s %s %s %d", devices[num_device].client, devices[num_device].device, devices[num_device].firm, &devices[num_device].price) == 4) {
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

    sort_price();

    fprintf(f, "Заказчик Стоимость\n");
    char cur_cl[100];
    strcpy(cur_cl, devices[0].client);
    int total_price = devices[0].price;
    for (int i = 1; i < num_device; i++) {
        if (strcmp(devices[i].client, cur_cl) == 0) {
            total_price += devices[i].price;
        } else {
            fprintf(f, "%s %d\n", cur_cl, total_price);
            strcpy(cur_cl, devices[i].client);
            total_price = devices[i].price;
        }
    }
    fprintf(f, "%s %d\n", cur_cl, total_price);

    fclose(f);
}

void sort_price() {
    for (int i = 0; i < num_device - 1; i++) {
        for (int j = 0; j < num_device - i - 1; j++) {
            if (strcmp(devices[j].client, devices[j + 1].client) > 0) {
                // Обмен записями о продажах
                Record temp = devices[j];
                devices[j] = devices[j + 1];
                devices[j + 1] = temp;
            }
        }
    }
}

void add_b() {
    printf("Введите клиента: ");
    scanf("%s", devices[num_device].client);
    printf("Введите прибор: ");
    scanf("%s", devices[num_device].device);
    printf("Введите фирму: ");
    scanf("%s", devices[num_device].firm);
    printf("Введите стоимость: ");
    scanf("%d", &devices[num_device].price);

    num_device++;
    printf("Запись добавлена.\n");
}

void edit_b() {
    char client[100];
    printf("Введите клиента для редактирования: ");
    scanf("%s", client);

    for (int i = 0; i < num_device; i++) {
        if (strcmp(devices[i].client, client) == 0) {
            printf("Введите клиента: ");
            scanf("%s", devices[i].client);
            printf("Введите прибор: ");
            scanf("%s", devices[i].device);
            printf("Введите фирму: ");
            scanf("%s", devices[i].firm);
            printf("Введите стоимость: ");
            scanf("%d", &devices[i].price);

            return;
        }
    }

    printf("Клиент %s не найден\n", client);
}

void delete_b() {
    char client[100];
    printf("Введите клиента для удаления: ");
    scanf("%s", client);

    for (int i = 0; i < num_device; i++) {
        if (strcmp(devices[i].client, client) == 0) {
            for (int j = i; j < num_device - 1; j++) {
                strcpy(devices[j].client, devices[j + 1].client);
                strcpy(devices[j].device, devices[j + 1].device);
                strcpy(devices[j].firm, devices[j + 1].firm);
                devices[j].price, devices[j + 1].price;
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
        printf("%s %s %s %d", devices[num_device].client, devices[num_device].device, devices[num_device].firm, devices[num_device].price);
    }
}
