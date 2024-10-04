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
#define ARR_SIZE 5

void scan_arr(int32_t arr[])
{  
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int32_t less_in_arr(int32_t arr[])
{
    int32_t less = 0;
    less = arr[0];
    for (int i = 1; i < ARR_SIZE; i++)
    {
        less = less < arr[i] ? less : arr[i];
    }
    return less;
}
int main()
{

    int32_t arr[ARR_SIZE] = {0};
    scan_arr(arr);
    printf("%d\n", less_in_arr(arr));
    return 0;
}

