#ifndef AUTO_H
#define AUTO_H

#define MAX_CARS 100

// Структура записи о продаже автомобиля
typedef struct {
    char date[11];       // Дата продажи
    char manager[50];    // Фамилия менеджера
    char brand[20];      // Марка автомобиля
    int price;           // Цена
} SaleRecord;

// Глобальные переменные
extern SaleRecord cars[MAX_CARS];  // Массив записей о продажах
extern int num_cars;                // Количество записей о продажах

// Прототипы функций
void read_data();               // Чтение данных из файла
void write_sales_count();       // Запись количества проданных автомобилей за каждый месяц в файл
void add_sale();                // Добавление новой записи о продаже
void edit_sale();               // Редактирование данных о продаже
void delete_sale();             // Удаление записи о продаже
void print_all_sales();         // Вывод всех записей о продажах в консоль

#endif /* AUTO_H */
