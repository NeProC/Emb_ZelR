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


uint64_t fuct(uint32_t n)										//Ф-ция вычисления факториала
{
	uint64_t fuct_n = 1;
	if(n == 0){													// 0! = 1
		return fuct_n;
	}
	
	for (int i = 1; i <= n; i++){
		fuct_n *= i;
	}
	
	return fuct_n;
}

uint64_t power(int32_t n, int32_t p)								//Ф-ция возведения в степень
{
	if(p == 0){
		 return 1;
	 }
	uint64_t tmp = n;
	
	for (int i = 1; i < p; i++)
	{
		tmp *= n;
	}
	
	return tmp;
}

void cosinus(float_t x)										//Ф-ция вычисления синусв через ряды
{
	float_t y = 0.0;
	uint32_t n = 0;
	while(n <= 10){
		y += pow(-1, n) * pow(x, (2*n)) / fuct(2*n);
		n++;
	}
	
	printf("%.3f\n", y);
}


int main(int argc, char **argv)
{
	float x;
	scanf("%f", &x);
	
	x = (M_PI / 180) * x;										//Перевод градусов в радианы
	
	cosinus(x);
	return 0;
}

