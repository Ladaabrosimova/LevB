#include "bus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Record buses[MAX_BUSES];
int num_buses = 0;

// Чтение данных из файла в структуру записей
void read_data() {
    FILE *f = fopen("in.txt", "r");
    if (f == NULL) {
        printf("Ошибка открытия файла in.txt\n");
        exit(1);
    }
    while (fscanf(f, "%s %s %d", buses[num_buses].num, buses[num_buses].station, &buses[num_buses].pass) == 3) {
        num_buses++;
    }
    fclose(f);
}

void write_passengers_count() {
    FILE *f = fopen("out.txt", "w");
    if (f == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }
    
    sort_buses(); 
    fprintf(f, "Станция Количество рейсов\n");
    char cur_station[100];
    strcpy(cur_station, buses[0].station);
    int num_trips = 1;
    for (int i = 1; i < num_buses; i++) {
        if (strcmp(buses[i].station, cur_station) == 0) {
            num_trips++;
        } else {
            fprintf(f, "%s %d\n", cur_station, num_trips); 
            strcpy(cur_station, buses[i].station);
            num_trips = 1;
        }
    }
    fprintf(f, "%s %d\n", cur_station, num_trips); 
    fclose(f); 
}


// Добавление нового автобуса в структуру
void add_bus() {
    printf("Введите номер автобуса: ");
    scanf("%s", buses[num_buses].num);
    printf("Введите название станции прибытия: ");
    scanf("%s", buses[num_buses].station);
    printf("Введите количество пассажиров: ");
    scanf("%d", &buses[num_buses].pass);

    num_buses++;
    printf("Автобус добавлен.\n");
}

// Редактирование данных об автобусе
void edit_bus() {
    char num[20];
    printf("Введите номер автобуса для редактирования: ");
    scanf("%s", num);

    for (int i = 0; i < num_buses; i++) {
        if (strcmp(buses[i].num, num) == 0) {
            printf("Введите новый номер автобуса: ");
            scanf("%s", buses[i].num);
            printf("Введите новое название станции прибытия: ");
            scanf("%s", buses[i].station);
            printf("Введите новое количество пассажиров: ");
            scanf("%d", &buses[i].pass);
            printf("Изменения сохранены\n");
            return;
        }
    }

    printf("Автобус с номером %s не найден\n", num);
}

// Удаление автобуса из структуры
void delete_bus() {
    char num[20];
    printf("Введите номер автобуса для удаления: ");
    scanf("%s", num);

    for (int i = 0; i < num_buses; i++) {
        if (strcmp(buses[i].num, num) == 0) {
            for (int j = i; j < num_buses - 1; j++) {
                strcpy(buses[j].num, buses[j + 1].num);
                strcpy(buses[j].station, buses[j + 1].station);
                buses[j].pass = buses[j + 1].pass;
            }
            num_buses--;
            printf("Автобус с номером %s удален\n", num);
            return;
        }
    }

    printf("Автобус с номером %s не найден\n", num);
}

// Сортировка автобусов по номеру и названию станции
void sort_buses() {
    for (int i = 0; i < num_buses - 1; i++) {
        for (int j = 0; j < num_buses - i - 1; j++) {
            // Сравниваем названия станций двух автобусов
            if (strcmp(buses[j].station, buses[j + 1].station) > 0) {
                // Если текущий автобус должен идти после следующего, меняем их местами
                Record temp = buses[j];
                buses[j] = buses[j + 1];
                buses[j + 1] = temp;
            }
        }
    }
}


// Вывод всех автобусов в консоль
void print_all_buses() {
    for (int i = 0; i < num_buses; i++) {
        printf("%s %s %d\n", buses[i].num, buses[i].station, buses[i].pass);
    }
}
