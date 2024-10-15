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

void scan_char (char ch[])
{
    char c;
    int i = 0;
    while( (c = getchar()) != '.'){
        scanf("%c", &ch[i++]);
        printf("%c\n", ch[i]);
    }
    ch[i] = '\0';
    return;
}

int main()
{
    char c[1000] = {0};
    scan_char(c);
    int len = strlen(c);
    printf("%d\n", len);
    return 0;
}

