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

int32_t word_to_digit(int8_t i)								//перевод символа числа в число
{
	int32_t tmp;
    switch( i )
    {
        case '0': tmp = 0; break; 
        case '1': tmp = 1; break;
        case '2': tmp = 2; break;
        case '3': tmp = 3; break;
        case '4': tmp = 4; break;
        case '5': tmp = 5; break;
        case '6': tmp = 6; break; 
        case '7': tmp = 7; break;
        case '8': tmp = 8; break;
        case '9': tmp = 9; break;
        default : break;
    }
    return tmp;
}

int32_t digit_to_num(void){
    int32_t sum_num = 0;
    int8_t  c;
    
    while( (c = getchar()) != '.'){										//Пока не появился символ '.'
        if(c >= '0' && c <= '9'){
            sum_num += word_to_digit(c);					//Суммируем в переменную sum_num числа переведенные
//            printf("%c\t", c);							//из символов
//            printf("%d\n", count_num);
        }
    }
    return sum_num;
}

int main(int argc, char **argv)
{
    printf("%d\n", digit_to_num ());
    return 0;
}

