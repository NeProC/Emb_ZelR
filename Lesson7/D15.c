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

int32_t max_find(void)
{
    static int32_t flag = 0, max;         //Статический max чтобы не потерять значение присвоеное при flag == 0
    int32_t num;
    scanf("%d", &num);
    
    if(num == 0){
        return max;
    }
    
    if(flag == 0){                         //Флаг первого прохода, для приравнивания max к числу последовательности
        max = num;
        flag++;
    }
        
    max = max_find();
    max = max > num ? max : num;
    
    return max;
}

int main(int argc, char **argv)
{

    printf("%d\n", max_find());
    return 0;
}
