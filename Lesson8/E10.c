/*
 * E1.c
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
#define ARR_SIZE 12
#define SWAP_SIZE 4

void scan_arr(int32_t arr[], int32_t len_arr);						//Запись значений в массив
int32_t less_in_arr(int32_t arr[]);									//Меньшее значение в масиве
int32_t max_in_arr(int32_t arr[]);									//Максимальное значение в массиве
int32_t index_max(int32_t arr[]);									//Индекс максисального значения в массиве
int32_t index_less(int32_t arr[]);									//Индекс минимального значения в массиве
int32_t sum_in_arr(int32_t *arr, int32_t a, int32_t b);				//Сумма двух ячеек в массиве
void print_arr(int32_t arr[], int32_t len_arr);						//Распечатать массив
void swap_in_arr(int32_t *arr, int32_t i, int32_t j);				//Поменять местами две ячейки в массиве
void bubble_sort( int32_t *arr, int32_t len);						//Сортировка массива по возрастанию пузырьковым методом 
int32_t sum_arr_positiv(int32_t *arr, int32_t len);					//Сумма положительных ячеек массива
float_t arithmetic_mean(int32_t *arr, int32_t len);					//Средне арифметическое значение массива
void reverse_half(int32_t *arr, int32_t len);						//Реверс половин массива
void reverse_third(int32_t *arr, int32_t len);						//Реверс третей массива
void swap_right_arr(int32_t *arr, int32_t len);						//Сдвиг массива вправо
void swap_right_arr_n(int32_t *arr, int32_t len, int32_t n);		//Сдвиг массива вправо на N


int main()
{
    int32_t len_arr = ARR_SIZE;
    int32_t arr[len_arr];
    int32_t n = SWAP_SIZE;
    scan_arr(arr, len_arr);
    swap_right_arr_n(arr, len_arr, n);
    print_arr(arr, len_arr);
    return 0;
}

void scan_arr(int32_t arr[], int32_t len_arr)
{  
    for (int32_t i = 0; i < len_arr; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int32_t less_in_arr(int32_t arr[])
{
    int32_t less = arr[0];
    
    for (int32_t i = 1; i < ARR_SIZE; i++)
    {
        less = less < arr[i] ? less : arr[i];
    }
    
    return less;
}

int32_t max_in_arr(int32_t arr[])
{
    int32_t max = arr[0];
    
    for (int32_t i = 1; i < ARR_SIZE; i++)
    {
        max = max > arr[i] ? max : arr[i];
    }
    
    return max;
}

int32_t index_max(int32_t arr[])
{
    int32_t index = 1, max = arr[0];
    
    for (int32_t i = 1; i < ARR_SIZE; i++)
    {
        if(max < arr[i]){
            max = arr[i];
            index = i;
        }
    }
    
    return index;
}

int32_t index_less(int32_t arr[])
{
    int32_t index = 1, min = arr[0];
    
    for (int32_t i = 1; i < ARR_SIZE; i++)
    {
        if(min > arr[i]){
            min = arr[i];
            index = i;
        }
    }
    
    return index;
}

int32_t sum_in_arr(int32_t *arr, int32_t a, int32_t b)
{
    return *(arr + a) + *(arr + b);
}

void print_arr(int32_t arr[], int32_t len_arr)
{
    for (int i = 0; i < len_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap_in_arr(int32_t *arr, int32_t i, int32_t j)
{
    int32_t tmp = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = tmp;
}

void bubble_sort( int32_t *arr, int32_t len)
{
    int32_t swap_flag;
    for (int32_t i = len - 1; i >= 0; i--)
    {
        swap_flag = 1;
        for (int32_t j = 0; j < i; j++)
        {
            if( arr[j + 1] > arr[j]){
                swap_in_arr(arr, j + 1, j);
                swap_flag = 0;
            }
        }
        if(swap_flag){
            break;
        }
    }
} 

int32_t sum_arr_positiv(int32_t *arr, int32_t len)
{
    int32_t sum = 0;
    for (int i = 0; i < len; i++)
    {
        if( *(arr + i) > 0){
            sum += *(arr + i);
        }
    }
    
    return sum;
}

float_t arithmetic_mean(int32_t *arr, int32_t len)
{
    float_t mid = 0;
    for(int32_t i = 0; i < len; i++)
    {
        mid += arr[i];
    }
    
    return mid/len;
}

void reverse_half(int32_t *arr, int32_t len)
{
    for(int32_t i = 0; i < len / 4; i++)
    {
        swap_in_arr(arr, i, len / 2 - i - 1);
    }
    for(int32_t i = 0; i < len / 4; i++)
    {
        swap_in_arr(arr, i + len / 2, len - i - 1);
    }
}

void reverse_third(int32_t *arr, int32_t len)
{
    for(int32_t i = 0; i < len / 6; i++)
    {
        swap_in_arr(arr, i, len / 3 - i - 1);
    }
    for(int32_t i = 0; i < len / 6; i++)
    {
        swap_in_arr(arr, i + len / 3, len * 2 / 3 - i - 1);
    }
    for(int32_t i = 0; i < len / 6; i++)
    {
        swap_in_arr(arr, len * 2 / 3 + i, len - i - 1);
    }
}

void swap_right_arr(int32_t *arr, int32_t len)
{
    int32_t tmp = arr[len - 1];
    for(int32_t i = len - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    *arr = tmp;
}

void swap_right_arr_n(int32_t *arr, int32_t len, int32_t n)
{
    for(int32_t j = n; j > 0; j--)
    {
        int32_t tmp = arr[len - 1];
        for(int32_t i = len - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        *arr = tmp;
    }
}
