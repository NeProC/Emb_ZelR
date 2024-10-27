


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define SIZE 100

#include "sens.h"

typedef struct{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t t;
}sens;


void add_rec(sens info[], int num, uint16_t year, uint8_t month,
    uint8_t day, uint8_t hour, uint8_t minute, int8_t t);			//Функция добавления структуры в массив
int add_info(sens info[]);											//Ф-ция добавления значений
void print_info(sens info[], int num);								//Вывод данных
void swap_ij(sens info[], int i, int j);							//Меняет местами структуры в массиве
void sort_t(sens info[], int num);									//Сортировка по температуре


int main(int argc, char **argv)
{
    sens info[SIZE];
    int num = add_info(info);
    print_info(info, num);
    sort_t(info, num);
    print_info(info, num);
    return 0;
}

void add_rec(sens info[], int num, uint16_t year, uint8_t month,
    uint8_t day, uint8_t hour, uint8_t minute, int8_t t)
{
    info[num].year = year;
    info[num].month = month;
    info[num].day = day;
    info[num].hour = hour;
    info[num].minute = minute;
    info[num].t = t; 
}

int add_info(sens info[])
{
    int counter = 0;
    add_rec(info, counter++, 2021,9,16,23,55, 9);
    add_rec(info, counter++, 2021,9,2, 23,55,-9);
    add_rec(info, counter++, 2021,1,7, 23,55, 8);
    add_rec(info, counter++, 2021,9,5, 23,55, 1);
    return counter;
}

void print_info(sens info[], int num)
{
    printf("<========================================>\n");
    for(int32_t i = 0; i < num; i++)
    {
        printf("%04d - %02d - %02d - %02d - %02d\tt = %3d%cC\n",
            info[i].year,
            info[i].month,
            info[i].day,
            info[i].hour,
            info[i].minute,
            info[i].t,
            0x27
        );
    }
}

void swap_ij(sens info[], int i, int j)
{
    sens tmp = info[i];
    info[i] = info[j];
    info[j] = tmp;
    return;
}

void sort_t(sens info[], int num)
{
    for(int32_t i = 0; i < num; i++)
    {
        for(int32_t j = i; j < num; j++)
        {
            if(info[i].t < info[j].t){
                swap_ij(info, i, j);
            }
        }
    }
}
