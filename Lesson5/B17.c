/*
 * B17.c
 * 
 * Copyright 2024 roman <roman@DESKTOP-RM33TSB>
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

#define begin 10
#include <stdio.h>

int score_sum(int num)				//Ф-ци суммы цифр числа
{
	int sum = 0;
	while(num != 0){
		sum += num%10;
		num /= 10;
	}
	return sum;						//Возвращает сумму
}

int score_um(int num)				//Ф-ция умножения цифр числа
{
	int um = 1;
	while(num != 0){
		um *= num%10;
		num /= 10;
	}
	return um;						//Возвращает произведение
}

int main(int argc, char **argv)
{
	int num;
	scanf("%d", &num);
	
	for (int i = begin; i <= num; i++)
	{
		if(score_sum(i) == score_um(i)){	//Условие равенства суммы и произведения
			printf("%d ", i);
		}
	}
	
	return 0;
}

