#include "library.h"
#include <stdio.h>

int main(){
    int choice;
    
    while(1){
        printf("\nМеню:\n");
        printf("1. Добавить\n");
        printf("2. Удалить\n");
        printf("3. Редактировать\n");
        printf("4. Загрузить в память\n");
        printf("5. Распечатать все\n");
        printf("6. Создать файл\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_b(); 
                break;
            case 2:
                delete_b();
                break;
            case 3:
                edit_b();
                break;
            case 4:
                read_data();
                printf("Данные загружены в память\n");
                break;
            case 5:
                print_all();
                break;
            case 6:
                write_book_count();
                printf("Файл создан успешно.\n");
                break;
            case 0:
                printf("До свидания!\n");
                return 0;
            default:
                printf("Некорректный выбор, попробуйте снова.\n");
        }
    }

    return 0;
}