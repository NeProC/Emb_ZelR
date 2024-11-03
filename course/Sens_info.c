/*
==================================================================================
Курсовая работа по теме "Создание консольного приложения - Статистика температуры"
==================================================================================
студент Зеленев Р. А.
*/
 
#include "temp_functions.h"
#define SIZE 1000 // Размер массива структур

int main(int argc, char **argv)
{
     sens info[SIZE];
    // int num = add_info(info);
    // print_info(info, num);
    // sort_t(info, num);
    // print_info(info, num);
    // sort_time(info, num);
    // print_info(info, num);
    // middle_t_in_month(info, num, 9);
    // min_in_month(info, num, 9);
    // max_in_month(info, num, 9);
    // middle_t_in_year(info, num, 2021);
    // min_in_year(info, num, 2021);
    // max_in_year(info, num, 2021);
    // //~ print_info(info, num);

//======================================= аргументы командной строки
    // int k = 0;
    // opterr = 0;
    // while ((k = getopt(argc, argv, "hf:m")) != -1)
    // {
    //     switch (k)
    //     {
    //     case 'h':
    //         help();
    //         break;
    //     case 'f':
            
    //         break;
    //     case 'm':
            
    //         break;  
    //     default:
    //         break;
    //     }
    // }
    int num = add_info_from_csv(info);
    printf("num = %d\n", num);
    print_info(info, num);

    return 0;
}
