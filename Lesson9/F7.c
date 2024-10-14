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


#include <stdio.h>
#include <string.h>

 int compression(int a[], int b[], int N)
{
    int counter = 1, index = 0, i = 0;
    if(*a == 1){
        *b = 0;
        i = 1;
        counter = 2;
    }
    for (; i < N-1; i++)
    {
        if(*(a + i) == *(a + i + 1)){
            counter++;
        }
        else{
            *(b + index) = counter;
            index++;
            counter = 1;
        }
    }
    return index;
}


int main(int argc, char **argv)
{
    int N = 7, M = 30;
    int a[N], b[M];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    
    int len = compression(a, b, N);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", *(b + i));
    }
    printf("%d\n", len);
    return 0;
}

