/*
 * B12.c
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


#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int num, min, max, scoreNum = 0, tmp;
	scanf("%d", &num);
	tmp =  num;
	
	while(tmp != 0){													//Количество цифр в числе, scoreNum
		scoreNum++;
		tmp /= 10;
	}
	max = num%10;														//  Присваиваем min и max значение последней цифры для случая
	min = num%10;														//когда число 1 цифра
    	
	tmp = num/10;														//В переменную tmp кладем число num без последней цифры
    for (int i = scoreNum-1; i > 0; i--)								//  Перебираем оставшиеся цифры числа. scoreNum меньше на 1
	{																	//т к 1 цифр1 отброили
		max = (tmp % 10) > max ? tmp % 10 : max;
		tmp /= 10;														//Убираем у числа младшую цифру в цикле
	}
	
	tmp = num/10;
	for (int i = scoreNum-1; i > 0; i--)
	{
		min = (tmp % 10) < min ? tmp % 10 : min;
		tmp /= 10;
	}
	
	printf("%d %d\n", min, max);
	
	return 0;
}

