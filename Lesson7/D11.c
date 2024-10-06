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


int32_t bin_one(uint32_t i)
{
    if(i == 0){
        return 0;
    }
        
    int32_t sum_one = (i % 2) + bin_one(i / 2);
    return sum_one;
}

int main(int argc, char **argv)
{
    uint32_t x;
    scanf("%d", &x);
    printf("%d\n", bin_one(x));;
    return 0;
}

