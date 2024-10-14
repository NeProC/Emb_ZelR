/*
 * F1.c
 * 
 * Copyright 2024 R.Zelenev <R.Zelenev@NB-592>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#define M_PI 3.14159265358979323846
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#define ARR_SIZE 100
#define SWAP_SIZE 4

void section_sort(uint32_t len, uint32_t *arr);						//Сортировка секциями
void scan_arr(int32_t *arr, int32_t len);							//Считывание массива
void print_arr (int32_t *arr, int32_t len);						//Вывод массива
void sort_even_odd(int n, int a[]);									//Сортировка и вывод четных и не четных чисел
void number_in_arr(uint32_t *arr, uint32_t len, uint64_t num);		//
int32_t len_of_num (uint64_t  n);									//Длина числа
void num_of_digit(uint32_t *arr, uint32_t len_arr);					//Подсчет чисел
void read_str(char *arr);											//Считывание строки чисел и помещение в массив
void count_of_dig(char *arr_c, int32_t *arr_dig, int32_t len);		//Подсчет цифр в массиве
void pri_count_dig(int32_t *arr);									//Вывод подсчета цифр в строке
void select_dig(char *arr);											//
void pri_char(char *arr, int32_t len);								//Печать массива символов
void print_digit(char s[]);											//Подсчет цифр в строке


int main()
{
/*    char arr_num[ARR_SIZE];
    select_dig(arr_num);
    int32_t len = strlen(arr_num);
    int32_t count[10] = {0};
    count_of_dig(arr_num, count, len);
    pri_count_dig(count);
//    pri_char(arr_num, 5); */
    char s[ARR_SIZE];
    char c;
    int index = 0;
    while((c = getchar()) != '\n'){
        s[index++] = c;
    }
    print_digit(s);
    return 0;
}

void section_sort(uint32_t len, uint32_t *arr)
{
    int32_t new_el, index;
    
    for (int i = 1; i < len; i++)
    {
        new_el = arr[i];
        index = i - 1;
        while(arr[index] > new_el && index >= 0)
        {
            arr[index + 1] = arr[index];
            index -= 1;
        }
        arr[index + 1] = new_el;
    }
    return;
}

void scan_arr(int32_t *arr, int32_t len)
{
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    return;
}

void print_arr (int32_t *arr, int32_t len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

void sort_even_odd(int n, int a[])
{
    int even = 0, not_even = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
            even++;
    }
    not_even = n - even;

    int arr_even[even], arr_not_even[not_even];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0){
            arr_even[count++] = a[i];
//            count++;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] % 2 != 0){
            arr_not_even[count++] = a[i];
//            count++;
        }
    }
    
    for (int i = 0; i < even ; i++)
    {
        a[i] = arr_even[i];
    }
    for (int i = 0; i < not_even ; i++)
    {
        a[i + even] = arr_not_even[i];
    }
    return;
}

void number_in_arr(uint32_t *arr, uint32_t len, uint64_t num)
{
    for(uint32_t i = 0; i < len; i++){
        arr[i] = num % 10;
        num /= 10;
    }
    return;
}

int32_t len_of_num (uint64_t  n)
{
    if(n == 0)
        return 1;
    int32_t len = 0;
    while(n != 0){
        len++;
        n /= 10;
    }
    return len;
}

void num_of_digit(uint32_t *arr, uint32_t len_arr)
{
    int32_t counter = 1;
    for(int32_t i = 1; i < len_arr; i++)
    {
        if(arr[i] == arr[i - 1])
            counter++;
        else {
            printf("%d %d\n", arr[i - 1], counter);
            counter = 1;
        }
    }
    printf("%d %d\n", arr[len_arr - 1], counter);
    return;
}

void read_str(char *arr)
{
    int8_t c;
    int32_t i = 0;
    
    while( (c = getchar()) != '\n' && i < ARR_SIZE){
        *(arr + i) = c;
        i++;
    }
    return;
}

void count_of_dig(char *arr_c, int32_t *arr_dig, int32_t len)
{
    for (int32_t i = 0; i < len; i++)
    {
        arr_dig[arr_c[i] - '0']++;
    }
    return;
}

void pri_count_dig(int32_t *arr)
{
    for (int32_t i = 0; i < 10; i++)
    {
        if(*(arr + i) != 0)
            printf("%d %d\n", i, *(arr + i));
    }
    return;
}

void select_dig(char *arr)
{
    char c;
    int32_t i = 0;
    
    while( (c = getchar()) != '\n'){
        if(c >= '0' && c <= '9'){
            *(arr + i) = c;
            i++;
        }
    }
    *(arr + i) = '\0';
    return;
}

void pri_char(char *arr, int32_t len)
{
    for (int32_t i = 0; i < len; i++)
    {
        printf("%c ", arr[i]);
    }
    return;
}

void print_digit(char s[])
{
    char arr[100] = {0};
    int count = 0, i = 0;

    while(s[i] != '\0'){
        if(*(s + i) >= '0' && *(s + i) <= '9')
            arr[count++] = s[i];
        i++;
    }
    arr[count] = '\0';
    
    int len = strlen(arr);
    int arr_dig[10] = {0};

    for(int i = 0; i < len; i++){
        arr_dig[arr[i] - '0']++;
    }

    for(int i = 0; i < 10; i++){
        if(*(arr_dig + i) != 0)
            printf("%d %d\n", i, arr_dig[i]);
    }
}
