/*
 * F5.c
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

#define ARR_SIZE 10
#include <stdio.h>
#include <string.h>

void swap_negmax_last(int size, int a[])
{
    int max_neg = 0, index_max_neg;
    for (int i = 0; i < size; i++){
        if(a[i] < 0){
            max_neg = a[i];
            index_max_neg = i;
            break;
        }
    }
    
    if(max_neg == 0)
        return;
    
    for (int i = 0; i < size; i++){
        if(a[i] < 0 && a[i] > max_neg){
            max_neg = a[i];
            index_max_neg = i;
        }
    }
    
    a[index_max_neg] = a[size - 1];
    a[size - 1] = max_neg;
    return;
}

int main()
{
    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    swap_negmax_last(ARR_SIZE, arr);
    
    for (int i = 0; i < ARR_SIZE; i++)
{
    printf("%d ", arr[i]);
}
    return 0;
}

