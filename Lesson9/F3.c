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
#define ARR_SIZE 10
#define SWAP_SIZE 4

void section_sort(int32_t len, int32_t *arr);						//Сортировка секциями
void scan_arr(int32_t *arr, int32_t len);							//Считывание массива
void print_arr (int32_t *arr, int32_t len);							//Вывод массива
void sort_even_odd(int n, int a[]);									//Сортировка и вывод четных и не четных чисел
void number_in_arr(int32_t *arr, int32_t len, int32_t num);			//
int32_t len_of_num (int32_t n);										//Длина числа



int main()
{
    int32_t num;
    scanf("%d", &num);
    int32_t len = len_of_num(num);
    int32_t arr[len];
    number_in_arr(arr, len, num);
    section_sort(len, arr);
    print_arr(arr, len);
    return 0;
}

void section_sort(int32_t len, int32_t *arr)
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

void number_in_arr(int32_t *arr, int32_t len, int32_t num)
{
    for(int32_t i = 0; i < len; i++){
        arr[i] = num % 10;
        num /= 10;
    }
    return;
}

int32_t len_of_num (int32_t n)
{
    int32_t len = 0;
    while(n != 0){
        len++;
        n /= 10;
    }
    return len;
}
