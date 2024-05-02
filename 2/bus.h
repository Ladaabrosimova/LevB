#ifndef BUS_H
#define BUS_H

#define MAX_BUSES 100

// Структура записи об автобусе
typedef struct {
    char num[20];       // Номер автобуса
    char station[100];  // Название станции прибытия
    int pass;           // Количество пассажиров
} Record;

// Глобальные переменные
extern Record buses[MAX_BUSES];  // Массив автобусов
extern int num_buses;            // Количество загруженных автобусов

// Прототипы функций
void read_data();               // Чтение данных из файла
void write_passengers_count();  // Запись общего количества пассажиров каждого автобуса в файл
void add_bus();                 // Добавление нового автобуса
void edit_bus();                // Редактирование данных об автобусе
void delete_bus();              // Удаление автобуса
void sort_buses();              // Сортировка автобусов
void print_all_buses();         // Вывод всех автобусов в консоль

#endif /* BUS_H */
