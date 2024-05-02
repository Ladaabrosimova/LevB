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
extern SaleRecord cars[MAX_CARS];  
extern int num_cars;                

// Прототипы функций
void read_data();               
void write_sales_count();   
void sort_price(); 
void add_sale();               
void edit_sale();              
void delete_sale();            
void print_all_sales();         

#endif /* AUTO_H */
