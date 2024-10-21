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
#define LINE 10
#define COLUMN 10

void scan_matrix(int matrix[LINE][COLUMN])
{
    //printf("yep");
    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    return;
}

void print_matrix(int matrix[LINE][COLUMN])
{
    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

int main_diagonal(int matrix[5][5])
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(i == j)
                sum += matrix[i][j];
        }
    }
    return sum;
}

int max_in_lines(int matrix[LINE][COLUMN])
{
    int sum = 0, max;
    int j = 0;
    for (int i = 0; i < LINE; i++)
    {
        max = matrix[i][j];
        for (j = 1; j < COLUMN; j++)
        {
            max = max > matrix[i][j] ? max : matrix[i][j];
        }
        sum += max;
        j = 0;
    }
    return sum;
}

int main()
{
    int matrix[LINE][COLUMN] = {0};/*{{10,9,98,65},
                          {8,-9,-4,6},
                          {15,6,78,-8},
                          {15,6,78,-8},
                          {15,6,78,-8}};;*/
    scan_matrix(matrix);
    printf("%d\n", max_in_lines(matrix));
    return 0;
}

