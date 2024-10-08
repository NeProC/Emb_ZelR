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
#define ARR_SIZE 10
#define SWAP_SIZE 4

void scan_arr(int32_t arr[], int32_t len_arr);									//Запись значений в массив
int32_t less_in_arr(int32_t arr[]);												//Меньшее значение в масиве
int32_t max_in_arr(int32_t arr[]);												//Максимальное значение в массиве
int32_t index_max(int32_t arr[]);												//Индекс максисального значения в массиве
int32_t index_less(int32_t arr[]);												//Индекс минимального значения в массиве
int32_t sum_in_arr(int32_t *arr, int32_t a, int32_t b);							//Сумма двух ячеек в массиве
void print_arr(int32_t arr[], int32_t len_arr);									//Распечатать массив
void swap_in_arr(int32_t *arr, int32_t i, int32_t j);							//Поменять местами две ячейки в массиве
void bubble_sort( int32_t *arr, int32_t len);									//Сортировка массива по возрастанию пузырьковым методом 
int32_t sum_arr_positiv(int32_t *arr, int32_t len);								//Сумма положительных ячеек массива
float_t arithmetic_mean(int32_t *arr, int32_t len);								//Средне арифметическое значение массива
void reverse_half(int32_t *arr, int32_t len);									//Реверс половин массива
void reverse_third(int32_t *arr, int32_t len);									//Реверс третей массива
void swap_right_arr(int32_t *arr, int32_t len);									//Сдвиг массива вправо
void swap_right_arr_n(int32_t *arr, int32_t len, int32_t n);					//Сдвиг массива вправо на N
void bubble_sort_last_num( int32_t *arr, int32_t len);							//Сортировака по последним цифрам
void bubble_sort_half_left( int32_t *arr, int32_t len);							//Сортировка левой половина по возрастанию
void bubble_sort_half_right( int32_t *arr, int32_t len);						//Сортировка правой половины по убыванию
int32_t second_zero_quantity(int32_t *arr, int32_t  len_arr);					//Количество чисел с вторм нулем в массиве
void second_zero_quantity_new_arr(int32_t *arr, int32_t *new_arr, int32_t len);	//Перевод в новый массив чисел с вторым нулем
void repetitive_num_arr(int32_t *arr, int32_t *new_arr, int32_t len);			//Перенос повторяющихся чисел в новый массив
int32_t counting_repetitions(int32_t *arr, int32_t len);						//Подсчет повторяющихся чисел
int32_t counting_negative(int32_t *arr, int32_t len);							//Подсчет отрицательных чисел массива
void transfer_pos(int32_t *arr, int32_t *new_arr_pos, int32_t len);				//Перенос в новый масси положительных чисел
int32_t counting_positiv(int32_t *arr, int32_t len);							//Подсчет положительных чисел массива
void transfer_neg(int32_t *arr, int32_t *new_arr_neg, int32_t len);				//Перенос в новый масси отрицательных чисел
int32_t num_more_one(int32_t *arr, int32_t len);								//Поиск повторяющегося числа
void num_one_in_arr(int32_t *arr, int32_t len);									//Вывод чисел встречающихся один раз
void division_nums(int32_t x);													//Вывод делителей
int32_t num_of_N(int32_t n);													//Вывод кол-ва цифр в числе 
void print_arr_rev(int32_t arr[], int32_t len_arr);								//Реверсивный вывод массива
void writing_numbers(int32_t *arr, int32_t len, int32_t x);						//Запись цифр числа в массив
int32_t sum_of_arr(int32_t *arr, int32_t len);									//Сумма цифр в массиве
void write_more_number(int32_t *arr, int32_t *big_arr, int32_t len);			//Перевод из массива в новый массив в порядке убывания



int main()
{
//    int32_t len_arr = ARR_SIZE;
//    int32_t arr[len_arr];
    
//    scan_arr(arr, len_arr);
//    bubble_sort(arr, len_arr);
    
    int32_t num;
    scanf("%d", &num);
    int32_t len_arr = num_of_N(num);
    int32_t arr[len_arr];
    int32_t arr_big_num[len_arr];
    writing_numbers(arr, len_arr, num);
    write_more_number(arr, arr_big_num, len_arr);
    print_arr(arr_big_num, len_arr);
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
        printf("%d", arr[i]);
    }
