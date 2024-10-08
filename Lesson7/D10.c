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

uint32_t is_prime(uint32_t n, uint32_t del)
{
    if(del == 0){
        return 0;
    }
        
    uint32_t flag = 0;
    n % del == 0 ? flag++ : flag;
    flag += is_prime(n, del - 1);
    
    return flag;
}

int main(int argc, char **argv)
{
    int32_t a, del;
    scanf("%d", &a);
    del = a;
    is_prime(a, del) == 2 ? printf("YES") : printf("NO");
    return 0;
}

