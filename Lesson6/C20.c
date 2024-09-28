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

void equality(int32_t x, int32_t y)
{
    
    if(x == y && ((x + y) <= 1000)){                      //Условие что знаков меньше 1000 и откр = закр
        printf("YES");
    }
    else{
        printf("NO");
    }    
}

void right_symbol(void)
{
    int8_t c;
    int32_t right = 0, left = 0, r_right = 0;
    while( (c = getchar()) != '.'){
        if(c == '('){
            left++;
        }
        if(c == ')' && (left > right)){                    //Условие, что откр должно быть больше закр при считывании
            right++; 
        }
        if(c == ')'){                                      //Подсчет всех закр скобок
            r_right++;
        }    
        
    }
    if(right != r_right){                                  //Сравнение всех закр и правильно поставленных
        printf("NO");
        return;
    }
    equality(left, right);
}

int main(int argc, char **argv)
{
    right_symbol();
    return 0;
}