//    printf("\n");
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
    for(int32_t i = len - 1; i >= 0; i--)
    {
        swap_flag = 1;
        for(int32_t j = 0; j < i; j++)
        {
            if(arr[j + 1] < arr[j]){
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

void bubble_sort_last_num( int32_t *arr, int32_t len)
{
    int32_t swap_flag;
    for (int32_t i = len - 1; i >= 0; i--)
    {
        swap_flag = 1;
        for (int32_t j = 0; j < i; j++)
        {
            if( arr[j + 1] % 10 < arr[j] % 10){
                swap_in_arr(arr, j + 1, j);
                swap_flag = 0;
            }
        }
        if(swap_flag){
            break;
        }
    }
} 

void bubble_sort_half_left( int32_t *arr, int32_t len)
{
    int32_t swap_flag;
    for(int32_t i = len / 2 - 1; i >= 0; i--)
    {
        swap_flag = 1;
        for(int32_t j = 0; j < i; j++)
        {
            if(arr[j + 1] < arr[j]){
                swap_in_arr(arr, j + 1, j);
                swap_flag = 0;
            }
        }
        if(swap_flag){
            break;
        }
    }
} 

void bubble_sort_half_right( int32_t *arr, int32_t len)
{
    int32_t swap_flag;
    for(int32_t i = len - 1; i >= len / 2; i--)
    {
        swap_flag = 1;
        for(int32_t j = len / 2; j < i; j++)
        {
            if(arr[j + 1] > arr[j]){
                swap_in_arr(arr, j + 1, j);
                swap_flag = 0;
            }
        }
        if(swap_flag){
            break;
        }
    }
} 

int32_t second_zero_quantity(int32_t *arr, int32_t  len_arr)
{
    int32_t counter = 0;
    for (int i = 0; i < len_arr; i++)
    {
        if((arr[i] % 100) / 10 == 0)
        counter++;
    }
    return counter;
}

void second_zero_quantity_new_arr(int32_t *arr, int32_t *new_arr, int32_t len)
{
    int32_t counter = 0;
    for(int32_t i = 0; i < len; i++)
    {
        if((arr[i] % 100) / 10 == 0){
            new_arr[counter] = arr[i];
            counter++;
        }
    }
}

void repetitive_num_arr(int32_t *arr, int32_t *new_arr, int32_t len)
{
    
    if(len == 0){
        return;
    }
    int32_t counter = 0;
    for(int32_t i = 0; i <= len -2; i++){
        if(arr[i] == arr[i + 1]){
            new_arr[counter] = arr[i];
            counter++;
            break;           
        }
    }    
    
    for(int32_t i = 0; i <= len - 2; i++)
    {
        if(arr[i] == arr[i + 1] && arr[i] != new_arr[counter - 1]){
//            printf("arr_i = %d arr_i+1 = %d new_arr[count] = %d\n", arr[i], arr[i + 1], arr[counter] );
            new_arr[counter] = arr[i];
            counter++;
        }
    }
}

int32_t counting_repetitions(int32_t *arr, int32_t len)
{
    int32_t counter = 0;
    if(arr[0] == arr[1]){
        counter = 1;
    }
    for(int32_t i = 1; i < len - 1; i++)
    {
        if(arr[i] == arr[i + 1] && arr[i] != arr[i - 1]){
            counter++;
        }
    }
    
    return counter;
}

int32_t counting_negative(int32_t *arr, int32_t len)
{
    int32_t counter = 0;
    for(int32_t i = 0; i < len; i++)
    {
        if(*(arr + i) < 0){
            counter++;
        }
    }
    return counter;
}

void transfer_pos(int32_t *arr, int32_t *new_arr_pos, int32_t len)
{
    int32_t index = 0;
    for(int32_t i = 0; i < len; i++)
    {
        if(arr[i] > 0){
            new_arr_pos[index] = arr[i];
            index++;
        }
    }
}

int32_t counting_positiv(int32_t *arr, int32_t len)
{
    int32_t counter = 0;
    for(int32_t i = 0; i < len; i++)
    {
        if(*(arr + i) > 0){
            counter++;
        }
    }
    return counter;
}

void transfer_neg(int32_t *arr, int32_t *new_arr_neg, int32_t len)
{
    int32_t index = 0;
    for(int32_t i = 0; i < len; i++)
    {
        if(arr[i] < 0){
            new_arr_neg[index] = arr[i];
            index++;
        }
    }
}

int32_t num_more_one(int32_t *arr, int32_t len)
{
    int32_t counter = 0;
    int32_t more_num[2] = {0};
    for(int32_t i = 0; i < len; i++)
    {
        for(int32_t j = 0; j < len; j++)
        {
            if(arr[i] == arr[j]){
                counter++;
            }
        }
        if(counter > more_num[0]){
            more_num[0] = counter;
            more_num[1] = arr[i];
        }
        counter = 0;
    }
    return more_num[1];
}

void num_one_in_arr(int32_t *arr, int32_t len)
{
    int32_t counter = 0;
    for(int32_t i = 0; i < len; i++)
    {
        for(int32_t j = 0; j < len; j++)
        {
            if(arr[i] == arr[j]){
                counter++;
            }
        }
        if(counter == 1){
            printf("%d ", arr[i]);
        }
        counter = 0;
    }
    return;
}

void division_nums(int32_t x)
{
    int32_t start = 2, end = 10;
    int32_t counter = 0;
    
    do
    {
        for (int32_t i = 2; i <= x; i++)
        {
            if(i % start == 0)
                counter++;
        }
        printf("%d %d\n", start, counter);
        start++;
        counter = 0;
    } while (start != end);
    
}

int32_t num_of_N(int32_t n)
{
    int32_t counter = 0;
    while (n != 0)
    {
        counter++;
        n /= 10;
    }
    return counter;;
}

void print_arr_rev(int32_t arr[], int32_t len_arr)
{
    for (int i = len_arr - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
//    printf("\n");
}

void writing_numbers(int32_t *arr, int32_t len, int32_t x)
{
    for (int i = 0; i < len; i++)
    {
        arr[i] = x % 10;
        x /= 10;
    }
    return;
}

int32_t sum_of_arr(int32_t *arr, int32_t len)
{
    int32_t sum = 0;
    for(int32_t i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    return sum;
}

void write_more_number(int32_t *arr, int32_t *big_arr, int32_t len)
{
    int32_t max = 0;
    for(int32_t j = 0; j < len; j++)
    {
        for(int32_t i = 0; i < len; i++)
        {
            if(arr[i] > max)
            {
                max = arr[i];
            }
        }
        for(int32_t k = 0; k < len; k++)
        {
            if(max == arr[k])
            {
                arr[k] = 0;
                break;
            }  
        }
    big_arr[j] = max;
    max = 0;
    }
}
