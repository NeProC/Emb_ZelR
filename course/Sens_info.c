/*
==================================================================================
Курсовая работа по теме "Создание консольного приложения - Статистика температуры"
==================================================================================
студент Зеленев Р. А.
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "temp_functions.h"
#define SIZE 100 // Размер массива структур

int main(int argc, char **argv)
{
    sens info[SIZE];
    int num = add_info(info);
    print_info(info, num);
    sort_t(info, num);
    print_info(info, num);
    sort_time(info, num);
    print_info(info, num);
    middle_t_in_month(info, num, 9);
    min_in_month(info, num, 9);
    max_in_month(info, num, 9);
    middle_t_in_year(info, num, 2021);
    min_in_year(info, num, 2021);
    max_in_year(info, num, 2021);
    //~ print_info(info, num);

    return 0;
}
