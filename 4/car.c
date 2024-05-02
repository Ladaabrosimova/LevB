#include "car.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SaleRecord cars[MAX_CARS];
int num_cars = 0;

void read_data() {
    FILE *f = fopen("in.txt", "r");
    if (f == NULL) {
        printf("Ошибка открытия файла in.txt\n");
        exit(1);
    }
    while (fscanf(f, "%s %s %s %d", cars[num_cars].date, cars[num_cars].manager, cars[num_cars].brand, &cars[num_cars].price) == 4) {
        num_cars++;
    }
    fclose(f);
}

void write_sales_count() {
    FILE *f = fopen("out.txt", "w");
    if (f == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    sort_price();
    
    fprintf(f, "Менеджер Стоимость\n");
    char cur_manag[100];
    strcpy(cur_manag, cars[0].manager);
    int total_price = cars[0].price;
    for (int i = 1; i < num_cars; i++) {
        if (strcmp(cars[i].manager, cur_manag) == 0) {
            total_price += cars[i].price;
        } else {
            fprintf(f, "%s %d\n", cur_manag, total_price); 
            strcpy(cur_manag, cars[i].manager);
            total_price = cars[i].price;
        }
    }
    fprintf(f, "%s %d\n", cur_manag, total_price); 

    fclose(f); 
}

void sort_price() {
    for (int i = 0; i < num_cars - 1; i++) {
        for (int j = 0; j < num_cars - i - 1; j++) {
            if (strcmp(cars[j].manager, cars[j + 1].manager) > 0) {
                // Обмен записями о продажах
                SaleRecord temp = cars[j];
                cars[j] = cars[j + 1];
                cars[j + 1] = temp;
            }
        }
    }
}

void add_sale() {
    printf("Введите дату продажи (ДД.ММ.ГГГГ): ");
    scanf("%s", cars[num_cars].date);
    printf("Введите фамилию менеджера: ");
    scanf("%s", cars[num_cars].manager);
    printf("Введите марку автомобиля: ");
    scanf("%s", cars[num_cars].brand);
    printf("Введите цену автомобиля: ");
    scanf("%d", &cars[num_cars].price);

    num_cars++;
    printf("Запись о продаже добавлена.\n");
}

void edit_sale() {
    char date[11];
    printf("Введите дату продажи для редактирования (ДД.ММ.ГГГГ): ");
    scanf("%s", date);

    for (int i = 0; i < num_cars; i++) {
        if (strcmp(cars[i].date, date) == 0) {
            printf("Введите новую дату продажи (ДД.ММ.ГГГГ): ");
            scanf("%s", cars[i].date);
            printf("Введите новую фамилию менеджера: ");
            scanf("%s", cars[i].manager);
            printf("Введите новую марку автомобиля: ");
            scanf("%s", cars[i].brand);
            printf("Введите новую цену автомобиля: ");
            scanf("%d", &cars[i].price);
            printf("Изменения сохранены\n");
            return;
        }
    }

    printf("Запись о продаже с датой %s не найдена\n", date);
}

void delete_sale() {
    char date[11];
    printf("Введите дату продажи для удаления (ДД.ММ.ГГГГ): ");
    scanf("%s", date);

    for (int i = 0; i < num_cars; i++) {
        if (strcmp(cars[i].date, date) == 0) {
            for (int j = i; j < num_cars - 1; j++) {
                strcpy(cars[j].date, cars[j + 1].date);
                strcpy(cars[j].manager, cars[j + 1].manager);
                strcpy(cars[j].brand, cars[j + 1].brand);
                cars[j].price = cars[j + 1].price;
            }
            num_cars--;
            printf("Запись о продаже с датой %s удалена\n", date);
            return;
        }
    }

    printf("Запись о продаже с датой %s не найдена\n", date);
}


void print_all_sales() {
    for (int i = 0; i < num_cars; i++) {
        printf("%s %s %s %d\n", cars[i].date, cars[i].manager, cars[i].brand, cars[i].price);
    }
}
