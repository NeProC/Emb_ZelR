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

#define ARR_SIZE 1000
#include <stdio.h>
#include <string.h>

int num_of_sequence(int arr[], int len, int n)
{
    int flag = 0;
    for (int i = n; i < n + len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if(i == arr[j])
                flag++;
        }
        if(flag == 0)
            return i;
        flag--;
    }
    return 0;
}

int scan_sequence(int arr[])
{
    int index = 0;
    do
    {
        scanf("%d", &arr[index++]);
    } while (arr[index - 1] != 0);
    return index;

}

int min_in_arr(int arr[], int len)
{
    int min = arr[0];
    for (int i = 1; i < len - 1; i++)
    {
        min = min < arr[i] ? min : arr[i];
    }
    return min;
}

int main(int argc, char **argv)
{
    int arr[ARR_SIZE];
    int len = scan_sequence(arr);
    int n = min_in_arr(arr, len);
    int z = num_of_sequence(arr, len, n);
    printf("%d\n", z);
    return 0;
}

