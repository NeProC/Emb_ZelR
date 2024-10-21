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

void white_or_black(char l, char h)
{
    int lon, high;
    
    high = h - '0';
    if(high > 8)
        return;
    
    switch(l){
    case 'A':lon = 1; break;
    case 'B':lon = 2; break;
    case 'C':lon = 3; break;
    case 'D':lon = 4; break;
    case 'E':lon = 5; break;
    case 'F':lon = 6; break;
    case 'G':lon = 7; break;
    case 'H':lon = 8; break;
    default: return;
    }
    
    if(high % 2 == 0 && lon % 2 == 0)
        printf("BLACK");
    else if(high % 2 != 0 && lon % 2 != 0)
        printf("BLACK");
    else 
        printf("WHITE");
        
    return;
}

int main()
{
    char l, h;
    scanf("%1c%1c", &l, &h);
    white_or_black(l, h);
    
    return 0;
}

