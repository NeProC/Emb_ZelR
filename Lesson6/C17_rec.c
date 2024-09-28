/*
 * C2.c
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

int32_t sum(int32_t i)
{
    if(i == 0)
        return 0;
    int32_t tmp = 0;
    
    tmp = (i % 10) + sum(i / 10);
    
    return tmp;
}

int32_t composition(int32_t i)
{
    if(i == 0) 
        return 1;
    int32_t tmp = 1;
    
    tmp *= (i % 10) * composition(i / 10);
    
    return tmp;
}

void is_happy_number(int32_t i)
{
    if(sum(i) == composition(i)){
        printf("YES");
        return;
    }
    printf("NO");
}

int main(int argc, char **argv)
{
    int32_t x;
    scanf("%d", &x);
    is_happy_number(x);
    return 0;
}


