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

void scan_arr(int32_t arr[]);
int32_t less_in_arr(int32_t arr[]);
int32_t max_in_arr(int32_t arr[]);
int32_t index_max(int32_t arr[]);
int32_t index_less(int32_t arr[]);
int32_t sum(int32_t a, int32_t b);
void print_arr(int32_t arr[]);

int main()
{
    int32_t max1, max2, index1;
    int32_t arr[ARR_SIZE] = {0};
    scan_arr(arr);
    
    max1 = max_in_arr(arr);
    index1 = index_max(arr);
//    print_arr(arr);
    arr[index1-1] = less_in_arr(arr);
//    print_arr(arr);
    max2 = max_in_arr(arr);
    printf("%d", arr[index1]);
    return 0;
}

void scan_arr(int32_t arr[])
{  
    for (int32_t i = 0; i < ARR_SIZE; i++)
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
            index = i+1;
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
            index = i+1;
        }
    }
    return index;
}
int32_t sum(int32_t a, int32_t b)
{
    return a + b;
}

void print_arr(int32_t arr[])
{
    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
